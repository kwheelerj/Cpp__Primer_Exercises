#include <iostream>
#include "Chapter6.h"

int main()
{
	std::cout << "Enter a number to find the factorial of: ";
	int num;
	std::cin >> num;
	std::cout << "The factorial of " << num << " is " << fact(num) << std::endl;
	int num2 = 99;

	std::cout << "Before swap" << num << " " << num2 << std::endl;
	swap(&num, &num2);
	std::cout << "After swap" << num << " " << num2 << std::endl;

	return 0;
}