#include <iostream>
#include <vector>

int main()
{
	std::vector<int> ivec;
	decltype(ivec.size()) i;
	for (i = 0; i < 10; ++i)
		ivec.push_back(i);
	for (auto it = ivec.cbegin(); it != ivec.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	for (auto it = ivec.cbegin(); it != ivec.cend() && (it+1) != ivec.cend(); ++it)
		std::cout << ( *it + *(++it) ) << " ";
	std::cout << std::endl;

	for (auto beg = ivec.cbegin(), end = ivec.cend()-1; beg != end && beg < end; ++beg, --end)
		std::cout << ( *beg + *end ) << " ";
	std::cout << std::endl;


	std::cout << "Redo of \"Grade Clustering Program\" with iterators:" << std::endl;

	std::vector<int> grades_vector{42, 65, 95, 100, 39, 67, 95, 76, 88, 76, 83, 92, 76, 93};
	
	std::vector<unsigned> scores_cluster(11, 0);
	for (auto it = grades_vector.cbegin(); it != grades_vector.cend(); ++it)
		if (*it <= 100)
			++scores_cluster[*it/10];
	
	for (auto it = scores_cluster.cbegin(); it != scores_cluster.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}