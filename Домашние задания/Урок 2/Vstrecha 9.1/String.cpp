#include "String.h"

String::String(size_t u_size) : m_size{ u_size }, m_string{ new char[m_size] }
{
	*m_string = '\0';
	obj_count++;
}

String::String(char* u_string) : m_size{ strlen(u_string) + 1 }, m_string{ new char[m_size + 1] }
{
	strcpy_s(m_string, m_size, u_string);
	obj_count++;
}

String::~String()
{
	obj_count--;
	delete[] m_string;
}

String::String(String&& string) : m_string{ string.m_string }, m_size{ string.m_size }
{
	string.m_size = 0;
	string.m_string = nullptr;
}

void String::CinString()
{
	std::cout << "������� ������: ";
	std::cin.getline(m_string, m_size);
}

void String::CoutString() const
{
	std::cout << "���� ������: " << m_string << std::endl;
}

int String::operator()(char symbol) const
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

char& String::operator[](int ind)
{
	assert((ind >= 0 and ind < m_size) and "����� �� �������� ������");
	return m_string[ind];
}

char String::operator[](int ind) const
{
	assert((ind >= 0 and ind < m_size) and "����� �� �������� ������");
	return m_string[ind];
}