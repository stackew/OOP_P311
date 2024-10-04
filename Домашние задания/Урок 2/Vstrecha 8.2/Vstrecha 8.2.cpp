#include <iostream>

#include "Array.h"

int main()
{
	Array arr1;

	arr1.FillArr();
	arr1.CoutArr();

	Array arr2(std::move(arr1));

	arr2.CoutArr();

	return 0;
}