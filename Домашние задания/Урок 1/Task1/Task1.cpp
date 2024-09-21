#include <iostream>

#include "Fraction.h";

int main()
{
	setlocale(LC_ALL, "rus");

	Fraction fraction1, fraction2, answer;
	std::cout << "Дробь 1" << std::endl;
	fraction1 = fraction1.InputData();

	std::cout << "\nДробь 2" << std::endl;
	fraction2 = fraction2.InputData();


	answer.FractionSum(fraction1, fraction2);
	answer.FractionSub(fraction1, fraction2);
	answer.FractionMulti(fraction1, fraction2);
	answer.FractionDiv(fraction1, fraction2);
	return 0;
}