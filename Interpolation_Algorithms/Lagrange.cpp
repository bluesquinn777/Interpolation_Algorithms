#include "Lagrange.h"
#include <cassert>

using namespace std;

// Constructor and Destructor
LagrangeInterpolation::LagrangeInterpolation(double x_value) {
	// X and Y value for lahrange interpolation
	x_ = x_value;
}

LagrangeInterpolation::~LagrangeInterpolation() {}

// Accessors
double LagrangeInterpolation::getValueX() const {
	return x_;
}

// Mutators
double LagrangeInterpolation::lineExtrapolationSingleY(double indep_var_x, vector<double> x_vals, vector<double> y_vals) {
	assert(x_vals.size() == y_vals.size());
	int x_size = x_vals.size();
	vector<double> x_vals_copy, term_result;
	double final_result = 0;

	for (int i = 0; i < x_size; i++) {
		double term_up = 1;
		double term_down = 1;
		x_vals_copy = x_vals;
		x_vals_copy.erase(x_vals_copy.begin() + i);
		for (int j = 0; j < x_size - 1; j++) {
			term_up *= (indep_var_x - x_vals_copy[j]);
			term_down *= (x_vals[i] - x_vals_copy[j]);
		}
		term_result.push_back(term_up/term_down);
	}

	for (int k = 0; k < x_size; k++) {
		final_result += y_vals[k] * term_result[k];
	}
	return final_result;
}