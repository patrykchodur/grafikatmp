#include "sup_classes.hpp"
#include "rotate.hpp"
#include "minimalize.hpp"
#include "graph.hpp"

#include <vector>
#include <initializer_list>

// for testing

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
	//auto fact = minimalize(holder, AngleDeg(90));
	//auto result = rotate(rotate(holder, AngleDeg(90), fact), -AngleDeg(90), fact);
	//result.image.SaveFile("test.png", wxBITMAP_TYPE_PNG);


	std::vector<float> numbers;
	numbers.resize(400);
	for (int iter = 0; iter < numbers.size(); iter++)
		numbers.at(iter) = std::sin(iter / 40.0) + 1.;
	draw_graph(numbers, wxSize(200, 200)).SaveFile("graph.png", wxBITMAP_TYPE_PNG);


	

	return 0;
}
