#include "quadraticEquation.h"
#include <iostream>

QuadraticEquation::QuadraticEquation(ComplexNumber a, ComplexNumber b, ComplexNumber c) : a(a), b(b), c(c) {}
void QuadraticEquation::Solve() const
{
	ComplexNumber discriminant = b.Multiply(b).Sum(a.Multiply(c).Multiply(ComplexNumber(4,0).Multiply(ComplexNumber(-1, 0))));
	if (discriminant.getReal() >= 0) {
		ComplexNumber root1 = b.Multiply(ComplexNumber(-1, 0)).Sum(discriminant.Sqrt()).Divide(a.Multiply(ComplexNumber(2, 0)));
		ComplexNumber root2 = b.Multiply(ComplexNumber(-1, 0)).Sum(discriminant.Sqrt().Multiply(ComplexNumber(-1, 0))).Divide(a.Multiply(ComplexNumber(2, 0)));
		std::cout << "Roots are real \n";
		std::cout << "Root 1: "; root1.Print();
		std::cout << "Root 2: "; root2.Print();
	}
	else {
		std::cout << "Roots are complex \n";
		ComplexNumber root1 = b.Multiply(ComplexNumber(-1, 0)).Sum(discriminant.Sqrt()).Divide(a.Multiply(ComplexNumber(2, 0)));
		ComplexNumber root2 = b.Multiply(ComplexNumber(-1, 0)).Sum(discriminant.Sqrt().Multiply(ComplexNumber(-1, 0))).Divide(a.Multiply(ComplexNumber(2, 0)));
		std::cout << "Root 1: "; root1.Print();
		std::cout << "Root 2: "; root2.Print();
	}
};
