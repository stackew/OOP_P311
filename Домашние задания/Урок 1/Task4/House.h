#pragma once

#include "Apartment.h"

class House
{
public:
	House(const char* user_adress) :
		m_adress{ user_adress ? new char[strlen(user_adress) + 1] : nullptr },
		m_num_of_apartments{ 0 },
		m_apartments{ new Apartment[m_num_of_apartments] }
	{
		if (m_adress) { strcpy_s(m_adress, strlen(user_adress) + 1, user_adress); };
	}

	House() : House{nullptr} {}

	~House()
	{
		delete[] m_adress;
		delete[] m_apartments;
	}

	void ShowHouseInfo()
	{
		std::cout << "Адресс дома: " << m_adress << std::endl;
		std::cout << "Квартиры: ";
		for (size_t i = 0; i != m_num_of_apartments; i++)
		{
			m_apartments[i].ShowApartmentInfo();
			std::cout << std::endl;
		}
	}

	void AddApartment(const Apartment& apartment)
	{
		//Apartment* new_apartments = new Apartment[m_num_of_apartments + 1];
		//for (size_t i = 0; i != m_num_of_apartments; i++)
		//{
		//	new_apartments[i] = m_apartments[i];
		//}

		//new_apartments[m_num_of_apartments++] = apartment;

		//m_apartments = new_apartments;
	}

	void DeleteApartment(const Apartment& apartment)
	{
		if (IsApartExist(apartment))
		{
			int j = 0;
			Apartment* new_apartments = new Apartment[m_num_of_apartments - 1];
			for (size_t i = 0; i != m_num_of_apartments; i++)
			{
				if (&m_apartments[i] == &apartment)
				{
					j--;
				}
				new_apartments[j] = m_apartments[i];
			}
			delete[] m_apartments;

			m_num_of_apartments--;
			m_apartments = new_apartments;
		}
		else
		{
			std::cout << "Такой квартиры нет в этом доме." << std::endl;
		}
	}

private:
	char* m_adress;
	size_t m_num_of_apartments;
	Apartment* m_apartments;
	bool IsApartExist(const Apartment& apartment)
	{
		for (size_t i = 0; i != m_num_of_apartments; i++)
		{
			if (&m_apartments[i] == &apartment)
			{
				return true;
			}
		}
		return false;
	}
};

