#include "Apartment.h"

Apartment::Apartment(const Apartment& apartment)
{
	m_humans_count = apartment.m_humans_count;
	m_humans = new Human[m_humans_count];
	for (size_t i = 0; i != m_humans_count; i++)
	{
		m_humans[i] = apartment.m_humans[i];
	}
}

void Apartment::AddHuman(const Human& human)
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

void Apartment::ShowApartmentInfo()
{
	std::cout << "Жители квартиры: " << std::endl;
	for (size_t i = 0; i != m_humans_count; i++)
	{
		m_humans[i].ShowHumanInfo();
		std::cout << std::endl;
	}
}