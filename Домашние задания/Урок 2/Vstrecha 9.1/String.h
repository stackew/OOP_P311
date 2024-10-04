#pragma once

#include <iostream>
#include <string>
#include <cassert>

class String
{
	static int obj_count;

private:
	size_t m_size;
	char* m_string;

public:

	static int GetCount()
	{
		return obj_count;
	}

	String() : String(80) {}

	String(size_t u_size);

	String(char* u_string);

	String(String&& string);

	~String();

	void CinString();

	void CoutString() const;

	char& operator[](int ind)
	{
		assert((ind >= 0 and ind < m_size) and "Выход за диапозон строки");
		return m_string[ind];
	}

	char operator[](int ind) const
	{
		assert((ind >= 0 and ind < m_size) and "Выход за диапозон строки");
		return m_string[ind];
	}

	int operator()(char symbol) const
	{
		for (size_t i = 0; i < m_size; i++)
		{
			if (m_string[i] == symbol)
			{
				return i;
			}
		}
		return -1;
	}

	explicit operator int() const { return m_size; }
};

