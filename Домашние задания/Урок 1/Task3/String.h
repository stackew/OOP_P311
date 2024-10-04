#pragma once
#include <iostream>
#include <string>

class String
{
	static int obj_count;

private:
	size_t m_size;
	char* m_string;

public:

	static int GetCount()
	{
		return obj_count;
	}

	String() : String(80) {}

	String(size_t u_size);
	 
	String(char* u_string);

	String(String&& string);

	~String();

	void CinString();

	void CoutString() const;

};

