#pragma once

#include <iostream>
#include <string>

class Human
{
public:
	Human(const char* initials, const char* gender, const size_t& age) :
		m_initials{initials? new char[strlen(initials) + 1] : nullptr},
		m_gender{gender? new char[strlen(gender) + 1] : nullptr}, m_age{age}
	{
		if (m_initials) { strcpy_s(m_initials, strlen(initials) + 1, initials); };
		if (m_gender) { strcpy_s(m_gender, strlen(gender) + 1, gender); };
	}

	Human() : Human{nullptr, nullptr, 0} {}

	void ShowHumanInfo()
	{
		std::cout << "Инициалы: " << m_initials << std::endl;
		std::cout << "Гендер: " << m_gender<< std::endl;
		std::cout << "Возраст: " << m_age << std::endl;
	}

	~Human()
	{
		delete[] m_initials;
		delete[] m_gender;
		std::cout << "Вызван деструктор";
	}

private:
	char* m_initials;
	char* m_gender;
	size_t m_age;
};

