
#include <string>
#include <vector>

#include <iostream>
#include <sstream>

#include <fstream>

/* Note, this is an aggregate class */
struct PersonInfo
{
	std::string name;
	std::vector<std::string> phones;
};

int main(int argc, char **argv)
{
	std::string line, word;
	std::vector<PersonInfo> people;

	// while(std::getline(std::cin, line))
	std::ifstream input(argv[1]);
	while(std::getline(input, line))		// read from file instead
	{
		PersonInfo info;
		std::istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}

	for (auto it = people.cbegin(); it != people.cend(); ++it)
	{
		std::cout << it->name << " - ";
		for (auto j = it->phones.cbegin(); j != it->phones.cend(); ++j)
			std::cout << *j << " ";
		std::cout << std::endl;
	}

	return 0;
}