#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

class PhoneBook
{
private:

	struct Subscriber
	{
		std::string m_initials;
		std::string m_phone_number;
		std::string m_work_number;
		std::string m_other_info;
	};

	std::vector<Subscriber> book_data;

	Subscriber subscriber;

public:
	PhoneBook() : book_data{ NULL }, subscriber{ "", "", "", "" } {}

	void PrintSubData(const Subscriber& sub);

	void PrintBookData();

	void AddSub();

	void DeleteSub();

	void SearchByInits();

	void SaveBookToFile();

	void AddSubFromFile();
};