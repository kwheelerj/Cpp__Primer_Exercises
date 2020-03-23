#include <iostream>
#include <vector>
#include <string>

void print_details(std::vector<int>&, const std::string&);

int main()
{
	std::vector<int> v;
	print_details(v, "init - default");

	for (std::vector<int>::size_type ix = 0; ix != 24; ++ix)
		v.push_back(ix);
	print_details(v, "insert 24 ints");

	while (v.size() != v.capacity())
		v.push_back(0);
	print_details(v, "insert until capacity");

	v.push_back(42);
	print_details(v, "insert one past capacity");

	/* Will a resize to something smaller change the capacity? */
	v.resize(45);
	print_details(v, "resize to 45 (smaller)");

	/* shrink_to_fit is only a request */
	v.shrink_to_fit();
	print_details(v, "shrink to fit");

	return 0;
}

/* RECALL: that a string literal is a CONST. */
void print_details(std::vector<int> &v, const std::string &s)
{
	std::cout << s << std::endl;
	std::cout << "size : " << v.size() << std::endl;
	std::cout << "capacity : " << v.capacity() << std::endl;
	std::cout << std::endl;
}