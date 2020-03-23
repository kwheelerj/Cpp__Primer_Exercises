#include <iostream>
#include <string>


bool hasCapitals(const std::string &str) {
	std::cout << str  << std::endl;
	for(auto c : str)
	{
		if (std::isupper(c))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	// std::string s = "string test";
	std::cout << "Enter a string: " << std::endl;
	std::string s;
	std::cin >> s;

	bool hasCaps = hasCapitals(s);
	std::cout << "The string \"" << s << "\" has capital letters? "
		<< hasCaps << std::endl;

	return 0;
}