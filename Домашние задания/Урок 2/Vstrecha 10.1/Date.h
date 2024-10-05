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

	Date(int us_day, int us_month, int us_year);

	void Increase(int n);

	void Decrease(int n);

	Date& operator++();

	const Date operator++(int);

	Date& operator--();

	const Date& operator--(int);

	friend bool operator==(const Date& date1, const Date& date2);

	friend bool operator!=(const Date& date1, const Date& date2);

	friend bool operator>(const Date& date1, const Date& date2);

	friend bool operator<(const Date& date1, const Date& date2);

	friend std::ostream& operator<< (std::ostream& output, const Date& date);

	friend std::istream& operator>> (std::istream& input, Date& date);
	
	Date& operator= (const Date& date);

	Date& operator+=(const int& n);

	Date& operator-=(const int& n);

	void operator()();
};

