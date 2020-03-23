#include <iostream>

int id = 0;

class numbered
{
friend void f(const numbered&);

public:
	numbered() : serial_number(++id) {}
	numbered(const numbered&) : serial_number(++id) {}
	numbered& operator=(const numbered&) { serial_number = ++id; return *this; }
private:
	int serial_number;
};

void f(const numbered &s) {
	std::cout << s.serial_number << std::endl;
}

int main()
{
	numbered a, b = a, c = b;
	f(a); f(b), f(c);

	return 0;
}