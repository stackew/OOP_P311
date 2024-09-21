#pragma once
#include <iostream>
#include <string>

class String
{
private:
	static int m_obj_count;
	size_t m_size;
	char* m_string;

public:

	static int GetCount()
	{
		return m_obj_count;
	}

	String() : m_size{ 80 }, m_string { new char[m_size] }
	{
		m_obj_count++;
		*m_string = '\0';
	}

	String(size_t u_size) : m_size{ u_size }, m_string { new char[m_size] }
	{
		*m_string = '\0';
		m_obj_count++;
	}
	 
	String(char* u_string) : m_size{ strlen(u_string) + 1 }, m_string { new char[m_size + 1]}
	{
		strcpy_s(m_string, m_size, u_string);
		m_obj_count++;
	}

	~String()
	{
		m_obj_count--;
		delete[] m_string;
	}

	void CinString();

	void CoutString();

};

