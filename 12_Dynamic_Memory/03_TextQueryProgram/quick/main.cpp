#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <set>
#include <vector>

int main()
{
	std::cout << "What word are you looking for? ";
	std::cout.flush();
	std::string query;
	std::cin >> query;

	std::ifstream fl("input.txt");
	std::string line;

	std::set<int> lines;
	int line_number = 0;
	std::vector<std::string> all_lines;

	while (std::getline(fl, line))
	{
		all_lines.push_back(line);
		++line_number;
		// std::cout << line << std::endl;
		std::istringstream iss(line);
		std::string word;
		while (iss >> word)
		{
			// std::cout << "\t" << word << std::endl;
			if (word == query)
			{
				lines.insert(line_number);
				break;
			}
		}
	}

	std::cout << "'" << query << "' occurs " <<  lines.size() << " times:" << std::endl;	
	for (const auto &w : lines)
	{
		std::cout << "\t(line " << w << ") ";
		std::cout << all_lines.at(w-1) << std::endl;
	}
	std::cout << std::endl;


	return 0;
}