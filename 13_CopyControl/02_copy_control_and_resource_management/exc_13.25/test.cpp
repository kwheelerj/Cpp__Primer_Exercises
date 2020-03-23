#include <iostream>
#include <vector>
#include "StrBlob.h"


int main()
{
	StrBlob sb({"test1"});

	std::cout << sb.front() << std::endl;

	StrBlob sb2 = sb;

	std::cout << sb2.front() << std::endl;

	sb2.pop_back();

	std::cout << sb.empty() << std::endl;
	std::cout << sb2.empty() << std::endl;

	return 0;
}