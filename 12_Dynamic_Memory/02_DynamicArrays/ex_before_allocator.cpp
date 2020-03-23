#include <iostream>
#include <string>

int main()
{
	/* An example of the wastefulness of new - combining allocation AND construction: */

	size_t n = 10;
	std::string *const p = new std::string[n];
	std::string s;
	
	std::string *q = p;
	while (std::cin >> s && q != p + n)
		*q++ = s;
	
	const size_t size = q - p;
	std::cout << size << std::endl;

	delete [] p;
}
