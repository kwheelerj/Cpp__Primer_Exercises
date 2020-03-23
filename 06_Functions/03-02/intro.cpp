#include <iostream>

int factorial(int val);

int main()
{
	std::cout << "Enter an integer: ";
	int input;
	std::cin >> input;
	std::cout << "Factorial of " << input << " is " << factorial(input) << std::endl;
}

int factorial(int val)
{
	if (val != 0)
		return factorial(val-1) * val;
	return 1;
}