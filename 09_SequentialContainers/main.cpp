#include <iostream>
#include <list>
#include <vector>
#include <string>

int main()
{
	std::list<int> li = { 0, 1, 2, 3, 4 };

	for (auto b = li.cbegin(); b != li.cend(); ++b)
		std::cout << *b << " ";
	std::cout << std::endl;

	// initialize vector<double> from the list<int>:
	std::vector<double> vec(li.cbegin(), li.cend());
	vec.push_back(5.5);

	for (std::vector<double>::const_iterator a = vec.cbegin(); a != vec.cend(); ++a)
		std::cout << *a << " ";
	std::cout << std::endl;

/* Exercise 9.14 */
	std::list<const char*> cli(10, "abc");

	std::vector<std::string> svec;
	svec.assign(cli.begin(), cli.end());

	for (auto b = svec.cbegin(); b != svec.cend(); ++b)
		std::cout << *b << " ";
	std::cout << std::endl;

	return 0;
}