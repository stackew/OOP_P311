#pragma once

#include <iostream>
#include <string>

class Human
{
public:
	Human(const std::string& initials, const size_t& age) :
		m_initials{initials}, m_age{age} {}

	Human() : Human{"", 0} {}

	Human(const Human& human);

	void ShowHumanInfo();

private:
	std::string m_initials;
	size_t m_age;
};

