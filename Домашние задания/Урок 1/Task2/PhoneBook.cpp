#include <iostream>

#include "PhoneBook.h"

void PhoneBook::AddSub()
{
	Subscriber new_sub;

	std::cin.ignore();
	std::cout << "\nВведите инициалы нового абонента: ";
	std::getline(std::cin, new_sub.m_initials);
	std::cout << "Введите телефон нового абонента: ";
	std::cin >> new_sub.m_phone_number;
	std::cout << "Введите рабочий телефон нового абонента: ";
	std::cin >> new_sub.m_work_number;
	std::cout << "Введите другую информацию о новом абоненте: ";
	std::cin.ignore();
	std::getline(std::cin, new_sub.m_other_info);

	book_data.push_back(new_sub);

};

void PhoneBook::AddSubFromFile()
{
	std::string path;

	std::cout << "\nВведите файл из которого надо брать данные, вместе с расширением"
		<< "(вы должны создать файл заранее и ввести данные об абоненте, "
		<< "каждая новая данная в новой строке): ";
	std::cin >> path;

	std::ifstream file;

	file.open(path);

	if (!file.is_open())
	{
		std::cout << "Файл не удалось открыть." << std::endl;
	}
	else
	{
		Subscriber sub;

		std::getline(file, sub.m_initials);
		std::getline(file, sub.m_phone_number);
		std::getline(file, sub.m_work_number);
		std::getline(file, sub.m_other_info);

		std::cin.ignore();

		book_data.push_back(sub);

		std::cout << "Данные успешно загружены." << std::endl;

	}
}

void PhoneBook::DeleteSub()
{
	std::string sub_init;

	std::cout << "\nВведите инициалы абонента, которого хотите удалить: ";
	std::cin.ignore();
	std::getline(std::cin, sub_init);

	auto it = std::find_if(book_data.begin(), book_data.end(),
		[&sub_init](const Subscriber& subscriber) { return subscriber.m_initials == sub_init; });

	if (it != book_data.end())
	{
		book_data.erase(it);
		std::cout << "Абонент успешно удален." << std::endl;
	}
	else
	{
		std::cout << "Такой абонент не найден." << std::endl;
	}
}

void PhoneBook::PrintBookData()
{
	std::cout << "\nТелефонная книга\n" << std::endl;

	for (const Subscriber& sub : book_data)
	{
		PrintSubData(sub);
		std::cout << std::endl;
	}
};

void PhoneBook::PrintSubData(const Subscriber& sub)
{
	std::cout << "Инициалы: " << sub.m_initials << std::endl;
	std::cout << "Номер телефона: " << sub.m_phone_number << std::endl;
	std::cout << "Рабочий телефон: " << sub.m_work_number << std::endl;
	std::cout << "Другая информация: " << sub.m_other_info << std::endl;
}

void PhoneBook::SaveBookToFile()
{
	std::ofstream file;

	file.open("PhoneBook.txt");

	if (!file.is_open())
	{
		std::cout << "\nФайл не удалось открыть." << std::endl;
	}
	else
	{
		file << "Телефонная книга";
		for (const Subscriber& sub : book_data)
		{
			file << "\n\nИнициалы: " << sub.m_initials;
			file << "\nНомер телефона: " << sub.m_phone_number;
			file << "\nРабочий номер: " << sub.m_work_number;
			file << "\nПрочая информация: " << sub.m_other_info;
		}

		std::cout << "\nКнига успешно сохранена в файл!" << std::endl;
	}

	file.close();
}

void PhoneBook::SearchByInits()
{
	std::string inits_to_search;

	std::cout << "\nВведите инициалы человека, которого хотите найти: ";

	std::cin.ignore();
	std::getline(std::cin, inits_to_search);

	std::cout << "Вот что удалось найти: " << std::endl;
	for (const Subscriber& sub : book_data)
	{
		if (sub.m_initials == inits_to_search)
		{
			PrintSubData(sub);

			std::cout << std::endl;
		}
	}
}