#include <iostream>
#include <map>
#include <string>


int main()
{
	std::map<std::string, int> word_count;
	std::string word;

	while (std::cin >> word)
		++word_count[word];

	for (const auto &w : word_count)
		std::cout << w.first << " occurs " << w.second << ( (w.second > 1 ? " times." : " time.") ) << std::endl;


	std::cout << std::endl;


	std::map<std::string, int>::const_iterator map_it = word_count.cbegin();

	while (map_it != word_count.cend())
	{
		std::cout << map_it->first << " occurs " << map_it->second << ( (map_it->second > 1 ? " times." : " time.") ) << std::endl;
		++map_it;
	}
}