#include <iostream>

#include "Flat.h"

int main()
{
	setlocale(LC_ALL, "rus");

	Flat flat1, flat2;

	std::cin >> flat1 >> flat2;

	std::cout << flat1 << "\n" << flat2 << std::endl;

	if (flat1 == flat2)
	{
		std::cout << "Площади равны" << std::endl;
	}
	else
	{
		std::cout << "Площади не равны" << std::endl;
	}

	if (flat1 > flat2)
	{
		std::cout << "Цена 1 больше чем цена 2" << std::endl;
	}
	else
	{
		std::cout << "Цена 1 меньше либо равна цене 2" << std::endl;
	}

	flat2 = std::move(flat1);

	std::cout << flat2 << std::endl;

	return 0;
}