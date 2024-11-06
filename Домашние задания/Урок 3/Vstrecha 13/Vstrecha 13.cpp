#include <iostream>
#include <stack>
#include <string>

bool IsMatching(char open, char close) 
{
    return (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}

std::string CheckBrackets(const std::string& str) 
{
    std::stack<char> brackets_stack;
    std::string error_message;

    for (size_t i = 0; i < str.length(); i++) 
    {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') 
        {
            brackets_stack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') 
        {
            if (brackets_stack.empty() || !IsMatching(brackets_stack.top(), ch)) 
            {
                error_message = str.substr(0, i + 1);
                return error_message;
            }
            else 
            {
                brackets_stack.pop();
            }
        }
        else if (ch == ';') 
        {
            break;
        }
    }

    if (!brackets_stack.empty()) {
        error_message = str;
        return error_message;
    }

    return "Корректная строка"; 
}

int main() 
{
    setlocale(LC_ALL, "rus");
        
    std::string input;

    std::cout << "Введите строку (она должна заканчиваться на ';'): ";
    std::getline(std::cin, input);

    std::string result = CheckBrackets(input);

    std::cout << result << std::endl;

    return 0;
}