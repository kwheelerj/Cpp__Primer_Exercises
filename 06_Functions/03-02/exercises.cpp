#include <iostream>


int &get(int *arry, int index);


int main()
{
	int ar[] = {1, 2, 3};
	auto res = get(ar, 1);
	std::cout << res << std::endl;

	std::cout << std::endl;

	int ia[10];
	for (int i = 0; i != 10; ++i)
		get(ia, i) = i;


	for (int i = 0; i != 10; ++i)
		std::cout << ia[i] << " ";
	std::cout << std::endl;

	return 0;
}

int &get(int *arry, int index)
{
	return arry[index];
}