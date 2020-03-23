#include <iostream>
#include <string>

class PrintString
{
public:
	PrintString(std::ostream &o = std::cout, char c = ' ') :
		os(o), sep(c) {}

	void operator()(const std::string &s) const { os << s << sep; }

private:
	std::ostream &os;
	char sep;
};


int main()
{
	PrintString printer;
	PrintString p(printer);

	printer("test");

	PrintString err(std::cerr, '\n');
	err("error test");

	p("hi");

	return 0;
}