#include "minimalize.hpp"
#include <gsl/gsl_multimin.h>
#include <utility>

#ifdef DISPLAY_MINIMIZER_INFO
	#include <iostream>
#endif // DISPLAY_MINIMIZER_INFO


//wrapper for error function
static double error_f(const gsl_vector* x, void* params) {
	const auto& parameter_pair = *(static_cast<std::pair<const ImageHolder&, const Angle&>*>(params));

	auto factrs = Factors(gsl_vector_get(x, 0), gsl_vector_get(x, 1), gsl_vector_get(x, 2), gsl_vector_get(x, 3));

	return error(parameter_pair.first, parameter_pair.second, factrs);
} 

	


Factors minimalize(const ImageHolder& holder, const Angle& angle, int numb_of_iterations, const Factors& starting_point, const Factors& step_fact) {
	const gsl_multimin_fminimizer_type* type = gsl_multimin_fminimizer_nmsimplex2;
	gsl_multimin_fminimizer* minimizer_instance = nullptr;
	
	//starting point
	auto x = gsl_vector_alloc(4);
	gsl_vector_set (x, 0, starting_point[0]);
	gsl_vector_set (x, 1, starting_point[1]);
	gsl_vector_set (x, 2, starting_point[2]);
	gsl_vector_set (x, 3, starting_point[3]);


	//step value
	auto step = gsl_vector_alloc(4);
	gsl_vector_set (step, 0, step_fact[0]);
	gsl_vector_set (step, 1, step_fact[1]);
	gsl_vector_set (step, 2, step_fact[2]);
	gsl_vector_set (step, 3, step_fact[3]);


	//preparing parameters
	auto parameters = std::pair<const ImageHolder&, const Angle&>(holder, angle);
	//minimalization function
	gsl_multimin_function function;
	function.n = 4;
	function.f = error_f;
	function.params = static_cast<void*>(&parameters);


	//minimizer_instance
	minimizer_instance = gsl_multimin_fminimizer_alloc (type, 4);
	gsl_multimin_fminimizer_set(minimizer_instance, &function, x, step);

	//while loop
	int iter = 0;
	int status;
	double size;
	do {
#ifdef DISPLAY_MINIMIZER_INFO
		std::cout << "Iteration of minimalize function: " << iter + 1 << std::endl;
		std::cout << Factors(gsl_vector_get(minimizer_instance->x, 0), gsl_vector_get(minimizer_instance->x, 1), gsl_vector_get(minimizer_instance->x, 2), gsl_vector_get(minimizer_instance->x, 3)) << std::endl;
#endif // DISPLAY_MINIMIZER_INFO

		iter++;
		status = gsl_multimin_fminimizer_iterate(minimizer_instance);

		//if (status)
			//break;

		size = gsl_multimin_fminimizer_size(minimizer_instance);

		//set limit
		status = gsl_multimin_test_size(size, 0.1);
		//if (status == GSL_SUCCESS)
			//break;

	} while (/*status == GSL_CONTINUE && */iter < numb_of_iterations);
	
	auto result = Factors(gsl_vector_get(minimizer_instance->x, 0), gsl_vector_get(minimizer_instance->x, 1), gsl_vector_get(minimizer_instance->x, 2), gsl_vector_get(minimizer_instance->x, 3));


	gsl_vector_free(x);
	gsl_vector_free(step);
	gsl_multimin_fminimizer_free(minimizer_instance);


	return result;
}
	
