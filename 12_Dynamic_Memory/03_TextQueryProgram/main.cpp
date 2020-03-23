#include <iostream>
#include <fstream>
#include <string>
#include "TextQuery.h"

void runQueries(std::ifstream &infile)
{
	// infile is an ifstream that is the file we want to query
	TextQuery tq(infile);		// store the file and build the QUERY MAP

	while (true)
	{
		std::cout << "Enter word to look for, or q to quit: ";
		std::string s;
		if ( !(std::cin >> s) || s == "q" ) break;
		
		print(std::cout, tq.query(s)) << std::endl;
	}
}

int main()
{
	std::ifstream fl("input.txt");
	runQueries(fl);

	return 0;
}