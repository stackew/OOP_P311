#include <iostream>

#include "Hangman.h"

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));

	Hangman Game;
	Game.PlayGame();

	return 0;
}