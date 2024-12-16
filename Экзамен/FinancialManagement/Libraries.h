#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <map>
#include <Windows.h>

enum CardType
{
	NONE = 0,
	DEBUT,
	CREDIT
};

struct Expenses
{
	int amount;
	std::time_t date;
	std::string category;

	Expenses(int u_amount, std::time_t u_date, const std::string& u_category) :
		amount(u_amount), date(u_date), category(u_category) {}
};

enum Options
{
	ADD_CARD = 1,
	DELETE_CARD,
	VIEW_WALLET,
	DEPOSIT,
	MAKE_PURCHASE,
	PRINT_REPORT,
	EXPENSES_TOP,
	CATEGORY_TOP,
	SAVE_TO_FILE,
	EXIT
};