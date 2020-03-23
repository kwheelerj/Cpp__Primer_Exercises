#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

void print_it(std::vector<std::string>&);
void elimDups(std::vector<std::string>&);

bool isShorter(const std::string&, const std::string&);

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
	elimDups(v);
	print_it(v);

	/* Now, want to prit the vector, words in order by size and alphabetically in each size */
	/* We will use a predicate here */

	// sort(v.begin(), v.end(), isShorter);

	/* alternatively */
	stable_sort(v.begin(), v.end(), isShorter);
	print_it(v);


	return 0;
}

void elimDups(std::vector<std::string> &words)
{
	std::sort(words.begin(), words.end());
	auto end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

void print_it(std::vector<std::string> &vec)
{
	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;
}

bool isShorter(const std::string &s1, const std::string &s2)
{
	return s1.size() < s2.size();
}