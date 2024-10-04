#pragma once
class Array
{
private:
	int* m_arr;
	int m_size;
public:

	Array();

	Array(int user_size);

	Array(Array&& array);

	void CoutArr() const;

	void FillArr();

	~Array();
};

