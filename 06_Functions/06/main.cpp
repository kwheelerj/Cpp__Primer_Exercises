#include <iostream>

void f();
void f(int);
void f(int, int);
void f(double d, double dd = 3.14);

int main()
{
	f();
	f(42);
	f(42, 0);
	f(2.45);
	f(2.56, 3.15);

	return 0;
}

void f()
{
	std::cout << "f() called" << std::endl;
}

void f(int i)
{
	std::cout << "f(int) called with argument i = " << i << std::endl;
}

void f(int i, int j)
{
	std::cout << "f(int, int) called with arguments i = " << i << " and j = " << j << std::endl;
}

// void f(double d, double dd = 3.14) /* DO NOT DECLARE DEFAULT ARGUMENTS TWICE! */
void f(double d, double dd)
{
	std::cout << "f(double, double = 3.14) called with argument d = " << d  << " and dd = " << dd << std::endl;
}