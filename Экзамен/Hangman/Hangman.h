#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

class Hangman
{
public:

	void PlayGame();
private:
	std::string hidden_word;
	std::string display_word;
	int attempts_left = 6;

	std::string DecryptWord(std::string word_to_decrypt);

	std::string WordSelection();

	std::string InitDisplayWord(const int& size);

	void PrintHangman();

	void FindLetter(char& letter);

	void MainGame();

	void GameResults(const std::chrono::seconds& duration) const;
};