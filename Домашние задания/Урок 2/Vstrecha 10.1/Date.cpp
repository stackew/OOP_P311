#include "Date.h"

Date::Date(int us_day, int us_month, int us_year) : m_day{ us_day }, m_month{ us_month },
m_year{ us_year }
{
	assert((us_day > 0 and us_day < 32) and "Такого дня не существует.");
	assert((us_month > 0 and us_month < 13) and "Такого месяца не существует.");
}

void Date::Increase(int n)
{
	while (m_day + n > 31)
	{
		m_month++;
		n -= 31;
	}
	m_day = m_day + n;

	while (m_month > 12)
	{
		m_month -= 12;
		m_year++;
	}

}

void Date::Decrease(int n)
{
	while (m_day - n < 1)
	{
		n -= 31;
		m_month--;
	}
	m_day = 31 + m_day - (n + 31);


	while (m_month < 1)
	{
		m_month += 12;
		m_year--;
	}
}

Date& Date::operator++()
{
	Increase(1);
	return *this;
}

const Date Date::operator++(int)
{
	Date date{ m_day, m_month, m_year };
	++(*this);
	return date;
}

Date& Date::operator--()
{
	Decrease(1);
	return *this;
}

const Date& Date::operator--(int)
{
	Date date{ m_day, m_month, m_year };
	--(*this);
	return date;
}

bool operator==(const Date& date1, const Date& date2)
{
	return date1.m_day == date2.m_day and
		date1.m_month == date2.m_month and
		date1.m_year == date2.m_year;
}

bool operator!=(const Date& date1, const Date& date2)
{
	return date1.m_day != date2.m_day or
		date1.m_month != date2.m_month or
		date1.m_year != date2.m_year;
}

bool operator>(const Date& date1, const Date& date2)
{
	if (date1.m_year == date2.m_year)
	{
		if (date1.m_month == date2.m_month)
		{
			return date1.m_day > date2.m_day;
		}
		return date1.m_month > date2.m_month;
	}
	return date1.m_year > date2.m_year;
}

bool operator<(const Date& date1, const Date& date2)
{
	if (date1.m_year == date2.m_year)
	{
		if (date1.m_month == date2.m_month)
		{
			return date1.m_day < date2.m_day;
		}
		return date1.m_month < date2.m_month;
	}
	return date1.m_year < date2.m_year;
}

std::ostream& operator<< (std::ostream& output, const Date& date)
{
	output << date.m_day << "." << date.m_month << "." << date.m_year;
	return output;
}

std::istream& operator>> (std::istream& input, Date& date)
{
	input >> date.m_day;
	input.ignore(1);
	input >> date.m_month;
	input.ignore(1);
	input >> date.m_year;
	return input;
}

Date& Date::operator= (const Date& date)
{
	if (this == &date)
		return *this;

	m_day = date.m_day;
	m_month = date.m_month;
	m_year = date.m_year;

	return *this;
}

Date& Date::operator+=(const int& n)
{
	Increase(n);
	return *this;
}

Date& Date::operator-=(const int& n)
{
	Decrease(n);
	return *this;
}

void Date::operator()()
{
	m_day = 1;
	m_month = 1;
	m_year = 1;
}