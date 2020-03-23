#include <iostream>
#include <vector>
#include <forward_list>

void print_list(std::vector<int> &lst);
void print_list(std::forward_list<int> &lst);

int main()
{
	std::vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	print_list(vi);
	auto iter = vi.begin();
	while (iter != vi.end())
	{
		if (*iter % 2)
		{
			iter = vi.insert(iter, *iter);
			iter += 2;
		}
		else
			iter = vi.erase(iter);
		
	}
	print_list(vi);

	std::forward_list<int> fli = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	print_list(fli);
	auto it = fli.begin();
	auto prev = fli.before_begin();
	while (it != fli.end())
	{
		if (*it % 2)
		{
			prev = fli.insert_after(prev, *it);
			++it;
			++prev;
		}
		else
			it = fli.erase_after(prev);
	}
	print_list(fli);

}

void print_list(std::vector<int> &lst)
{
	for (auto it = lst.cbegin(); it != lst.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;
}
void print_list(std::forward_list<int> &lst)
{
	for (auto it = lst.cbegin(); it != lst.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;
}