#ifndef graph_hpp
#define graph_hpp


// for wxImage
#include <wx/image.h>
// for std::vector
#include <vector>
#include <wx/rawbmp.h>
// for std::max_value
#include <algorithm>

template <typename T>
wxImage draw_graph(const std::vector<T>& values, const wxSize& size = wxSize(40, 40), T min_value = 0) {

	wxImage result;
	result.Create(size);
	result.Clear(255);
	auto data_ptr = result.GetData();

	auto max_value = *(std::max_element(values.begin(), values.end()));

	min_value = *(std::min_element(values.begin(), values.end()));

	for (int iter = 0; iter < size.GetWidth(); iter++) {
		auto current_value = values.at(float(iter)/float(size.GetWidth()) * float(values.size()));

		auto ratio = float(current_value - min_value)/float(max_value - min_value);

		if (max_value == 0)
			ratio = 1.0;

		auto number_of_pixels = int(ratio * size.GetHeight());

		for (int iter2 = 0; iter2 < number_of_pixels; iter2++) {
			int current_pixel = iter * 3 + (size.GetHeight() - iter2 - 1) * size.GetWidth() * 3;
			data_ptr[current_pixel + 0] = 255;
			data_ptr[current_pixel + 1] = 100;
			data_ptr[current_pixel + 2] = 255;
		}
	}

	return result;
}


#endif
