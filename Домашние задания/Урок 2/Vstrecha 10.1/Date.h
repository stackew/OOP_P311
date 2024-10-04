#pragma once

#include <iostream>
#include <cassert>

class Date
{

private:
	int m_day;
	int m_month;
	int m_year;


public:

	Date() = default;

	Date(int us_day, int us_month, int us_year) : m_day{ us_day }, m_month{ us_month },
		m_year{ us_year }
	{
		assert((us_day > 0 and us_day < 32) and "Такого дня не существует.");
		assert((us_month > 0 and us_month < 13) and "Такого месяца не существует.");
	}

	void Increase(int n)
	{
		while (m_day + n > 31)
		{
			m_month++;
			n -= 31;
		}
		m_day = n;
		
		while (m_month > 12)
		{
			m_month -= 12;
			m_year++;
		}

	}

	void Decrease(int n);

	void CoutDate() const
	{
		std::cout << "Дата: " << m_day << "." << m_month << "." << m_year << std::endl;
	}

	Date& operator++()
	{
		Increase(1);
		return *this;
	}

	Date& operator++()
	{
		Date date{ m_day, m_month, m_year };
		++(*this);
		return date;
	}

	Date& operator--()
	{
		Decrease(1);
		return *this;
	}

	Date& operator--()
	{
		Date date{ m_day, m_month, m_year };
		--(*this);
		return date;
	}

};

