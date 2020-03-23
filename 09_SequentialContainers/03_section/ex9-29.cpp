#include <iostream>
#include <forward_list>
#include <string>

void print_list(std::forward_list<std::string> &flst);
std::forward_list<std::string>::iterator str_insert(std::forward_list<std::string>&, std::string, std::string);

int main()
{
	std::forward_list<std::string> sflst = { "test1", "test2", "test4"};
	print_list(sflst);

	auto res = str_insert(sflst, "test2", "test3");
	std::cout << *res << " == test3" << std::endl;
	print_list(sflst);

	res = str_insert(sflst, "fdsaf", "test5");
	std::cout << *res << " == test5" << std::endl;
	print_list(sflst);

	return 0;
}


std::forward_list<std::string>::iterator str_insert(std::forward_list<std::string> &flst, std::string s_find, std::string s_insert)
{
	// find first string and insert the second string right after the first string, if found.
	// if the first string is not found, then insert the string at the end of the list.

	/* Note: resizing the forward list by inserting or deleting elements does not invalidate any pointers! */
	auto prev = flst.before_begin();
	for (auto curr = flst.begin(); curr != flst.end(); ++prev, ++curr)
		if (*curr == s_find)
			return flst.insert_after(prev, s_insert);
	return flst.insert_after(prev, s_insert);
}

void print_list(std::forward_list<std::string> &flst)
{
	for (auto it = flst.cbegin(); it != flst.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}