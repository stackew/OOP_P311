#pragma once

class Fraction
{
public:
	Fraction InputData();

	void SimplifyFraction(Fraction& fraction);

	void FractionSum(Fraction& fraction1, Fraction& fraction2);
	void FractionSub(Fraction& fraction1, Fraction& fraction2);
	void FractionMulti(Fraction& fraction1, Fraction& fraction2);
	void FractionDiv(Fraction& fraction1, Fraction& fraction2);

private:
	int m_numerator;
	int m_denominator;
	int gcd(int numerator, int denominator);
	void DenReduction(Fraction const& fraction1, Fraction const& fraction2,
		Fraction& answer);
};

