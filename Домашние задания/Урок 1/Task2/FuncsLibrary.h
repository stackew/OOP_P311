#pragma once

#include "PhoneBook.h"

enum Actions
{
	ADD_SUBSCRIBER = 1,
	DELETE_SUBSCRIBER,
	PRINT_BOOK,
	SAVE_BOOK_TO_FILE,
	SEARCH_BY_INIT,
	EXIT
};

enum AddSubMethods
{
	MANUALLY = 1,
	FROM_FILE
};

void AddSubWithMethods(PhoneBook& phone_book);

void Program();

void ShowMenu();

void SwitchFunction(const Actions& action, PhoneBook& phone_book);

