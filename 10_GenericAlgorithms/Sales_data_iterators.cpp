#include <iostream>
#include <iterator>
#include "Sales_data.h"


int main(int argc, char **argv)
{
	std::istream_iterator<Sales_data> item_iter(std::cin), eof;
	std::ostream_iterator<Sales_data> out_iter(std::cout, "\n");

	Sales_data sum = *item_iter++;

	while (item_iter != eof)
	{
		if (item_iter->isbn() == sum.isbn())
			sum += *item_iter++;
		else
		{
			out_iter = sum;
			sum += *item_iter++;
		}
	}

	out_iter = sum;

	return 0;
}