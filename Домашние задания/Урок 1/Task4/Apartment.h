#pragma once

#include "Human.h"

class Apartment
{
public:
	Apartment(const size_t& floor, const size_t& apartment_number) : m_floor{ floor },
		m_apartment_number{ apartment_number }, m_num_of_residents{ 0 },
		m_humans{ new Human[m_num_of_residents] {} } {}

	Apartment() : Apartment{0, 0} {}

	~Apartment()
	{
		delete[] m_humans;
	}

	void ShowApartmentInfo()
	{
		std::cout << "Этаж: " << m_floor << std::endl;
		std::cout << "Номер квартиры: " << m_apartment_number << std::endl;
		std::cout << "Жители: " << std::endl;
		for (size_t i = 0; i != m_num_of_residents; i++)
		{
			m_humans[i].ShowHumanInfo();
			std::cout << std::endl;
		}
	}

	void AddHuman(const Human& human)
	{
		Human* new_humans = new Human[m_num_of_residents + 1];
		for (size_t i = 0; i != m_num_of_residents; i++)
		{
			new_humans[i] = m_humans[i];
		}
		delete[] m_humans;

		new_humans[m_num_of_residents] = human;

		m_num_of_residents++;

		m_humans = new_humans;

	}
	
	void DeleteHuman(const Human& human)
	{
		if (IsHumanExist(human))
		{
			int j = 0;
			Human* new_humans = new Human[m_num_of_residents - 1];
			for (size_t i = 0; i != m_num_of_residents; i++)
			{
				if (&m_humans[i] == &human)
				{
					j--;
				}
				new_humans[j] = m_humans[i];
			}
			delete[] m_humans;
			m_num_of_residents--;

			m_humans = new_humans;
		}
		else
		{
			std::cout << "Этот человек не живет в этой квартире" << std::endl;
		}
	}

private:
	size_t m_floor;
	size_t m_apartment_number;
	size_t m_num_of_residents;
	Human* m_humans;
	bool IsHumanExist(const Human& human)
	{
		for (size_t i = 0; i != m_num_of_residents; i++)
		{
			if (&m_humans[i] == &human)
			{
				return true;
			}
		}
		return false;
	}
};

