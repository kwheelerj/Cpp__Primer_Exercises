#include <iostream>
#include <vector>
#include <memory>

int main()
{
	{
		std::vector<int> vec;
		std::shared_ptr<int> p = std::make_shared<int>();
		std::cout << p.use_count() << std::endl;
		vec.push_back(*p);		// vec just has a copy of the int, not the shared pointer
		// vec.push_back did not create a new shared pointer increasing the use_count, due to the deref
		std::cout << p.use_count() << std::endl;
		
		std::vector<std::shared_ptr<int>> sp_vec;
		sp_vec.push_back(p);
		std::cout << p.use_count() << std::endl;
		// now, sp_vec.push_back DID create a new shared pointer, increasing the use_count

	}

	return 0;
}