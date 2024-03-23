#include "complexNumber.h"
#include <iostream>

ComplexNumber::ComplexNumber(double real=0.0, double imag=0.0) : real(real), imag(imag) {}
double ComplexNumber::getReal() const {
	return real;
}
ComplexNumber ComplexNumber::Sum(ComplexNumber a) const{
	a.real += real;
	a.imag += imag;
	return a;
}
ComplexNumber ComplexNumber::Multiply(ComplexNumber a) const
{
	int areal = a.real;
	a.real = a.real * real - a.imag * imag;
	a.imag = areal * imag + a.imag * real;
	return a;
}
ComplexNumber ComplexNumber::Sqrt() const {
	double r = sqrt(real * real + imag * imag);
	double theta = atan2(imag, real);
	return ComplexNumber(sqrt(r) * cos(theta / 2), sqrt(r) * sin(theta / 2));
}

ComplexNumber ComplexNumber::Divide(const ComplexNumber& a) const {
	double denominator = a.real * a.real + a.imag * a.imag;
	return ComplexNumber((real * a.real + imag * a.imag) / denominator, (imag * a.real - real * a.imag) / denominator);
}
void ComplexNumber::Print() const{
	std::cout << real << " + " << imag << "i" << std::endl;
}