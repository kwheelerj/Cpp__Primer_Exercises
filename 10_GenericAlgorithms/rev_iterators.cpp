#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	for (auto r_iter = vec.crbegin(); r_iter != vec.crend(); ++r_iter)
		std::cout << *r_iter << " ";
	std::cout << std::endl;

	std::sort(vec.begin(), vec.end());
	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::sort(vec.rbegin(), vec.rend());
	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;


	/* string with words, comma separated */
	std::string str = "one,two,three,last";

	auto comma = std::find(str.cbegin(), str.cend(), ',');
	for (auto it = str.cbegin(); it != comma; ++it)
		std::cout << *it;
	std::cout << std::endl;

	std::string::const_reverse_iterator last_comma = std::find(str.crbegin(), str.crend(), ',');
	std::cout << ">" << std::string(str.crbegin(), last_comma)  << "<" << std::endl;
	std::cout << ">" << std::string(last_comma.base(), str.cend()) << "<" << std::endl;

}