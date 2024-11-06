#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);

	std::vector<char> text;

	char letter;

	std::cout << "Введите текст: ";
	while (std::cin.get(letter) && letter != '\n')
	{
		text.push_back(letter);
	}
	text.push_back(' ');

	std::vector<std::vector<char>> words;
	std::vector<int> counts;
	std::vector<char> current_word;

	for (char& letter : text)
	{
		if (letter != ' ' && letter != '\n' && letter != '.'
			&& letter != ',' && letter != '!' && letter != '?')
		{
			current_word.push_back(letter);
		}
		else if (!current_word.empty())
		{
			bool in_words = false;

			for (size_t i = 0; i < words.size(); i++)
			{
				if (words[i] == current_word)
				{
					counts[i]++;
					in_words = true;
					break;
				}
			}

			if (!in_words)
			{
				words.push_back(current_word);
				counts.push_back(1);
			}
			current_word.clear();
		}
	}

	size_t count = 0;
	for (const std::vector<char>& word : words)
	{
		
		for (const char& letter : word)
		{
			std::cout << letter;
		}
		std::cout << ": " << counts[count++] << std::endl;
	}

	return 0;
}