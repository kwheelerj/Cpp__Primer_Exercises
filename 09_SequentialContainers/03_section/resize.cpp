#include <iostream>
#include <list>

void print_list(std::list<int> &lst);

int main()
{
	std::list<int> li(10, 42);
	print_list(li);

	li.resize(15);
	print_list(li);

	li.resize(25, -1);
	print_list(li);

	li.resize(5, 9);	/* Note the ineffect of the 9 argument */
	print_list(li);

	return 0;
}


void print_list(std::list<int> &lst)
{
	for (auto it = lst.cbegin(); it != lst.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;
}