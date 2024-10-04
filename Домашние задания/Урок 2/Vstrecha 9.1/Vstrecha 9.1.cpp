#include <iostream>
#include <Windows.h>

#include "String.h"

int String::obj_count = 0;

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

	String str4(std::move(str3));
	str4.CoutString();

	std::cout << str4[3] << std::endl;

	int index = str4('b');

	if (index != -1)
	{
		std::cout << "Символ 'b' расположен под индексом: " << index << std::endl;
	}
	else
	{
		std::cout << "Символ не найден." << std::endl;
	}

	int strlen = (int)str4;

	std::cout << strlen << std::endl;

	std::cout << "Количество созданных объектов: " << String::GetCount() << std::endl;

	return 0;
}