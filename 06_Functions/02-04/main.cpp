#include <iostream>
#include <string>


int max(const int n, const int *pn);
void pswap(const int *n1, const int *n2);

int main()
{
	std::cout << "Enter two numbers: ";
	int n1, n2;

	std::cin >> n1 >> n2;

	int res = max(n1, &n2);
	std::cout << "Max is " << res << std::endl;


	std::cout << n1 << " " << n2 << std::endl;
	pswap(&n1, &n2);
	std::cout << n1 << " " << n2 << std::endl;

	return 0;
}

int max(const int n, const int* pn)
{
	if (n > *pn)
		return n;
	return *pn;
}

void pswap(const int *n1, const int *n2)
{
	// const int *temp = n1;

	std::cout << n1 << " " << *n1 << std::endl;
	std::cout << n2 << " " << *n2 << std::endl;
	auto temp = n1;
	n1 = n2;
	n2 = temp;
	std::cout << n1 << " " << *n1 << std::endl;
	std::cout << n2 << " " << *n2 << std::endl;
}