#include "Hangman.h"

std::string Hangman::DecryptWord(std::string word_to_decrypt)
{
	std::string decrypted_word;
	for (char ch : word_to_decrypt)
	{
		if (ch >= 'A' && ch <= 'Z')
		{
			char decrypted_char = (ch - 'A' - 7 + 26) % 26 + 'A';
			decrypted_word += decrypted_char;
		}
		else
		{
			decrypted_word += ch;
		}
	}

	return decrypted_word;
}

void Hangman::FindLetter(char& letter)
{
	bool is_letter_exists = false;
	for (size_t i = 0; i < hidden_word.size(); ++i)
	{
		if (letter == hidden_word[i])
		{
			display_word[i] = letter;
			is_letter_exists = true;
		}
	}
	if (!is_letter_exists)
	{
		std::cout << "К сожалению вы не угадали!" << std::endl;
		attempts_left--;
	}
}

std::string Hangman::InitDisplayWord(const int& size)
{
	std::string display_word;
	for (size_t i = 0; i < size; ++i)
	{
		display_word += '*';
	}

	return display_word;
}

void Hangman::MainGame()
{
	do
	{
		std::cout << "Осталось попыток: " << attempts_left << std::endl;
		PrintHangman();
		std::cout << "Загаданное слово: " << display_word << std::endl;

		char letter;
		std::cout << "Введите букву (английскую): ";
		std::cin >> letter;
		letter = (char)toupper(letter);

		FindLetter(letter);

	} while (display_word != hidden_word && attempts_left != 0);

}

void Hangman::PlayGame()
{
	auto start_time = std::chrono::high_resolution_clock::now();
	hidden_word = WordSelection();
	display_word = InitDisplayWord(hidden_word.size());

	MainGame();

	auto end_time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);

	GameResults(duration);
}

void Hangman::PrintHangman()
{
	if (attempts_left == 6)
	{
		std::cout << "   _____" << std::endl;
		std::cout << "  |     |" << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "  |" << std::endl;
	}
	if (attempts_left == 5)
	{
		std::cout << "   _____" << std::endl;
		std::cout << "  |     |" << std::endl;
		std::cout << "  |     O" << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "  |" << std::endl;
	}
	if (attempts_left == 4)
	{
		std::cout << "   _____" << std::endl;
		std::cout << "  |     |" << std::endl;
		std::cout << "  |     O" << std::endl;
		std::cout << "  |     |" << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "  |" << std::endl;
	}
	if (attempts_left == 3)
	{
		std::cout << "   _____" << std::endl;
		std::cout << "  |     |" << std::endl;
		std::cout << "  |     O" << std::endl;
		std::cout << "  |    /|" << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "  |" << std::endl;
	}
	if (attempts_left == 2)
	{
		std::cout << "   _____" << std::endl;
		std::cout << "  |     |" << std::endl;
		std::cout << "  |     O" << std::endl;
		std::cout << "  |    /|\\" << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "  |" << std::endl;

	}
	if (attempts_left == 1)
	{
		std::cout << "   _____" << std::endl;
		std::cout << "  |     |" << std::endl;
		std::cout << "  |     O" << std::endl;
		std::cout << "  |    /|\\" << std::endl;
		std::cout << "  |    /" << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "  |" << std::endl;
	}
	if (attempts_left == 0)
	{
		std::cout << "   _____" << std::endl;
		std::cout << "  |     |" << std::endl;
		std::cout << "  |     O" << std::endl;
		std::cout << "  |    /|\\" << std::endl;
		std::cout << "  |    / \\" << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << "  |" << std::endl;
	}
	std::cout << std::endl;
}

void Hangman::GameResults(const std::chrono::seconds& duration) const
{
	if (display_word == hidden_word)
	{
		std::cout << "Поздравляю, вы угадали слово!" << std::endl;
	}
	else
	{
		std::cout << "К сожалению вы не смогли угадать слово." << std::endl;
	}
	std::cout << "\n\nКоличество оставшихся попыток: " << attempts_left << "/6" << std::endl;
	std::cout << "Время игры: " << duration.count() << " секунд" << std::endl;
	std::cout << "Искомое слово: " << hidden_word << std::endl;
	std::cout << "Буквы игрока: " << display_word << std::endl;
}

std::string Hangman::WordSelection()
{
	std::ifstream file("EncryptedWords.txt");
	std::vector<std::string> words;
	std::string word;

	if (!file.is_open())
	{
		std::cerr << "Не удалось открыть файл." << std::endl;
	}
	else
	{
		while (file >> word)
		{
			words.push_back(word);
		}

		file.close();
	}

	std::string encrypted_word = words[rand() % words.size()];
	encrypted_word = DecryptWord(encrypted_word);

	return encrypted_word;
}