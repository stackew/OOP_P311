#include <iostream>

#include "Array.h"

Array::Array() : Array(10) {}

Array::Array(int user_size) : m_size{ user_size }, m_arr{ new int[m_size] } {}

Array::Array(Array&& array) : m_size{ array.m_size }, m_arr{ array.m_arr }
{
	array.m_arr = nullptr;
	array.m_size = 0;
}

void Array::CoutArr() const
{
	std::cout << "Array: ";
	for (size_t i = 0; i != m_size; i++)
	{
		std::cout << m_arr[i] << " ";
	}
}

void Array::FillArr()
{
	for (size_t i = 0; i < m_size; i++)
	{
		m_arr[i] = rand() % 10;
	}
}

Array::~Array()
{
	delete[] m_arr;
}