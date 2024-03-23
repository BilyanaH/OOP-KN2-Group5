#ifndef COMPLEXNUMBER_HPP
#define COMPLEXNUMBER_HPP
struct ComplexNumber {
	double real;
	double img;
	ComplexNumber Sum(ComplexNumber a);
	void Print();
};
#endif