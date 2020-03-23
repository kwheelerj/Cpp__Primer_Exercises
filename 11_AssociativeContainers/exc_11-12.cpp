#include <iostream>
#include <utility>
#include <vector>
#include <string>

int main()
{
	std::string str;
	int i;
	std::pair<std::string, int> pa;
	std::vector<std::pair<std::string, int>> vec;

	while (std::cin >> str)
	{
		std::cin >> i;
		// pa = { str, i };
		/* alternatively: */
		pa = std::make_pair(str, i);
		vec.push_back(pa);
	}

	for (const auto &p : vec)
		std::cout << p.first << " : " << p.second << std::endl;

	return 0;
}