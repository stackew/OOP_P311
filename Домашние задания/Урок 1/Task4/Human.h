#pragma once

#include <iostream>
#include <string>

class Human
{
public:
	Human(const std::string& initials, const size_t& age) :
		m_initials{initials}, m_age{age} {}

	Human() : Human{"", 0} {}

	Human(const Human& human)
	{
		m_initials = human.m_initials;
		m_age = human.m_age;
	}

	void ShowHumanInfo()
	{
		std::cout << "Инициалы: " << m_initials << std::endl;
		std::cout << "Возраст: " << m_age << std::endl;
	}

private:
	std::string m_initials;
	size_t m_age;
};

