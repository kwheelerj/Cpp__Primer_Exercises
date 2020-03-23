#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>


void print(std::vector<int>);

int main()
{
	std::istream_iterator<int> in_iter(std::cin);
	std::istream_iterator<int> eof;
	
	// Version 1:
	/*
	std::vector<int> vec;
	while(in_iter != eof)
		vec.push_back(*in_iter++);
	*/

	// Alternatively, a shorter version of the above code is:
	std::vector<int> vec(in_iter, eof);

	print(vec);

	std::cin.clear();


	std::istream_iterator<int> in(std::cin);
	std::cout << std::accumulate(in, eof, 0);

	return 0;
}

void print(std::vector<int> v)
{
	for (int i : v)
		std::cout << i << " ";
	std::cout << std::endl;
}