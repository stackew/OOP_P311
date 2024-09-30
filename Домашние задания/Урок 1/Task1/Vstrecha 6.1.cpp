#include <iostream>

#include "Fraction.h";

void PrintResult(const Fraction& result)
{
	std::cout << "Получившаяся дробь: " << result.GetNumerator() << "/"
		<< result.GetDenominator() << std::endl;
}

int main()
{
	setlocale(LC_ALL, "rus");

	Fraction fraction1, fraction2;
	std::cout << "Дробь 1" << std::endl;
	fraction1 = fraction1.InputData();

	std::cout << "\nДробь 2" << std::endl;
	fraction2 = fraction2.InputData();

	PrintResult(fraction1 + fraction2);
	PrintResult(fraction1 - fraction2);
	PrintResult(fraction1 * fraction2);
	PrintResult(fraction1 / fraction2);

	return 0;
}