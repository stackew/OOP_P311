#include <iostream>

class Node
{
public:
	double data;
	Node* prev, * next;

	Node(double data)
	{
		this->data = data;
		this->prev = this->next = NULL;
	}
};

class DoubleLinkedList
{
public:

	Node* head, * tail;

	DoubleLinkedList()
	{
		head = tail = NULL;
	}

	~DoubleLinkedList()
	{
		while (head != NULL)
		{
			pop_front();
		}
	}

	Node* push_front(double data)
	{
		Node* ptr = new Node(data);
		ptr->next = head;
		if (head != NULL)
		{
			head->prev = ptr;
		}
		if (tail == NULL)
		{
			tail = ptr;
		}

		return ptr;
	}

	Node* push_back(double data)
	{
		Node* ptr = new Node(data);
		ptr->prev = tail;
		if (tail != NULL)
		{
			tail->next = ptr;
		}
		if (head == NULL)
		{
			head = ptr;
		}
		tail = ptr;

		return ptr;
	}

	void pop_front()
	{
		if (head == NULL)
		{
			throw std::exception("Вы не можете удалять элемент спереди пустого списка.");
		}

		Node* ptr = head->next;
		if (ptr != NULL)
		{
			ptr->prev = NULL;
		}
		else
		{
			tail = NULL;
		}

		delete head;
		head = ptr;
	}

	void pop_back()
	{
		if (tail == NULL)
		{
			throw std::exception("Вы не можете удалять элемент c конца пустого списка.");
		}

		Node* ptr = tail->prev;
		if (ptr != NULL)
		{
			ptr->next = NULL;
		}
		else
		{
			head = NULL;
		}

		delete tail;
		tail = ptr;
	}

	void print() const
	{
		for (Node* ptr = head; ptr != NULL; ptr = ptr->next)
		{
			std::cout << ptr->data << " ";
		}
	}
};
int main()
{
	setlocale(LC_ALL, "rus");

	DoubleLinkedList list;

	//list.push_back(3.4);
	//list.push_back(2.8);
	//list.push_back(3.7);
	//list.push_back(1.0);
	//list.push_back(5.2);
	//list.print();
	//std::cout << std::endl;

	try
	{
		list.pop_front();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	list.print();

	return 0;
}