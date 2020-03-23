#include <iostream>
#include <vector>
#include <iterator>
#include <list>

void print(std::vector<int>);
void print(std::list<int>);

int main()
{
	std::vector<int> c = { 0, 1, 2 };
	auto it = std::inserter(c, c.begin());

	*it = 42;
	*it = 43;
	++it;	// does nothing
	*it = 44;

	print(c);


	//std::vector<int> cc = { 0, 1, 2 };	// front_inserter will not work with vector, since vector does not define push_front()
	std::list<int> cc = { 0, 1, 2 };
	auto iit = std::front_inserter(cc);
	*iit = 42;
	*iit = 43;
	++iit;	// does nothing
	*iit = 44;

	print(cc);


	std::vector<int> _c = { 0, 1, 2 };
	std::back_insert_iterator<std::vector<int>> _it = std::back_inserter(_c);
	*_it = 91;
	*_it = 92;
	++_it;	// does nothing
	*_it = 93;

	print(_c);


	return 0;
}

void print(std::vector<int> vi)
{
	for (int i : vi)
		std::cout << i << " ";
	std::cout << std::endl;
}

void print(std::list<int> vi)
{
	for (int i : vi)
		std::cout << i << " ";
	std::cout << std::endl;
}