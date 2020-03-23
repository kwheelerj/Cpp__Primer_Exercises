#include <iostream>

class A
{
public:
	A() = default;
	A(int a) : i(a) { }
	int get_i() const { return i; }
	int get_j() const { return j; }
	int get_k() const { return k; }
private:
/* garbage data if not explicitly initialized */
	int i;
	int j;
	int k;
};

int main()
{
	// A a(15);
	A a;
	std::cout << a.get_i() << std::endl;
	std::cout << a.get_j() << std::endl;
	std::cout << a.get_k() << std::endl;

	A b(4);
	std::cout << b.get_i() << std::endl;
	std::cout << b.get_j() << std::endl;
	std::cout << b.get_k() << std::endl;

	return 0;
}
