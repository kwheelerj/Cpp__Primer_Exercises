#include <iostream>
#include <memory>
#include <string>
#include <cstddef>


int main()
{
	/* A fix to the wasteful example earlier: */
	size_t n = 10;
	std::allocator<std::string> salloc;
	std::string *const p = salloc.allocate(n);

	std::string s;
	std::string *q = p;
	while (std::cin >> s && q != p + n)
		salloc.construct(q++, s);

	const std::size_t size = q - p;
	std::cout << size << std::endl;

	return 0;
}