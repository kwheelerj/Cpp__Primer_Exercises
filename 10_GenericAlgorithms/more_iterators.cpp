#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>
#include <vector>
#include <fstream>
#include <numeric>

void liprint(std::list<int>&);
void viprint(std::vector<int>&);
void vsprint(std::vector<std::string>&);

int main()
{
	std::list<int> lst = { 1, 2, 3, 4 };
	std::list<int> lst2, lst3;

	liprint(lst);
	std::copy(lst.cbegin(), lst.cend(), std::front_inserter(lst2));
	liprint(lst2);

	std::copy(lst.cbegin(), lst.cend(), std::inserter(lst3, lst3.begin()));
	liprint(lst3);

	/* iostream iterators */
	std::vector<int> vec;
	std::istream_iterator<int> int_it(std::cin);
	std::istream_iterator<int> eof;
	while (int_it != eof)
		vec.push_back(*int_it++);
	viprint(vec);
	
	std::ifstream fin("input.dat");
	std::vector<std::string> svec;
	std::istream_iterator<std::string> str_it(fin);
	std::istream_iterator<std::string> seof;
	while (str_it != seof)
		svec.push_back(*str_it++);
	vsprint(svec);

	std::cin.clear();
	/* the while loops can actually be shortened: */
	std::istream_iterator<int> in_iter(std::cin), it_eof;
	std::vector<int> ivec(in_iter, it_eof);
	viprint(ivec);


	std::cin.clear();
	/* example stream iterator with algorithm lib */
	std::istream_iterator<int> in(std::cin), eeof;
	std::cout << std::accumulate(in, eeof, 0) << std::endl;


	/* now ostreams: */
	std::ostream_iterator<int> out_iter(std::cout, " ");
	for (auto e : ivec)
		*out_iter++ = e;	/* acutally, * and ++ do nothing for ostream_iterators */
	std::cout << std::endl;
	/* alternatively: */
	for (auto e : ivec)
		out_iter = e;
	std::cout << std::endl;

	/* Even more alternaively: */
	std::copy(ivec.cbegin(), ivec.cend(), out_iter);
	std::cout << std::endl;


	return 0;
}


void liprint(std::list<int> &li)
{
	for (auto it = li.cbegin(); it != li.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void viprint(std::vector<int> &vec)
{
	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void vsprint(std::vector<std::string> &vec)
{
	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}