#include <iostream>
#include <vector>


struct X {
	X() { std::cout << "X()" << std::endl; }
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	X& operator=(const X&) { std::cout << "operator=(const X&)" << std::endl; return *this; }
	~X() { std::cout << "~X()" << std::endl; }
};

int main()
{
	X x1;
	X x2 = x1;
	std::cout << std::endl;
	X x3;
	x3 = x1;
	std::cout << std::endl;

	std::cout << "<<< START of VECTOR >>>" << std::endl;
	std::vector<X> xvec;
	std::cout << xvec.capacity() << std::endl;
	xvec.push_back(x3);
	std::cout << xvec.capacity() << std::endl;
	std::cout << "--" << std::endl;
	xvec.push_back(x2);
	std::cout << xvec.capacity() << std::endl;
	std::cout << "--" << std::endl;
	xvec.push_back(x1);
	std::cout << xvec.capacity() << std::endl;
	std::cout << "--" << std::endl;

	xvec.emplace_back();
	std::cout << xvec.capacity() << std::endl;
	std::cout << "<<< END of VECTOR >>>" << std::endl;

	std::cout << "Right before return of main()" << std::endl;

	return 0;
}