#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

void read(std::istream&, std::vector<std::string>&);
void vsprint(std::vector<std::string>&);
void elimDups(std::vector<std::string>&);
void vsprint(std::vector<std::string>&, std::vector<std::string>::const_iterator);

int main()
{
	std::vector<std::string> v;
	std::fstream input("input.dat");
	read(input, v);
	vsprint(v);

	elimDups(v);
	vsprint(v);

	stable_sort(v.begin(), v.end(),
		[] (const std::string &a, const std::string &b) { return a.size() < b.size(); }
	);
	vsprint(v);

	/* Use find_if(iter, iter, unary predicate) with a lambda expression as the predicate
	 *	to get the iterator to the first element that is at least as long as the GIVEN size.
	 */

	int sz = 5;
	auto wc = std::find_if(v.cbegin(), v.cend(),
							[sz] (const std::string &a) { return a.size() >= sz; } );
	
	vsprint(v, wc);


	/* For printing, alternatively: */
	std::for_each(wc, v.cend(), [] (const std::string &s) { std::cout << s << " "; } );
	std::cout << std::endl;

	[] (int i, int j) { return i + j; };

	return 0;
}

void read(std::istream &is, std::vector<std::string> &vec)
{
	while (is)
	{
		std::string word;
		is >> word;
		vec.push_back(word);
		
	}
}

void vsprint(std::vector<std::string> &vec)
{
	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void elimDups(std::vector<std::string> &words)
{
	std::sort(words.begin(), words.end());
	auto end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

void vsprint(std::vector<std::string> &vec, std::vector<std::string>::const_iterator it)
{
	for (; it != vec.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}