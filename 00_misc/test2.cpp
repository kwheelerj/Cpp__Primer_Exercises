#include <iostream>

int main()
{

	int ia[3][4] = { {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11} };

	int ii[4] = { 100, 101, 102, 103 };
	std::cout << "ii = " <<  ii << std::endl;
	std::cout << "-----" << std::endl;
	
	for (auto p = ii; p != ii + 3; ++p)
	{
		std::cout << "p = " << p << std::endl;
		std::cout << "*p = " << *p << std::endl;
	}


	std::cout << "=======" << std::endl;


	std::cout << "ia = " << ia << std::endl;
	std::cout << "-----" << std::endl;

	for (auto p = ia; p != ia + 3; ++p)
	{
		std::cout << "p = " << p << std::endl;
		std::cout << "*p = " << *p << std::endl;
		for (auto q = *p; q != *p + 4; ++q)
		{
			std::cout << "\tq = " << q << std::endl;
			std::cout << "\t*q = " << *q << std::endl;
		}
		std::cout << "-----" << std::endl;
	}

	return 0;
}