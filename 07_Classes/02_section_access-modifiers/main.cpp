#include <iostream>
#include "Sales_data.h"


int main(int argc, char **argv)
{
	Sales_data total = Sales_data(std::cin);
	print(std::cout, total);
	return 0;

	if (read(std::cin, total))
	{
		Sales_data trans;
		while(read(std::cin, trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(std::cout, trans) << std::endl;
				total = trans;
			}
		}
		print(std::cout, total) << std::endl;
	}
	else
	{
		std::cerr << "No data." << std::endl;
	}

	return 0;
}