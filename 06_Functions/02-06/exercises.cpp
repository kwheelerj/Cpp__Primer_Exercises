#include <iostream>
#include <initializer_list>
#include <vector>


int sum(std::initializer_list<int> il);


int main(int argc, char **argv)
{
	int result;
	result = sum({1, 2, 3, 4, 5});
	std::cout << result << std::endl;

	

	return 0;
}


int sum(std::initializer_list<int> il)
{
	int sum = 0;

	for (const auto &el : il)
		sum += el;
	
	return sum;
}