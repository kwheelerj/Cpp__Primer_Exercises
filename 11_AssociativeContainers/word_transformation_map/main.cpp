#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>


void word_transform(std::ifstream&, std::ifstream&);
std::map<std::string, std::string> build_map(std::ifstream&);
const std::string &transform(const std::string&, const std::map<std::string, std::string>&);


int main()
{
	std::ifstream mf("word-transform.txt"), inp(std::string("input.txt"));
	word_transform(mf, inp);

	return 0;
}


void word_transform(std::ifstream &map_file, std::ifstream &input)
{
	auto trans_map = build_map(map_file);
	std::string text;

	while (std::getline(input, text))
	{
		std::istringstream stream(text);
		std::string word;
		bool first_word = true;

		while (stream >> word)
		{
			if (first_word)
				first_word = false;
			else
				std::cout << " ";

			std::cout << transform(word, trans_map);
		}
		std::cout << std::endl;
	}
}


std::map<std::string, std::string> build_map(std::ifstream &map_file)
{
	std::map<std::string, std::string> trans_map;
	std::string key;
	std::string value;

	while (map_file >> key && std::getline(map_file, value))	// "brb" ; " be right back"
	{
		std::cout << "\t" << value << std::endl;
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw std::runtime_error("No mapping for " + key);
	}
	return trans_map;
}


const std::string &transform(const std::string &s, const std::map<std::string, std::string> &m)
{
	// the actual map work; this is the heart of the program
	auto map_it = m.find(s);
	if (map_it != m.cend())
		return map_it->second;
	return s;
}