#include <iostream>
#include <string>
#include <memory>
#include <cstddef>

int main()
{
	std::size_t sz = 5;
	// dynamically allocated array made before user input received
	char *cp = new char[sz];

	// get user input
	{
		std::string input;
		std::cin >> input;

		if (input.size() > sz)
		{ // reallocate
			std::cout << "\treallocation necessary" << std::endl;
			delete[] cp;
			sz = input.size();
			cp = new char[sz];
		}
		std::size_t i = 0;
		for ( ; i != input.size(); ++i)
		{
			cp[i] = input[i];
		}
		cp[i] = '\0';

	} // end this scope to free memory allocated by library string

	std::cout << cp << std::endl;

	return 0;
}