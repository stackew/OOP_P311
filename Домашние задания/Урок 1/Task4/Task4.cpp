#include <iostream>

#include "House.h"

int main()
{
	setlocale(LC_ALL, "rus");

	Human hum1{ "Поляков Сергей Михайлович", 55 };

	Apartment apar1;

	House house;



	apar1.AddHuman(hum1);

	house.AddApartment(apar1);

	house.ShowHouseInfo();

	return 0;
}