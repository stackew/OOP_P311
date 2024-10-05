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

	char& operator[](int ind);

	char operator[](int ind) const;

	int operator()(char symbol) const;

	explicit operator int() const { return m_size; }
};

