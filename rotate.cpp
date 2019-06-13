#include "rotate.hpp"
#include "sup_classes.hpp"
#include <wx/rawbmp.h>
#include <vector>

template <typename T>
static T pythag(T a, T b) {
	return std::sqrt(a*a + b*b);
}

template <typename T>
static T sq(T a) {
	return a*a;
}

// calculate rectangle taken by rotated image
static wxSize calculateSize(const wxSize& size, const Angle& angle) {
	// calculating a diagonal of the box defined by size
	float diagonalLength = pythag(size.GetHeight(), size.GetWidth());
	Angle diagonalAngle = std::atan2(size.GetHeight(), size.GetWidth());

	// calculating a rectangle needed to fit rotated size
	float width = std::max(std::abs(std::cos(angle - diagonalAngle) * diagonalLength), std::abs(std::cos(angle + diagonalAngle) * diagonalLength));
	float height = std::max(std::abs(std::sin(angle - diagonalAngle) * diagonalLength), std::abs(std::sin(angle + diagonalAngle) * diagonalLength));

	return wxSize(int(width) + 1, int(height) + 1);
}



ImageHolder rotate(const ImageHolder& img, const Angle& angle, const Factors& factors) {
	// saving some properties
	auto newAngle = angle + img.angle;
	auto orgWidth = img.orgSize.GetWidth();
	auto orgHeight = img.orgSize.GetHeight();
	auto newSize = calculateSize(img.orgSize, angle + img.angle);
	auto prevSize = calculateSize(img.orgSize, img.angle);


	// calculating Origin of new, current and original image
	auto newOrigin = FloatPoint((newSize.GetWidth() - 1)/2., (newSize.GetHeight() - 1)/2.);
	auto prevOrigin = FloatPoint((prevSize.GetWidth() - 1)/2., (prevSize.GetHeight() - 1)/2.);
	auto orgOrigin = FloatPoint((orgWidth - 1)/2., (orgHeight - 1)/2.);

	// creating new Image
	auto newImg = wxImage(newSize.GetWidth(), newSize.GetHeight());

	// checking whether image has alpha channel
	auto hasAlpha = img.image.HasAlpha();

	for (auto iter = 0; iter < newSize.GetWidth() * newSize.GetHeight() ; iter++) {

		// calculating properties dependent on pixel position
		auto currentPoint = wxPoint(iter % newSize.GetWidth(), iter / newSize.GetWidth());
		auto currentDistanceFromOrigin = pythag(float(currentPoint.x - newOrigin.x), float(currentPoint.y - newOrigin.y));
		auto alfa = Angle(std::atan2(newOrigin.y - currentPoint.y, newOrigin.x - currentPoint.x));
		alfa -= angle;
		auto prevPoint = FloatPoint(prevOrigin.x - std::cos(alfa) * currentDistanceFromOrigin, prevOrigin.y - std::sin(alfa) * currentDistanceFromOrigin);
		
		// vectors for columns and points
		auto colours = std::vector<std::pair<float, wxColour>>();
		auto points = std::vector<wxPoint>();

		points.push_back(wxPoint(int(prevPoint.x), int(prevPoint.y)));
		points.push_back(wxPoint(int(prevPoint.x), int(prevPoint.y) + 1));
		points.push_back(wxPoint(int(prevPoint.x) + 1, int(prevPoint.y) + 1));
		points.push_back(wxPoint(int(prevPoint.x) + 1, int(prevPoint.y)));

		// removing points which are not in the previous image
		points.erase(std::remove_if(points.begin(), points.end(), [&prevSize](const wxPoint& point) {
					return point.x < 0 || point.y < 0 || point.x >= prevSize.GetWidth() || point.y >= prevSize.GetHeight(); }), points.end());

		// setting black color for pixels outside of previous image
		if (points.size() == 0) {
			newImg.SetRGB(currentPoint.x, currentPoint.y, 0, 0, 0);
			if (hasAlpha)
				newImg.SetAlpha(currentPoint.x, currentPoint.y, 255);
			continue;
		}

		// add to colours vector propper points distance and colour
		for (const auto& tmpiter : points) {
			colours.emplace_back(pythag<float>(prevPoint.x - tmpiter.x, prevPoint.y - tmpiter.y), wxColour(img.image.GetRed(tmpiter.x, tmpiter.y), img.image.GetGreen(tmpiter.x, tmpiter.y), img.image.GetBlue(tmpiter.x, tmpiter.y)));
		}

		// sort colours vector starting from the closests
		std::sort(colours.begin(), colours.end(), [](std::pair<float, wxColour>& obj1, std::pair<float, wxColour>& obj2) {return obj1.first < obj2.first;});


		float red = 0, green = 0, blue = 0, alpha = 0;

		// in case of distance == 0 FIXME: replace factors[0] with 1
		if (std::isnan(colours[0].first/colours[0].first)) {
			red = colours[0].second.Red() * factors[0];
			green = colours[0].second.Green() * factors[0];
			blue = colours[0].second.Blue() * factors[0];
		}
		else {
			for (int tmpiter = 0; tmpiter < colours.size(); tmpiter++) {
				red += (colours[0].first/colours[tmpiter].first) * factors[tmpiter] * colours[tmpiter].second.Red(); // * (4./colours.size());
				green += (colours[0].first/colours[tmpiter].first) * factors[tmpiter] * colours[tmpiter].second.Green(); // * (4./colours.size());
				blue += (colours[0].first/colours[tmpiter].first) * factors[tmpiter] * colours[tmpiter].second.Blue(); // * (4./colours.size());
				if (hasAlpha)
					alpha += (colours[0].first/colours[tmpiter].first * factors[tmpiter]) * colours[tmpiter].second.Alpha() * (4./colours.size());
			}
		}

		// set color for current pixel
		newImg.SetRGB(currentPoint.x, currentPoint.y, red, green, blue);
		if (hasAlpha)
			newImg.SetAlpha(currentPoint.x, currentPoint.y, alpha);
	}

	return ImageHolder(newImg, newAngle, img.orgSize);
}


float error(const ImageHolder& img, const Angle& angle, const Factors& factors) {
	// image rotated twice
	auto after = rotate(rotate(img, angle, factors), -angle, factors);
	float result = 0;

	// size of the image
	auto size = calculateSize(img.orgSize, img.angle);

	// calculate mean squared error
	for (auto iter = 0; iter < size.GetWidth() * size.GetHeight(); iter++) {
		auto point = wxPoint(iter % size.GetWidth(), iter / size.GetWidth());
		result += sq(img.image.GetRed(point.x, point.y) - after.image.GetRed(point.x, point.y));
		result += sq(img.image.GetGreen(point.x, point.y) - after.image.GetGreen(point.x, point.y));
		result += sq(img.image.GetBlue(point.x, point.y) - after.image.GetBlue(point.x, point.y));
	}

	return result;
}

/*

float compare(const ImageHolder& img1, const ImageHolder& img2) {
	auto size1 = calculateSize(img1.orgSize, img1.angle);
	auto size2 = calculateSize(img2.orgSize, img2.angle);

	if size1 != size2
		throw 

*/

