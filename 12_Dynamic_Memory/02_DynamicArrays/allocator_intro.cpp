#include <iostream>
#include <string>
#include <memory>
#include <cstddef>

#include <vector>


int main()
{
	std::size_t n = 10;

	std::allocator<std::string> alloc;
	auto const p = alloc.allocate(n);	/* allocates n UNCONSTRUCTED strings; return pointer start of allocated memory*/

	/* Herem q will point to one past the LAST constructed element */
	auto q = p;		/* Need to do this since want to later destroy p AND made p a const pointer [ auto const ] */
	alloc.construct(q++);
	alloc.construct(q++, 10, 'c');
	alloc.construct(q++, "hi");

	std::cout << *p << std::endl;
	std::cout << *(q-1) << std::endl;


	/* Destroy each constructed element... */
	while (q != p)
		alloc.destroy(--q);

	/* ... then deallocate the memory. */
	alloc.deallocate(p, n);


	std::cout << "=======" << std::endl;


	/* Algorithms to Copy and Fill Uninitialized Memory */
	/* Example: suppose we have vector<int> to COPY into dynamic memory: */
	std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	std::allocator<int> ialloc;
	int *const ip = ialloc.allocate(v.size() * 2);	/* recall: ip is a *const since we do not want ip to change what it points to - for deallocate */

	int *iq = std::uninitialized_copy(v.cbegin(), v.cend(), ip);

	for (int *i = ip; i != iq; ++i)
		std::cout << "\t" << *i << std::endl;

	std::cout << "---" << std::endl;

	/* fill in the rest of the allocated memory with 42 */
	int *iiq = std::uninitialized_fill_n(iq, v.size(), 42);

	for (int *i = ip; i != iiq; ++i)
		std::cout << "\t" << *i << std::endl;

	return 0;
}