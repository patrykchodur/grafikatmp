#ifndef sup_classes_hpp
#define sup_classes_hpp


/*

	sup_classes.hpp synopsis


struct Angle {
	float angle;

	Angle();
	Angle(float);
	Angle(const Angle&);

	Angle& operator=(const& Angle&);
	Angle& operator+=(const Angle&);
	Angle& operator-=(const Angle&);
	Angle operator+(const Angle&);
	Angle operator-(const Angle&);

	Angle operator-();

	operator float();

	friend std::ostream& operator<<(std::ostream&, const Angle&);
}

struct AngleDeg {
	float angle;

	AngleDeg();
	AngleDeg(float);
	explicit AngleDeg(const Angle&);

	AngleDeg operator-();
}

struct ImageHolder {
	wxImage img;
	Angle angle;
	wxSize orgSize;

	ImageHolder();
	ImageHolder(const wxImage&);
	ImageHolder(const wxImage&, const Angle&, const wxSize&);
	ImageHolder(const ImageHolder&);

	ImageHolder& operator=(const ImageHolder& other);
}
	
struct Factors {
	float c[4];

	Factors();
	Factors(float c1, float c2, float c3, float c4);
	Factors(const Factors&);
	
	Factors& operator=(const Factors&);

	bool operator==(const Factors&);
	bool operator!=(const Factors&);

	float& operator[](int);
	const float& operator[](int) const;
}


*/


// for wxImage class
#include <wx/image.h>
// for std::floor class
#include <cmath>
// for std::ostream class
#include <ostream>

template <typename T>
static T mod(T first, T second) {
	return first - second * std::floor(first / second);
}


struct Angle {
	float angle;

	Angle (float angle = 0) : angle(mod<float>(angle, 2*M_PI)) { }
	Angle (const Angle& other) = default;

	Angle& operator=(const Angle& other) {
		angle = other.angle;
		return *this;
	}

	Angle operator+(const Angle& other) const {
		return Angle(mod<float>(angle + other.angle, 2*M_PI));
	}
	Angle operator-(const Angle& other) const {
		return (*this)+Angle(-other.angle);
	}
	Angle& operator+=(const Angle& other) {
		angle = mod<float>(angle + other.angle, 2*M_PI);
		return *this;
	}
	Angle& operator-=(const Angle& other) {
		return (*this)+=Angle(-other.angle);
	}
	Angle operator-() const {
		return Angle(-angle);
	}
	operator float() const {
		return angle;
	}

	bool operator==(const Angle& other) const {
		return angle == other.angle;
	}
	bool operator!=(const Angle& other) const {
		return !((*this)==other);
	}

	friend std::ostream& operator<<(std::ostream& stream, const Angle& obj) {
		stream << "Angle(" << obj.angle << ')';
		return stream;
	}
};

struct AngleDeg {
	float angle;

	AngleDeg (float angle = 0) : angle(angle) { }
	explicit AngleDeg (const Angle& other) : angle(other.angle / M_PI * 180) { }

	operator Angle() {
		return Angle(angle / 180 * M_PI);
	}

	AngleDeg operator-() {
		return AngleDeg(-angle);
	}
};
	

struct FloatPoint {
	float x, y;

	explicit FloatPoint(float x = 0, float y = 0): x(x), y(y) { }
	FloatPoint(const wxPoint& other): x(other.x), y(other.y) { }

	bool operator==(const FloatPoint& other) const {
		if (x == other.x && y == other.y)
			return true;
		return false;
	}
	bool operator!=(const FloatPoint& other) const {
		return !((*this)==other);
	}
};
struct ImageHolder {
	wxImage image;
	Angle angle;
	wxSize orgSize;

	ImageHolder() = default;
	ImageHolder(const wxImage& img) : image(img), orgSize(img.GetSize()) { }
	ImageHolder(const wxImage& img, const Angle& ang, const wxSize& sz) : image(img), angle(ang), orgSize(sz) { }
	ImageHolder(const ImageHolder&) = default;

	ImageHolder& operator=(const ImageHolder& other) {
		image = other.image;
		angle = other.angle;
		orgSize = other.orgSize;
		return *this;
	}

	ImageHolder& operator=(const wxImage& img) {
		image = img;
		orgSize = img.GetSize();
		angle = 0;
		return *this;
	}
};

struct Factors {
	float c[4];

	Factors(float c1 = 0, float c2 = 0, float c3 = 0, float c4 = 0) {
		c[0] = c1; 
		c[1] = c2; 
		c[2] = c3; 
		c[3] = c4; 
	}

	bool operator!=(const Factors& other) const {
		if (c[0] != other.c[0])
			return true;
		if (c[1] != other.c[1])
			return true;
		if (c[2] != other.c[2])
			return true;
		if (c[3] != other.c[3])
			return true;
		return false;
	}
	bool operator==(const Factors& other) const {
		return !(*this!=other);
	}
	float& operator[](int iter) {
		return c[iter];
	}
	const float& operator[](int iter) const {
		return c[iter];
	}
	friend std::ostream& operator<<(std::ostream& stream , const Factors& obj) {
		stream << "Factors(" << obj[0] << ", " << obj[1] << ", " << obj[2] << ", " << obj[3] << ')';
		return stream;
	}
};

/*
class size_error : public std::runtime_error {
	size_error(const std::string& desc) : std::runtime_error(desc) { }
}
*/

#endif // sup_classes_hpp
