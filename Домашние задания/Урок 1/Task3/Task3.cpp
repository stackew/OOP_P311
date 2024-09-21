#include <iostream>
#include <Windows.h>

#include "String.h"

int String::m_obj_count = 0;

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);

	String str;
	str.CinString();
	str.CoutString();

	String str2(100);
	str2.CinString();
	str2.CoutString();

	char user_string[80];
	std::cout << "Введите строку: ";
	std::cin.getline(user_string, 80);

	String str3(user_string);
	str3.CoutString();

	std::cout << "Количество созданных объектов: " << String::GetCount() << std::endl;

	return 0;
}
