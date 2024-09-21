#include "String.h"

void String::CinString()
{
	std::cout << "Введите строку: ";
	std::cin.getline(m_string, m_size);
}

void String::CoutString()
{
	std::cout << "Ваша строка: " << m_string << std::endl;
}