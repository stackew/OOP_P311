#pragma once

#include "Human.h"

class Apartment
{
public:
	Apartment() : m_humans_count{ 0 },
		m_humans{ new Human[m_humans_count] } {}

	Apartment(const Apartment& apartment);

	void AddHuman(const Human& human);

	void ShowApartmentInfo();


private:
	int m_humans_count;
	Human* m_humans;
};

