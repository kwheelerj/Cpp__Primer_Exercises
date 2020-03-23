#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

bool partition_predicate(std::string&);
void print_it(std::vector<std::string>&);

int main()
{
	std::vector<std::string> v;
	std::ifstream input("input.dat");
	while(input)
	{
		std::string word;
		input >> word;
		v.push_back(word);
	}
	print_it(v);
	auto partition_end = std::partition(v.begin(), v.end(), partition_predicate);
	print_it(v);

	for (auto it = v.cbegin(); it != partition_end; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}

bool partition_predicate(std::string &s)
{
	return s.size() >= 5;
}

void print_it(std::vector<std::string> &vec)
{
	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;
}