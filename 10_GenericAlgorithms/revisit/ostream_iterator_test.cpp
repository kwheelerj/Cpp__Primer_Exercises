#include <iostream>
#include <vector>
#include <iterator>

#include <sstream>
#include <string>

int main()
{
	std::vector<int> vec = { 0, 1, 2, 3, 4, 5 };

	std::ostream_iterator<int> out_iter(std::cout, " ");

	for (auto e : vec)
		out_iter = e;
	std::cout << std::endl;

	/* *** */

	std::vector<std::string> svec = { "kenneth", "james", "wheeler" };
	std::ostringstream oss;
	std::ostream_iterator<std::string> o_it(oss, " ");
	for (std::string s : svec)
		o_it = s;

	std::cout << oss.str() << std::endl;

	return 0;
}