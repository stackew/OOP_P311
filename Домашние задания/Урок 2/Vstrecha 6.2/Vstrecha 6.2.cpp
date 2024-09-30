#include <iostream>

#include "ComplexNum.h"



int main()
{
	ComplexNum comp_num1;
	ComplexNum comp_num2;

	std::cin >> comp_num1 >> comp_num2;

	std::cout << comp_num1 + comp_num2 << std::endl;
	std::cout << comp_num1 - comp_num2 << std::endl;
	std::cout << comp_num1 * comp_num2 << std::endl;
	std::cout << comp_num1 / comp_num2 << std::endl;
}