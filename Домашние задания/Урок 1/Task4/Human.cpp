#include "Human.h"

Human::Human(const Human& human)
{
	m_initials = human.m_initials;
	m_age = human.m_age;
}

void Human::ShowHumanInfo()
{
	std::cout << "Инициалы: " << m_initials << std::endl;
	std::cout << "Возраст: " << m_age << std::endl;
}