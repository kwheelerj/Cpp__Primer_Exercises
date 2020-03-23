#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>


void print(std::multiset<std::string> m);
void print(std::vector<std::string> v);


int main()
{
	// a)
	std::multiset<std::string> mset;
	std::vector<std::string> vec = { std::string("abc"), "def", "ghi", "jkl" };

	std::copy(vec.begin(), vec.end(), std::inserter(mset, mset.end()));

	print(vec);
	print(mset);

	// b)
	/*
	 * std::multiset<int> bmset;
	 * std::copy(vec.begin(), vec.end(), std::back_inserter(bmset));
	 *** Illegal, cannot perform push_back on a map or set.
	 */

	// c)
	std::vector<std::string> cvec;
	std::copy(mset.begin(), mset.end(), std::inserter(cvec, cvec.end()));
	print(cvec);

	// d)
	std::vector<std::string> dvec;
	std:copy(mset.begin(), mset.end(), std::back_inserter(dvec));
	print(dvec);

	return 0;
}

void print(std::multiset<std::string> m)
{
	for (auto i : m)
		std::cout << i << " ";
	std::cout << std::endl;
}

void print(std::vector<std::string> v)
{
	for (auto i : v)
		std::cout << i << " ";
	std::cout << std::endl;
}