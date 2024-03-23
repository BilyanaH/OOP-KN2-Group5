#include "quadraticEquation.hpp"
#include <iostream>
#include <cmath>


bool QuadraticEquation::Solve(double& x1, double& x2){
	double D = b * b - 4 * a * c;
	if (D < 0) {
		return false;
	}
	if (D == 0) {
		x1 =- b + sqrt(D) / (2 * a);
	}
	else
	{
		x1 = ( - b + sqrt(D) ) / (2 * a);
		x2 = ( - b - sqrt(D)) / (2 * a);
	}
	return true;
}
