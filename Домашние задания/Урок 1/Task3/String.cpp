#include "String.h"

void String::CinString()
{
	std::cout << "������� ������: ";
	std::cin.getline(m_string, m_size);
}

void String::CoutString()
{
	std::cout << "���� ������: " << m_string << std::endl;
}