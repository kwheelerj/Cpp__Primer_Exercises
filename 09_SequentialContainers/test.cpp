#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::vector<int> vi;

	vi.emplace(vi.begin());

	for (auto it = vi.begin(); it != vi.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	if (!vi.empty())
	{
		vi.front() = 1;

		for (auto it = vi.begin(); it != vi.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		auto v = vi.back();
		v = 23;

		for (auto it = vi.begin(); it != vi.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		auto &vr = vi.back();
		vr = 42;

		for (auto it = vi.begin(); it != vi.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	try
	{
		std::cout << vi.at(1);
	}
	// catch(const std::exception& e)
	catch (const std::out_of_range &e)
	{
		std::cerr << e.what() << '\n';
	}

	if (!vi.empty())
	{
		vi.pop_back();
	}
	std::cout << vi.size() << std::endl;

	std::cout << "====" << std::endl;

	vi = {0, 1, 2, 3};

	std::vector<int>::iterator it_vi = vi.erase(vi.begin(), vi.end() - 2);
	std::cout << *it_vi << std::endl;

	for (auto it = vi.begin(); it != vi.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}