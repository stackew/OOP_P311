#include "House.h"


void House::AddApartment(const Apartment& apartment)
{
	Apartment* new_apartments = new Apartment[m_count_apartments + 1];
	for (size_t i = 0; i != m_count_apartments; i++)
	{
		new_apartments[i] = m_apartments[i];
	}

	delete[] m_apartments;

	new_apartments[m_count_apartments] = apartment;

	m_count_apartments++;

	m_apartments = new_apartments;
}

void House::ShowHouseInfo()
{
	for (size_t i = 0; i != m_count_apartments; i++)
	{
		m_apartments[i].ShowApartmentInfo();
		std::cout << std::endl;
	}
}