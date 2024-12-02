#include <iostream>
#include <vector>
#include <Windows.h>

using char_matrix = std::vector<std::vector<char>>;

struct Node
{
    Node* left;
    Node* right;

    int data;
};

Node* CreateNode(int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = nullptr;
    new_node->right = nullptr;
    return new_node;
}

Node* InsertNode(Node* root, int data)
{
    if (root == nullptr)
    {
        return CreateNode(data);
    }

    if (data > root->data)
    {
        root->right = InsertNode(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = InsertNode(root->left, data);
    }

    return root;
}

void InorderWalk(Node* root)
{
    if (root != nullptr)
    {
        InorderWalk(root->left);
        std::cout << root->data << " ";
        InorderWalk(root->right);
    }
}

Node* SearchNode(Node* root, int val)
{
    if (root == nullptr || root->data == val)
    {
        return root;
    }

    if (root->data < val)
    {
        return SearchNode(root->right, val);
    }
    return SearchNode(root->left, val);
}

Node* DeleteNode(Node* root, int data)
{
    if (root == nullptr)
    {
        return root;
    }

    if (data < root->data)
    {
        root->right = DeleteNode(root->left, data);
    }

    else if (data > root->data)
    {
        root->right = DeleteNode(root->right, data);
    }

    else
    {
        if (root->left == nullptr)
        {
            Node* tmp = root->right;
            delete root;
            return tmp;
        }
        else if (root->right == nullptr)
        {
            Node* tmp = root->left;
            delete root;
            return tmp;
        }
        Node* tmp = MinValueNode(root->right);
        root->data = tmp->data;
        root->right = DeleteNode(root->right, tmp->data);
    }
}

Node* MinValueNode(Node* node)
{
    Node* current = node;
    while (current && current->left != nullptr)
    {
        current = current->left;
    }

    return node;
}

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