#include <iostream>
#include <string>
#include <memory>


std::size_t get_size(void);

int main()
{
	int *pia = new int[42];

	// typedef int[42] arrT;
	typedef int arrT[42];
	int *p = new arrT;

	int *pia2 = new int[10]();

	std::string *psa = new std::string[5];
	std::string *psa2 = new std::string[5]();


	int *pia3 = new int[4] {0, 1, 2, 3};

	std::string *psa3 = new std::string[9] {"a", "b", std::string(2, 'x'), "d"};


	/* legal to dynamically allocate an empty array: */
	std::size_t n = get_size();
	int *pi = new int[n];

	char arr[0];	/* illegal */
	char *cp = new char[0];

	delete [] p;

	/* smart pointers and dynamic arrays: */
	/* unique pointers, good: */
	std::unique_ptr<int []> up(new int[10]);
	for (size_t i = 0; i != 10; ++i)
		up[i] = i;
	up.release();		/* uses delete [] */

	/* shared pointers - no direct support for managing dynamic arrays: */
	std::shared_ptr<int> sp(new int[10], [](int *p) { delete [] p; });
	for (size_t i = 0; i != 10; ++i)
		*(sp.get() + i) = i;
	sp.reset();

	return 0;
}

std::size_t get_size()
{
	return 0;
}