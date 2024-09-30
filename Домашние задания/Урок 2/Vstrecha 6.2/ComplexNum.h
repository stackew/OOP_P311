#pragma once

#include <fstream>

class ComplexNum
{
	friend const ComplexNum operator+(const ComplexNum& num1, const ComplexNum& num2);
	friend const ComplexNum operator-(const ComplexNum& num1, const ComplexNum& num2);
	friend const ComplexNum operator*(const ComplexNum& num1, const ComplexNum& num2);
	friend const ComplexNum operator/(const ComplexNum& num1, const ComplexNum& num2);

public:
	static ComplexNum Sum(const ComplexNum& num1, const ComplexNum& num2);
	static ComplexNum Sub(const ComplexNum& num1, const ComplexNum& num2);
	static ComplexNum Multi(const ComplexNum& num1, const ComplexNum& num2);
	static ComplexNum Div(const ComplexNum& num1, const ComplexNum& num2);

	double GetReal() const;
	double GetImag() const;

private:
	friend std::ostream& operator<<(std::ostream& output, const ComplexNum& complex_num);
	friend std::istream& operator>>(std::istream& input, ComplexNum& complex_num);

	double m_real;
	double m_imag;
};

