#pragma once

#include "Apartment.h"

class House
{
public:
	House() : m_count_apartments{ 0 }, m_apartments{ new Apartment[m_count_apartments] } {}

	~House()
	{
		delete[] m_apartments;
	}

	void AddApartment(const Apartment& apartment);

	void ShowHouseInfo();


private:
	int m_count_apartments;
	Apartment* m_apartments;
};

