#include "Timestamp.h"
#include "ComplexNumber.h"
#include "QuadraticEquation.h"
#include <iostream>
#include <cmath>

int main() {
	Timestamp t = Timestamp(3661);
	t.Print();
	Timestamp t2 = Timestamp(3661);
	t.Add(t2);
	t.Print();
	std::cout<<t.ToSeconds();
	std::cout << std::endl;
    //ComplexNumber a(3.0, 4.0);
    //ComplexNumber b(1.0, 2.0);
    //ComplexNumber sum = a.Sum(b);
    //sum.Print();
    //ComplexNumber product = a.Multiply(b);
    //product.Print();

	ComplexNumber a(3, 2);
	ComplexNumber b(1, 7);

	std::cout << "Complex number a: "; a.Print();
	std::cout << "Complex number b: "; b.Print();
	ComplexNumber sum = a.Sum(b);
	std::cout << "Sum of a and b: "; sum.Print();
	ComplexNumber product = a.Multiply(b);
	std::cout << "Product of a and b: "; product.Print();
	QuadraticEquation equation(ComplexNumber(1, 0), ComplexNumber(-3, 0), ComplexNumber(2, 0));
	std::cout << "Solving the quadratic equation: \n";
	equation.Solve();

	return  0;
}