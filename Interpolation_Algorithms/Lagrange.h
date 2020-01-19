#pragma once
#include <vector>

using namespace std;

class LagrangeInterpolation {
	// A class to realize lagrange interpolation

public:
	LagrangeInterpolation(double x_value);
	~LagrangeInterpolation();

	// Accessors
	double getValueX() const;

	// Mutators
	double lineExtrapolationSingleY(double indep_var_x, vector<double> x_vals, vector<double> y_vals);

private:
	double x_;				// Input x value
};