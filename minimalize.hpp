#ifndef minimalize_hpp
#define minimalize_hpp


/*
	
	minimalize.hpp synopsis


Factors minimalize(const ImageHolder&, const Angle&, int numb_of_iterations = 40, const Factors& starting_point = Factors(0, 0, 0, 0), const Factors& step_factors = Factors(0.2, 0.2, 0.2, 0.2));


*/


#include "rotate.hpp"


Factors minimalize(const ImageHolder&, const Angle&, int numb_of_iterations = 40, const Factors& starting_point = Factors(0, 0, 0, 0), const Factors& step_factors = Factors(0.2, 0.2, 0.2, 0.2));


#endif // minimalize_hpp
