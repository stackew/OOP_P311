#include <iostream>
#include <Windows.h>

#include "Overcoat.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);

	Overcoat overcoat1, overcoat2;

	std::cin >> overcoat1 >> overcoat2;

	std::cout << overcoat1 << "\n" << overcoat2 << std::endl;

	if (overcoat1 == overcoat2)
	{
		std::cout << "Типы равны" << std::endl;
	}
	else
	{
		std::cout << "Типы не равны" << std::endl;
	}

	if (overcoat1 > overcoat2)
	{
		std::cout << "Цена 1 больше чем цена 2" << std::endl;
	}
	else if (!(overcoat1 == overcoat2))
	{
		std::cout << "Одежда имеет разный тип" << std::endl;
	}
	else
	{
		std::cout << "Цена 1 меньше либо равна цене 2" << std::endl;
	}

	overcoat2 = std::move(overcoat1);

	std::cout << overcoat2 << std::endl;

	return 0;
}