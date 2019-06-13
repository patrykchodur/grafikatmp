#include "sup_classes.hpp"
#include "rotate.hpp"
#include "minimalize.hpp"

int main() {


	wxInitAllImageHandlers();
	wxImage img;
	img.LoadFile("1.png", wxBITMAP_TYPE_PNG);
	auto holder = ImageHolder(img);
	/*
	auto result = rotate(rotate(holder, AngleDeg(5), Factors(1, 0, 0, 0)), AngleDeg(5), Factors(1, 0, 0, 0));
	result = rotate(rotate(result, AngleDeg(5), Factors(1, 0, 0, 0)), AngleDeg(5), Factors(1, 0, 0, 0));
	result = rotate(result, AngleDeg(-20), Factors(1, 0, 0, 0));
	*/
	auto fact = minimalize(holder, AngleDeg(90));
	auto result = rotate(rotate(holder, AngleDeg(90), fact), -AngleDeg(90), fact);
	result.image.SaveFile("test.png", wxBITMAP_TYPE_PNG);
	return 0;
}
