#include <iostream>
#include "Chapter6.h"

int main()
{
	std::cout << "Enter a number to find the factorial of: ";
	int num;
	std::cin >> num;
	std::cout << "The factorial of " << num << " is " << fact(num) << std::endl;
	std::cout << "Abs value of -5 is " << abs(-5) << std::endl;

	return 0;
}

int fact(int num)
{
	int res = 1;
	while (num > 1)
	{
		res *= num--;
	}
	return res;
}

int abs(int num)
{
	return num < 0 ? num * -1 : num;
}

