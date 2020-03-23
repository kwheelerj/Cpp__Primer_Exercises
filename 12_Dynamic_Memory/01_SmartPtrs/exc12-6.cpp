#include <iostream>
#include <vector>

std::vector<int>* factory()
{
	return new std::vector<int>();
}

void read_init(std::vector<int> *v)
{
	int i;
	while (std::cin >> i)
		v->push_back(i);
}

void print(std::vector<int> *v)
{
	for (auto i : *v)
	{
		std::cout << i << std::endl;
	}
}

int main()
{
	auto pvi = factory();
	read_init(pvi);
	print(pvi);
	
	delete pvi;

	return 0;
}