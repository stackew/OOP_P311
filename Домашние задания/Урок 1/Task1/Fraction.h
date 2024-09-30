#pragma once

class Fraction
{
	friend const Fraction operator+(const Fraction& frac1, const Fraction& frac2);
	friend const Fraction operator-(const Fraction& frac1, const Fraction& frac2);
	friend const Fraction operator*(const Fraction& frac1, const Fraction& frac2);
	friend const Fraction operator/(const Fraction& frac1, const Fraction& frac2);

public:

	Fraction() = default;

	Fraction InputData();

	static void SimplifyFraction(Fraction& fraction);

	static Fraction FractionSum(const Fraction& fraction1, const Fraction& fraction2);
	static Fraction FractionSub(const Fraction& fraction1, const Fraction& fraction2);
	static Fraction FractionMulti(const Fraction& fraction1, const Fraction& fraction2);
	static Fraction FractionDiv(const Fraction& fraction1, const Fraction& fraction2);

	int GetNumerator() const;
	int GetDenominator() const;
private:
	int m_numerator;
	int m_denominator;
	static void DenReduction(const Fraction& fraction1, const Fraction& fraction2,
		Fraction& answer);
};



