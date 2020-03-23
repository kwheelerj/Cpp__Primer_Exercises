#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <numeric>
#include <algorithm>

int main()
{
	std::vector<double> vec = { 1.3, 2.4 };
	double dsum = std::accumulate(vec.cbegin(), vec.cend(), 0.0);
	std::cout << dsum << std::endl;

	std::vector<std::string> svec = { "My ", "name ", "is ", " bananas." };
	std::string ssum = std::accumulate(svec.cbegin(), svec.cend(), std::string(""));
	std::cout << ssum << std::endl;

	/* ex 10.5 */
	// std::vector<std::string> roster1 = { "test1", "test2" };
	std::vector<const char*> roster1 = { "test1", "test2" };
	std::list<const char*> roster2 = { "test1", "test3" };
	bool res = std::equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
	std::cout << res << std::endl;


	std::vector<int> ivec;
	ivec.resize(10);		// as long as the capacity is there
	std::fill_n(ivec.begin(), 10, 0);
	for (auto it = ivec.cbegin(); it != ivec.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	/* alternatively */

	// ivec.clear();
	// ivec.resize(0);
	// std::cout << ivec.capacity() << std::endl;

	std::vector<int> iivec;
	std::fill_n(std::back_inserter(iivec), 10, 1);

	for (auto it = iivec.cbegin(); it != iivec.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}