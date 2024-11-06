#include <iostream>
#include <vector>
#include <Windows.h>

using char_matrix = std::vector<std::vector<char>>;

class Stack
{
public:
    Stack() { top = -1; }

    virtual void push(char el) = 0;

    virtual char pop() = 0;

    virtual char peek() const = 0;

    virtual bool isEmpty() const = 0;

private:
    int top;
    char arr[100];
};

class CharStack : Stack
{
public:
    CharStack() { top = -1; }

    void push(char el)
    {
        if (top >= 99) 
        {
            std::cout << "Переполнение стека" << std::endl;
            return;
        }
        arr[++top] = el;
    }

    char pop()
    {
        if (isEmpty())
        {
            std::cout << "Стек пуст" << std::endl;
            return 0;
        }
        return arr[top--];
    }

    char peek() const
    {
        if (top < 0) 
        {
            std::cout << "Стек пуст" << std::endl;
            return 0;
        }
        return arr[top];
    }

    bool isEmpty() const
    {
        return (top < 0);
    }

private:
    int top;
    char arr[100];
};

class ISMAutomate
{
public:
	virtual char_matrix parse(std::vector<char> input) = 0;
};

class CSMAutomate : ISMAutomate
{
public:
	char_matrix parse(std::vector<char> input)
	{
		this->input = input;

        char_matrix output;
        std::vector<char> current_word;

        for (const char& symbol : input)
        {
            if (isNotStopSymbol(symbol))
            {
                stack.push(symbol);
            }
            else
            {
                if (symbol != '\n' && stack.peek() != '-')
                {
                    FillCurrentWord(current_word);
                    
                    FillOutput(output, current_word);
                }
            }
        }
        return output;
	}
private:
	std::vector<char> input;
	CharStack stack;

    bool isNotStopSymbol(const char& symbol)
    {
        return symbol != ' ' && symbol != '.' && symbol != ','
            && symbol != ';' && symbol != '!'
            && symbol != '?' && symbol != '\n';
    }

    void FillCurrentWord(std::vector<char>& current_word)
    {
        while (!stack.isEmpty())
        {
            current_word.push_back(stack.peek());
            stack.pop();
        }
    }

    void FillOutput(char_matrix& output, std::vector<char>& current_word)
    {
        std::reverse(current_word.begin(), current_word.end());
        output.push_back(current_word);
        current_word.clear();
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);

    std::vector<char> text;

    char letter;

    std::cout << "Введите текст: ";
    while (std::cin.get(letter) && letter != '%')
    {
        text.push_back(letter);
    }
    text.push_back(' ');

    CSMAutomate automate;
    char_matrix parsed_input = automate.parse(text);

    for (const std::vector<char>& word : parsed_input)
    {
        for (const char& letter : word)
        {
            std::cout << letter;
        }
        std::cout << std::endl;
    }
    
	return 0;
}