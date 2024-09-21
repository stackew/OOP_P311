#include <iostream>

#include "PhoneBook.h"

void PhoneBook::AddSub()
{
	Subscriber new_sub;

	std::cin.ignore();
	std::cout << "\n������� �������� ������ ��������: ";
	std::getline(std::cin, new_sub.m_initials);
	std::cout << "������� ������� ������ ��������: ";
	std::cin >> new_sub.m_phone_number;
	std::cout << "������� ������� ������� ������ ��������: ";
	std::cin >> new_sub.m_work_number;
	std::cout << "������� ������ ���������� � ����� ��������: ";
	std::cin.ignore();
	std::getline(std::cin, new_sub.m_other_info);

	book_data.push_back(new_sub);

};

void PhoneBook::AddSubFromFile()
{
	std::string path;

	std::cout << "\n������� ���� �� �������� ���� ����� ������, ������ � �����������"
		<< "(�� ������ ������� ���� ������� � ������ ������ �� ��������, "
		<< "������ ����� ������ � ����� ������): ";
	std::cin >> path;

	std::ifstream file;

	file.open(path);

	if (!file.is_open())
	{
		std::cout << "���� �� ������� �������." << std::endl;
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

		std::cout << "������ ������� ���������." << std::endl;

	}
}

void PhoneBook::DeleteSub()
{
	std::string sub_init;

	std::cout << "\n������� �������� ��������, �������� ������ �������: ";
	std::cin.ignore();
	std::getline(std::cin, sub_init);

	auto it = std::find_if(book_data.begin(), book_data.end(),
		[&sub_init](const Subscriber& subscriber) { return subscriber.m_initials == sub_init; });

	if (it != book_data.end())
	{
		book_data.erase(it);
		std::cout << "������� ������� ������." << std::endl;
	}
	else
	{
		std::cout << "����� ������� �� ������." << std::endl;
	}
}

void PhoneBook::PrintBookData()
{
	std::cout << "\n���������� �����\n" << std::endl;

	for (const Subscriber& sub : book_data)
	{
		PrintSubData(sub);
		std::cout << std::endl;
	}
};

void PhoneBook::PrintSubData(const Subscriber& sub)
{
	std::cout << "��������: " << sub.m_initials << std::endl;
	std::cout << "����� ��������: " << sub.m_phone_number << std::endl;
	std::cout << "������� �������: " << sub.m_work_number << std::endl;
	std::cout << "������ ����������: " << sub.m_other_info << std::endl;
}

void PhoneBook::SaveBookToFile()
{
	std::ofstream file;

	file.open("PhoneBook.txt");

	if (!file.is_open())
	{
		std::cout << "\n���� �� ������� �������." << std::endl;
	}
	else
	{
		file << "���������� �����";
		for (const Subscriber& sub : book_data)
		{
			file << "\n\n��������: " << sub.m_initials;
			file << "\n����� ��������: " << sub.m_phone_number;
			file << "\n������� �����: " << sub.m_work_number;
			file << "\n������ ����������: " << sub.m_other_info;
		}

		std::cout << "\n����� ������� ��������� � ����!" << std::endl;
	}

	file.close();
}

void PhoneBook::SearchByInits()
{
	std::string inits_to_search;

	std::cout << "\n������� �������� ��������, �������� ������ �����: ";

	std::cin.ignore();
	std::getline(std::cin, inits_to_search);

	std::cout << "��� ��� ������� �����: " << std::endl;
	for (const Subscriber& sub : book_data)
	{
		if (sub.m_initials == inits_to_search)
		{
			PrintSubData(sub);

			std::cout << std::endl;
		}
	}
}