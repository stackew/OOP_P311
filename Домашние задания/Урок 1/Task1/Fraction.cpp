#include <iostream>
#include <numeric>

#include "Fraction.h"

const Fraction operator+(const Fraction& frac1, const Fraction& frac2)
{
	return Fraction::FractionSum(frac1, frac2);
}
const Fraction operator-(const Fraction& frac1, const Fraction& frac2)
{
	return Fraction::FractionSub(frac1, frac2);
}
const Fraction operator*(const Fraction& frac1, const Fraction& frac2)
{
	return Fraction::FractionMulti(frac1, frac2);
}
const Fraction operator/(const Fraction& frac1, const Fraction& frac2)
{
	return Fraction::FractionDiv(frac1, frac2);
}

Fraction Fraction::InputData()
{
	Fraction fraction;

	std::cout << "¬ведите числитель дроби: ";
	std::cin >> fraction.m_numerator;
	std::cout << "¬ведите знаменатель дроби: ";
	std::cin >> fraction.m_denominator;
	while (fraction.m_denominator == 0)
	{
		std::cout << "«наменатель не может быть равен нулю!" << std::endl;
		std::cout << "¬ведите другой знаменатель: ";
		std::cin >> fraction.m_denominator;
	}

	return fraction;
}

void Fraction::SimplifyFraction(Fraction& fraction)
{
	int numerator = fraction.m_numerator;
	int denominator = fraction.m_denominator;

	fraction.m_numerator = numerator / std::gcd(numerator, denominator);
	fraction.m_denominator = denominator / std::gcd(numerator, denominator);
}

void Fraction::DenReduction(const Fraction& fraction1, const Fraction& fraction2,
	Fraction& answer)
{

	answer.m_denominator = std::gcd(fraction1.m_denominator, fraction2.m_denominator);
	answer.m_denominator = (fraction1.m_denominator * fraction2.m_denominator) /
		answer.m_denominator;
}

Fraction Fraction::FractionSum(const Fraction& fraction1, const Fraction& fraction2)
{
	Fraction answer;

	DenReduction(fraction1, fraction2, answer);

	answer.m_numerator = (fraction1.m_numerator) * (answer.m_denominator
		/ fraction1.m_denominator) + (fraction2.m_numerator) *
		(answer.m_denominator / fraction2.m_denominator);

	SimplifyFraction(answer);

	return answer;

}

Fraction Fraction::FractionSub(const Fraction& fraction1, const Fraction& fraction2)
{
	Fraction answer;

	DenReduction(fraction1, fraction2, answer);

	answer.m_numerator = (fraction1.m_numerator) * (answer.m_denominator
		/ fraction1.m_denominator) - (fraction2.m_numerator) *
		(answer.m_denominator / fraction2.m_denominator);

	SimplifyFraction(answer);

	return answer;
}

Fraction Fraction::FractionMulti(const Fraction& fraction1, const Fraction& fraction2)
{
	Fraction answer;

	answer.m_numerator = fraction1.m_numerator * fraction2.m_numerator;
	answer.m_denominator = fraction1.m_denominator * fraction2.m_denominator;

	SimplifyFraction(answer);

	return answer;
}

Fraction Fraction::FractionDiv(const Fraction& fraction1, const Fraction& fraction2)
{
	Fraction answer;

	answer.m_numerator = fraction1.m_numerator * fraction2.m_denominator;
	answer.m_denominator = fraction1.m_denominator * fraction2.m_numerator;

	SimplifyFraction(answer);

	return answer;
}

int Fraction::GetNumerator() const
{
	return m_numerator;
}
int Fraction::GetDenominator() const
{
	return m_denominator;
}