#include <iostream>
#include <string>

int main()
{
	int *pia = new int[5]();
	int *pia2 = new int[5]{0, 1, 2, 3, 4};

	std::cout << *pia << std::endl;
	std::cout << *(pia+1) << std::endl;
	std::cout << std::endl;
	std::cout << *pia2 << std::endl;
	std::cout << *(pia2+1) << std::endl;
	std::cout << *pia2+9 << std::endl;
	std::cout << *(pia2+9) << std::endl;	// bad

	std::cout << std::endl;

	int ar[4] = { 1, 2, 3, 4 };
	std::cout << ar[1] << std::endl;

	std::cout << std::endl;

	size_t n = 0;
	int *p = new int[n];
	// ok, but cannot deref;
	// acts as the off-the-end pointer
}