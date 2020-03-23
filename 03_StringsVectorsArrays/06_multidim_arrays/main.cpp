#include <iostream>
// #include <string>
// #include <cstddef>
#include <iterator>
// #include <vector>

int main()
{
	int arr[2][3] = { 1, 2, 3, 4 };

/* This will not work since multi-dimensional array */
	// for (int *beg = std::cbegin(arr); beg != std::cend(arr); ++beg)
		// std::cout << *beg << " ";
	// std::cout << std::endl;

	int (&row)[3] = arr[1];		// binds row to the second 3-element array in arr

	constexpr size_t rowCnt = 2, colCnt = 3;
	int ia[rowCnt][colCnt];

	for (size_t i = 0; i != rowCnt; ++i)
		for (size_t j = 0; j != colCnt; ++j)
			ia[i][j] = i * colCnt + j;

	for (size_t i = 0; i != rowCnt; ++i)
	{
		for (size_t j = 0; j != colCnt; ++j)
			std::cout << ia[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// As of the new standard:
	size_t cnt = 0;
	for (auto &row : ia)
		for (auto &col : row)
			col = 2 * ++cnt;

	for (const auto &row : ia)
		for (const auto col : row)
			std::cout << col << " ";
	std::cout << std::endl;

	int (*p)[3] = ia;		/* p points to an array of 3 ints, first one of ia */
	std::cout << **ia << std::endl;

	p = &ia[1];				/* p points to last array of 3 elems */
	std::cout << *(*p+1) << std::endl;
	/* first deref causes pointer to return last array's first CONTAINER */


	// Notice the similar 2 sets of derefs here:
	for (auto p = ia; p != ia + 2; ++p)
		for (auto q = *p; q != *p + 3; ++q)
			std::cout << *q << " ";
	std::cout << std::endl;

	// Or we can use begin() and end():
	for (auto p = std::cbegin(ia); p != std::cend(ia); ++p)
		for (auto q = std::cbegin(*p); q != std::cend(*p); ++q)
			std::cout << *q << " ";
	std::cout << std::endl;

	/* without auto being used */
	for (const int (*p)[3] = std::cbegin(ia); p != std::cend(ia); ++p)
		for (const int *q = std::cbegin(*p); q != std::cend(*p); ++q)
			std::cout << *q << " ";
	std::cout << std::endl;


	return 0;
}