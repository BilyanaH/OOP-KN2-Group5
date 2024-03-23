#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H
class ComplexNumber {
private:
	double real;
	double imag;
public:
	ComplexNumber(double real, double imag);
	double getReal() const;
	ComplexNumber Sum(ComplexNumber a) const;
	ComplexNumber Multiply(ComplexNumber a) const;
	ComplexNumber Sqrt() const;
	ComplexNumber Divide(const ComplexNumber& a) const;
	void Print() const;
};
#endif