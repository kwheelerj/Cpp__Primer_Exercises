#include <iostream>
#include <forward_list>

int main()
{
	// std::forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::forward_list<int> flst = {1, 1, 2, 2, 2, 1, 1, 1, 2, 2};
	for (auto it = flst.cbegin(); it != flst.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end())
	{
		if (*curr % 2)
			curr = flst.erase_after(prev);
		else
		{
			// prev = curr;
			++prev;
			++curr;
		}
	}

	for (auto it = flst.cbegin(); it != flst.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}