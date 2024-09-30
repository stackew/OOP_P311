#include <iostream>

#include "Overcoat.h"

bool operator==(const Overcoat& overcoat1, const Overcoat& overcoat2)
{
	return overcoat1.type == overcoat2.type;
}

Overcoat& Overcoat::operator= (Overcoat&& overcoat)
{
	if (this == &overcoat)
		return *this;
	
	type = overcoat.type;
	cost = overcoat.cost;

	overcoat.type = "";
	overcoat.cost = 0;

	return *this;
}

bool operator>(const Overcoat& overcoat1, const Overcoat& overcoat2)
{
	if (overcoat1 == overcoat2)
		return overcoat1.cost > overcoat2.cost;
}

std::ostream& operator<<(std::ostream& output, const Overcoat& overcoat)
{
	std::cout << "Тип одежды: " << overcoat.type << "\nЦена: " << overcoat.cost
		<< std::endl;

	return output;
}

std::istream& operator>>(std::istream& input, Overcoat& overcoat)
{
	input >> overcoat.type;
	
	input.ignore(1);

	input >> overcoat.cost;

	return input;
}