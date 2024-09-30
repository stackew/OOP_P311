#include <iostream>

#include "Flat.h"

bool operator==(const Flat& flat1, const Flat& flat2)
{
	return flat1.area == flat2.area;
}

Flat& Flat::operator= (Flat&& flat)
{
	if (this == &flat)
		return *this;

	area = flat.area;
	cost = flat.cost;

	flat.area = 0;
	flat.cost = 0;

	return *this;
}

bool operator>(const Flat& flat1, const Flat& flat2)
{
	return flat1.cost > flat2.cost;
}

std::ostream& operator<<(std::ostream& output, const Flat& flat)
{
	std::cout << "Площадь: " << flat.area << "\nЦена: " << flat.cost
		<< std::endl;

	return output;
}

std::istream& operator>>(std::istream& input, Flat& flat)
{
	input >> flat.area;

	input.ignore(1);

	input >> flat.cost;

	return input;
}
