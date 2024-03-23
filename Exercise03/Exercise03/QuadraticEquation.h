#ifndef QUATRICEQUATION_H
#define QUATRICEQUATION_H
#include "complexNumber.h"

class QuadraticEquation {
private:
	ComplexNumber a, b, c;
public:
	QuadraticEquation(ComplexNumber a, ComplexNumber b, ComplexNumber c);
	void Solve() const;
 };
#endif