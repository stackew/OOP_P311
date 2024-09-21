#include <iostream>

#include "FuncsLibrary.h"

void AddSubWithMethods(PhoneBook& phone_book)
{
	int n_method;
	AddSubMethods method;

	std::cout << "\n1)Вручную" << std::endl;
	std::cout << "2)Из файла" << std::endl;
	std::cout << "Введите способ добавления абонента: ";
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
		std::cout << "Такого способа не существует." << std::endl;
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
	std::cout << "\n1)Добавить абонента" << std::endl;
	std::cout << "2)Удалить абонента" << std::endl;
	std::cout << "3)Вывести книгу на экран" << std::endl;
	std::cout << "4)Сохранить книгу в файл" << std::endl;
	std::cout << "5)Поиск абонента по инициалам" << std::endl;
	std::cout << "6)Выйти" << std::endl;
	std::cout << "Что вы хотите сделать: ";
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
		std::cout << "Программа завершена." << std::endl;
		break;
	default:
		std::cout << "Вы ввели что-то не так." << std::endl;
		break;
	}
}

