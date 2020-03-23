#include <iostream>
#include <vector>
#include <string>
#include <cctype>

int main()
{
	std::vector<int> ivec;
	decltype(ivec.size()) i;
	for (i = 0; i < 10; ++i)
		ivec.push_back(i);
	
	for (auto it = ivec.begin(); it != ivec.end(); ++it)
		*it *= 2;

	for (auto it = ivec.begin(); it != ivec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;


	/* binary search with iterators */
	int sought = 1;
	auto beg = ivec.cbegin(), end = ivec.cend();
	auto orig_beg = ivec.cbegin();
	auto mid = beg + (end - beg) / 2;
	std::cout << "orig *mid = >" << *mid << std::endl;
	std::cout << "orig mid - > " << (mid - beg) << std::endl;

	while (mid != end && *mid != sought)
	{
		if (sought < *mid)
			end = mid;
		else
			beg = mid + 1;
		mid = beg + (end - beg) / 2;
		std::cout << "\tmid = >" << (mid - orig_beg) << std::endl;
	}
	std::cout << "found? mid = " << *mid << std::endl;  

	int test = 1;
	test /= 2;
	std::cout<< test << std::endl;
	
	return 0;
}