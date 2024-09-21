#include <iostream>

#include "Fraction.h"

int Fraction::gcd(int numerator, int denominator)
{
	if (denominator == 0) return numerator;
	return gcd(denominator, numerator % denominator);
}

Fraction Fraction::InputData()
{
	Fraction fraction;

	std::cout << "Введите числитель дроби: ";
	std::cin >> fraction.m_numerator;
	std::cout << "Введите знаменатель дроби: ";
	std::cin >> fraction.m_denominator;
	while (fraction.m_denominator == 0)
	{
		std::cout << "Знаменатель не может быть равен нулю!" << std::endl;
		std::cout << "Введите другой знаменатель: ";
		std::cin >> fraction.m_denominator;
	}

	return fraction;
}

void Fraction::SimplifyFraction(Fraction& fraction)
{
	int numerator = fraction.m_numerator;
	int denominator = fraction.m_denominator;

	fraction.m_numerator = numerator / gcd(numerator, denominator);
	fraction.m_denominator = denominator / gcd(numerator, denominator);
}

void Fraction::DenReduction(Fraction const& fraction1, Fraction const& fraction2,
	Fraction& answer)
{

	answer.m_denominator = gcd(fraction1.m_denominator, fraction2.m_denominator);
	answer.m_denominator = (fraction1.m_denominator * fraction2.m_denominator) /
		answer.m_denominator;
}

void Fraction::FractionSum(Fraction& fraction1, Fraction& fraction2)
{
	Fraction answer;

	DenReduction(fraction1, fraction2, answer);

	answer.m_numerator = (fraction1.m_numerator) * (answer.m_denominator
		/ fraction1.m_denominator) + (fraction2.m_numerator) *
		(answer.m_denominator / fraction2.m_denominator);

	SimplifyFraction(answer);

	std::cout << "Получившаяся дробь: " << answer.m_numerator
		<< "/" << answer.m_denominator << std::endl;
}

void Fraction::FractionSub(Fraction& fraction1, Fraction& fraction2)
{
	Fraction answer;

	DenReduction(fraction1, fraction2, answer);

	answer.m_numerator = (fraction1.m_numerator) * (answer.m_denominator
		/ fraction1.m_denominator) - (fraction2.m_numerator) *
		(answer.m_denominator / fraction2.m_denominator);

	SimplifyFraction(answer);

	std::cout << "Получившаяся дробь: " << answer.m_numerator
		<< "/" << answer.m_denominator << std::endl;
}

void Fraction::FractionMulti(Fraction& fraction1, Fraction& fraction2)
{
	Fraction answer;

	answer.m_numerator = fraction1.m_numerator * fraction2.m_numerator;
	answer.m_denominator = fraction1.m_denominator * fraction2.m_denominator;

	SimplifyFraction(answer);

	std::cout << "Получившаяся дробь: " << answer.m_numerator
		<< "/" << answer.m_denominator << std::endl;
}

void Fraction::FractionDiv(Fraction& fraction1, Fraction& fraction2)
{
	Fraction answer;

	answer.m_numerator = fraction1.m_numerator * fraction2.m_denominator;
	answer.m_denominator = fraction1.m_denominator * fraction2.m_numerator;

	SimplifyFraction(answer);

	std::cout << "Получившаяся дробь: " << answer.m_numerator
		<< "/" << answer.m_denominator << std::endl;
}
