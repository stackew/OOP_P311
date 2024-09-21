#include <iostream>

#include "FuncsLibrary.h"

void AddSubWithMethods(PhoneBook& phone_book)
{
	int n_method;
	AddSubMethods method;

	std::cout << "\n1)�������" << std::endl;
	std::cout << "2)�� �����" << std::endl;
	std::cout << "������� ������ ���������� ��������: ";
	std::cin >> n_method;

	method = static_cast<AddSubMethods>(n_method);

	switch (method)
	{
	case MANUALLY:
		phone_book.AddSub();
		break;
	case FROM_FILE:
		phone_book.AddSubFromFile();
		break;
	default:
		std::cout << "������ ������� �� ����������." << std::endl;
		break;
	}
}

void Program()
{
	PhoneBook phone_book;
	int n_action;
	Actions action;

	do
	{
		ShowMenu();

		std::cin >> n_action;

		action = static_cast<Actions> (n_action);

		SwitchFunction(action, phone_book);

	} while (action != EXIT);
}

void ShowMenu()
{
	std::cout << "\n1)�������� ��������" << std::endl;
	std::cout << "2)������� ��������" << std::endl;
	std::cout << "3)������� ����� �� �����" << std::endl;
	std::cout << "4)��������� ����� � ����" << std::endl;
	std::cout << "5)����� �������� �� ���������" << std::endl;
	std::cout << "6)�����" << std::endl;
	std::cout << "��� �� ������ �������: ";
}


void SwitchFunction(const Actions& action, PhoneBook& phone_book)
{
	switch (action)
	{
	case ADD_SUBSCRIBER:
		AddSubWithMethods(phone_book);
		break;
	case DELETE_SUBSCRIBER:
		phone_book.DeleteSub();
		break;
	case PRINT_BOOK:
		phone_book.PrintBookData();
		break;
	case SEARCH_BY_INIT:
		phone_book.SearchByInits();
		break;
	case SAVE_BOOK_TO_FILE:
		phone_book.SaveBookToFile();
		break;
	case EXIT:
		std::cout << "��������� ���������." << std::endl;
		break;
	default:
		std::cout << "�� ����� ���-�� �� ���." << std::endl;
		break;
	}
}

