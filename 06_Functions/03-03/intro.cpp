#include <iostream>
#include <string>
#include <vector>

int (*func(int))[10];

int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


// auto func2(int i) -> int(*)[5];
int (*func2(int i))[5];

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

int (&func3(int))[5];

int main(int argc, char **argv)
{
	// int (*ret)[10] = func(1);
	// for (int i = 0; i < 10; ++i)
		// std::cout << *ret[i] << " ";
	// std::cout << std::endl;

	// std::cout << *((func2(1))[0]) << std::endl;
	std::cout << **func2(1) << std::endl;
	std::cout << *func2(1)[1] << std::endl;
	std::cout << (*func2(1))[1] << std::endl;
	std::cout << func3(1)[0] << std::endl;

	// int&odd;

	return 0;
}

int (*func(int i))[10]
{
	// This function returns a pointer to an array of 10 ints.
	// int arr[10] = {i, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	// never return a reference or a pointer to a local object
	arr[0] = i;
	return &arr;
}

auto func2(int i) -> int(*)[5]
{
	return (i % 2) ? &odd : &even;
}

int (&func3(int i))[5]
{
	return (i % 2) ? odd : even;
}