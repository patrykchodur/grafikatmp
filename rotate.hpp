#ifndef rotate_hpp
#define rotate_hpp


/*
	rotate.hpp synopsis


ImageHolder rotate(const ImageHolder& map, const Angle& angle, const Factors& factors);

float error(const ImageHolder& img, const Angle& angle, const Factors& factor);


*/


#include "sup_classes.hpp"

#include <wx/image.h>


ImageHolder rotate(const ImageHolder& map, const Angle& angle, const Factors& factors);

float error(const ImageHolder& img, const Angle& angle, const Factors& factor);

//float compare(const ImageHolder& img1, const ImageHolder& img2);




#endif // rotate_hpp
