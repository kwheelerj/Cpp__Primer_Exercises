#include <iostream>
#include <string>
#include <cstddef>
#include <iterator>
#include <vector>

int main()
{
	unsigned cnt_ = 10;

	int ar[cnt_];
	std::string sar[cnt_];

	constexpr std::size_t iarr_sz = 10;
	int iarr[iarr_sz];
	for (std::size_t i = 0; i < iarr_sz; ++i)
		iarr[i] = i;

	for (std::size_t i = 0; i < iarr_sz; ++i)
		std::cout << iarr[i] << " ";
	std::cout << std::endl;

	
	int *p = iarr;
	int *end = &iarr[10];
	for ( ; p != end; ++p)
		std::cout << *p << " ";
	std::cout << std::endl;

	int *beg = std::begin(iarr);
	int *e = std::end(iarr);
	for ( ; beg != e; ++beg)
		std::cout << *beg << " ";
	std::cout << std::endl;

	
	int *pa = std::begin(iarr);
	while (pa < e)
	{
		*pa = 0;
		++pa;
	}
	for (std::size_t i = 0; i < iarr_sz; ++i)
		std::cout << iarr[i] << " ";
	std::cout << std::endl;

	/* Compare two arrays for equality */
	int arr1[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr2[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr3[] = { 2, 3, 4, 5, 6, 7 };

	// for(int *p1 = arr1, *p2 = arr2; p1 < std::end(arr1) && p2 < std::end(arr2) && *p1 == *p2; ++p1, ++p2)
	for(int *p1 = arr1, *p2 = arr2; *p1 == *p2; ++p1, ++p2)
		std::cout << *p1 << " ";
	std::cout << std::endl;

	for(int *p1 = arr1, *p3 = arr3; p1 < std::end(arr1) && p3 < std::end(arr3) && *p1 == *p3; ++p1, ++p3)
		std::cout << *p1 << " ";
	std::cout << std::endl;

	std::vector<int> ivec1{2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> ivec2{2, 3, 4, 5, 6, 7, 8, 9};
	for(auto p1 = ivec1.cbegin(), p2 = ivec2.cbegin(); *p1 == *p2; ++p1, ++p2)
		std::cout << *p1 << " ";
	std::cout << std::endl;


	return 0;
}