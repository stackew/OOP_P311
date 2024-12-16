#include <iostream>

#include "Libraries.h"
#include "CardManager.h"

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	srand(time(NULL));

	Manager manager;
	manager.Start();

	return 0;
}