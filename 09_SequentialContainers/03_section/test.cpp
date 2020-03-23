#include <iostream>
#include <vector>

void vprint(std::vector<int> &v);

int main()
{
	std::vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vprint(vi);

	auto begin = vi.begin();
	while(begin != vi.end())
	{
		std::cout << "\t" << *begin << std::endl;
		++begin;
		begin = vi.insert(begin, 42);
		// vi.insert(begin, 42);
		/* Note: if we do not assign to begin, the iterator is invalidated by the insert, and the behavior is undefined. */
		std::cout << "\t" << *begin << std::endl;
		vprint(vi);
		std::cout << "------- bottom -------";
		++begin;
	}

}

void vprint(std::vector<int> &v)
{
	for (auto it = v.cbegin(); it != v.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}