#include <iostream>
#include <initializer_list>
#include <vector>

void error_msg(std::initializer_list<std::string> il);

int main()
{
	std::cout << "Enter a string" << std::endl;
	std::string s1;
	std::cin >> s1;
	std::cout << "Enter another string" << std::endl;
	std::string s2;
	std::cin >> s2;

	if (s1 != s2)
		error_msg({"functionX", s1, s2});
	else
		error_msg({"functionX", "okay"});

	return 0;
}

void error_msg(std::initializer_list<std::string> il)
{
	for (auto beg = il.begin(); beg != il.end(); ++beg)
		std::cout << *beg << " ";
	std::cout << std::endl;
}