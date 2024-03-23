#include "complexNumber.hpp"
#include <iostream>

ComplexNumber ComplexNumber::Sum(ComplexNumber a) {
	a.real += real;
	a.img += img;
	return a;
}
void ComplexNumber::Print() {
	std::cout << real << " + " << img << "i" << std::endl;
}