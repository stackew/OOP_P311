#pragma once

#include "Human.h"

class Apartment
{
public:
	Apartment() : m_humans_count{ 0 },
		m_humans{ new Human[m_humans_count] } {}

	Apartment(const Apartment& apartment)
	{
		m_humans_count = apartment.m_humans_count;
		m_humans = new Human[m_humans_count];
		for (size_t i = 0; i != m_humans_count; i++)
		{
			m_humans[i] = apartment.m_humans[i];
		}
	}

	~Apartment()
	{
		delete[] m_humans;
	}

	void ShowApartmentInfo()
	{
		std::cout << "Жители квартиры: " << std::endl;
		for (size_t i = 0; i != m_humans_count; i++)
		{
			m_humans[i].ShowHumanInfo();
			std::cout << std::endl;
		}
	}

	void AddHuman(const Human& human)
	{
		Human* temp_apart = new Human[m_humans_count + 1];
		for (size_t i = 0; i != m_humans_count; i++)
		{
			temp_apart[i] = m_humans[i];
		}
		delete[] m_humans;
		temp_apart[m_humans_count] = human;
		m_humans_count++;
		m_humans = temp_apart;
	}

private:
	int m_humans_count;
	Human* m_humans;
};

