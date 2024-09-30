#include <iostream>

#include "ComplexNum.h"

std::ostream& operator<<(std::ostream& output, const ComplexNum& complex_num)
{
	char n_or_p;
	complex_num.m_imag > 0 ? n_or_p = '+' : n_or_p = ' ';
	std::cout << complex_num.m_real << n_or_p << complex_num.m_imag << "i" << std::endl;
	return output;
}
std::istream& operator>>(std::istream& input, ComplexNum& complex_num)
{
	input >> complex_num.m_real;
	input.ignore(1);
	input >> complex_num.m_imag;
	return input;
}

const ComplexNum operator+(const ComplexNum& num1, const ComplexNum& num2)
{
	return ComplexNum::Sum(num1, num2);
}

const ComplexNum operator-(const ComplexNum& num1, const ComplexNum& num2)
{
	return ComplexNum::Sub(num1, num2);
}

const ComplexNum operator*(const ComplexNum& num1, const ComplexNum& num2)
{
	return ComplexNum::Multi(num1, num2);
}

const ComplexNum operator/(const ComplexNum& num1, const ComplexNum& num2)
{
	return ComplexNum::Div(num1, num2);
}



ComplexNum ComplexNum::Sum(const ComplexNum& num1, const ComplexNum& num2)
{
	ComplexNum result;

	result.m_real = num1.m_real + num2.m_real;
	result.m_imag = num1.m_imag + num2.m_imag;

	return result;
}

ComplexNum ComplexNum::Sub(const ComplexNum& num1, const ComplexNum& num2)
{
	ComplexNum result;

	result.m_real = num1.m_real - num2.m_real;
	result.m_imag = num1.m_imag - num2.m_imag;

	return result;
}

ComplexNum ComplexNum::Multi(const ComplexNum& num1, const ComplexNum& num2)
{
	ComplexNum result;

	result.m_real = ((num1.m_real * num2.m_real) - (num1.m_imag * num2.m_imag));
	result.m_imag = (num1.m_real * num2.m_imag) + (num1.m_imag * num2.m_real);

	return result;
}

ComplexNum ComplexNum::Div(const ComplexNum& num1, const ComplexNum& num2)
{
	ComplexNum result;

	result.m_real = (num1.m_real * num2.m_real + num1.m_imag * num2.m_imag) / (num2.m_real * num2.m_real + num2.m_imag * num2.m_imag);
	result.m_imag = (num1.m_imag * num2.m_real - num1.m_real * num2.m_imag) / (num2.m_real * num2.m_real + num2.m_imag * num2.m_imag);

	return result;
}

double ComplexNum::GetReal() const
{
	return m_real;
}

double ComplexNum::GetImag() const
{
	return m_imag;
}