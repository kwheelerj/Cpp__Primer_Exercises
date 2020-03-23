#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

int main()
{
	int val = 7;
	// std::vector<int> vec = { 0, 1, 2, 3, 4, 5 };
	// auto result = std::find(vec.cbegin(), vec.cend(), val);
	// std::cout << "The value " << val << (result == vec.cend() ? " is not present" : " is present") << std::endl;

	int ia[] = { 5, 4, 3, 2, 1, 0 };
	// int *res = std::find(std::begin(ia), std::end(ia), val);
	// std::cout << "The value " << val << (res == std::end(ia) ? " is not present" : " is present") << std::endl;

	val = 6;
	std::cout << *(ia + 4) << std::endl;
	auto ret = std::find(ia + 3, ia + 4, val);
	std::cout << ret << std::endl;
	std::cout << *ret << std::endl;
	std::cout << std::end(ia) << std::endl;
	std::cout << *std::end(ia) << std::endl;
	std::cout << *(std::end(ia)-1) << std::endl;
	// std::cout << "The value " << val << (ret == std::end(ia) ? " is not present" : " is present") << std::endl;
	std::cout << "The value " << val << (ret == ia+4 ? " is not present" : " is present") << std::endl;


	// std::list<std::string> li = { "test1", "test", "Test" };
	// std::string va = "tes";
	// auto re = std::find(li.cbegin(), li.cend(), va);
	// std::cout << "The value " << va << (re == li.cend() ? " is not present" : " is present") << std::endl;


	std::list<std::string> li = { "test1", "test1", "test", "est", "test", "test", "t" };
	std::ptrdiff_t res1 = std::count(li.cbegin(), li.cend(), "test");
	std::cout << res1 << std::endl;


	return 0;
}