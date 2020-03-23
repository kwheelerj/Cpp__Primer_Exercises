#include <iostream>

int main()
{
	/* References to const (AKA: const references) */
	int i = 42;
	int &r1 = i;
	const int &r2 = i;

	std::cout << "Init:" << std::endl;
	std::cout << "\ti = " << i << std::endl;
	std::cout << "\tr1 = " << r1 << std::endl;
	std::cout << "\tr2 = " << r2 << std::endl;

	r1 = 0;
	std::cout << "set r1 = 0:" << std::endl;
	std::cout << "\ti = " << i << std::endl;
	std::cout << "\tr1 = " << r1 << std::endl;
	std::cout << "\tr2 = " << r2 << std::endl;

	i = 5;
	std::cout << "set i = 5:" << std::endl;
	std::cout << "\ti = " << i << std::endl;
	std::cout << "\tr1 = " << r1 << std::endl;
	std::cout << "\tr2 = " << r2 << std::endl;


	std::cout << "\nconstexpr and pointers:" << std::endl;
	// constexpr int null = 0,  *p = null;

	// constexpr int null1 = 0;
	// constexpr int *p1 = null1;

	constexpr int null_ = 0;
	int *const p2 = null_;

	// if (p) { std::cout << "p is not null" << std::endl; } else { std::cout << "p is null(ptr)" << std::endl; }
	// if (p1) { std::cout << "p1 is not null" << std::endl; } else { std::cout << "p1 is null(ptr)" << std::endl; }
	if (p2) { std::cout << "p2 is not null" << std::endl; } else { std::cout << "p2 is null(ptr)" << std::endl; }

	return 0;
}