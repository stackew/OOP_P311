#include <iostream>

#include "Date.h"

int main()
{
	setlocale(LC_ALL, "rus");

	Date data1{ 1, 2, 2024 };
	Date data2;

	std::cout << "Введите дату: ";
	std::cin >> data2;
	std::cout << data1 << std::endl << data2 << std::endl;

	data1++;
	++data1;
	data2--;
	--data2;
	std::cout << data1 << std::endl << data2 << std::endl;

	bool isCheck;
	isCheck = data1 == data2;
	std::cout << isCheck << std::endl;
	isCheck = data1 != data2;
	std::cout << isCheck << std::endl;

	isCheck = data1 > data2;
	std::cout << isCheck << std::endl;
	isCheck = data1 < data2;
	std::cout << isCheck << std::endl;

	data1 = data2;
	std::cout << data1 << std::endl;

	data1 += 65;
	data1 -= 3;
	std::cout << data1 << std::endl;

	data1();
	std::cout << data1 << std::endl;

	return 0;
}