#include <iostream>
#include <map>
#include <vector>
#include <list>

int main()
{
	std::map<std::vector<int>::iterator, int> mvi;;
	std::map<std::list<int>::iterator, int> mli;

	std::vector<int> vi = { 1, 2, 3 };

	std::list<int> li = { 4, 5, 6 };

	mvi[vi.begin()] = 11;
	// mli[li.begin()] = 22;


	for (const auto &p : mvi)
	{
		std::cout << *p.first << std::endl;
		std::cout << "\t" << p.second << std::endl;
	}

	// for (const auto &p : mli)
	// {
	// 	std::cout << *p.first << std::endl;
	// 	std::cout << "\t" << p.second << std::endl;
	// }

	return 0;
}