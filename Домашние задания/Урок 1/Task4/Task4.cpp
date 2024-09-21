#include <iostream>

#include "House.h"

int main()
{
	setlocale(LC_ALL, "rus");

	House house{ "Улица Пушкина" };

	Apartment apar1{ 1, 1 };

	Human hum1{ "ААА", "жен", 33 };

	apar1.AddHuman(hum1);

	return 0;
}