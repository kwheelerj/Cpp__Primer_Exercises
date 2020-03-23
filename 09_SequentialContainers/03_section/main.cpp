#include <iostream>
#include <deque>
#include <string>

#include <list>


#include <vector>

#include <array>

int main()
{
	/* ex 9.18 */
	std::deque<std::string> deq;

	std::string word;
	while (std::cin >> word)
	{
		deq.push_back(word);
	}

	for (auto it = deq.cbegin(); it != deq.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;


	std::cout << std::endl;

	/* ex 9.20 */
	std::list<int> ili = { 0, 1, 2, 3, 4, 5, 6, 7 };
	std::deque<int> evens, odds;

	for (auto it = ili.cbegin(); it != ili.cend(); ++it)
		*it % 2 ? odds.push_back(*it) : evens.push_back(*it);

	for (auto it = evens.cbegin(); it != evens.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	for (auto it = odds.cbegin(); it != odds.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;


	/* ex 9.21 */
	std::vector<std::string> test;
	auto iter = test.begin();
	std::cin.clear();
	while (std::cin >> word)
		iter = test.insert(iter, word);	// same as calling push_front - which dne for vectors

	for (auto it = test.cbegin(); it != test.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;


	/* ex 9.25 */
	test.erase(test.cbegin(), test.cend());	/* nothing happens here */
	for (auto it = test.cbegin(); it != test.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;


	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	std::array<int, 11> aia;
	// aia = ia;		/* library array does not allow assignment, only copy */
	std::array<int, 11> aia2 = { 1, 2, 3 };	/* 1, 2, 3, 0, 0, ... */

	std::vector<int> via;
	via.assign(std::begin(ia), std::end(ia));

	for (auto it = via.cbegin(); it != via.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::list<int> lia;
	lia.assign(std::cbegin(ia), std::cend(ia));
	for (auto it = lia.cbegin(); it != lia.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}