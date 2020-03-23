#include <iostream>
#include "Window_mgr.h"

int main()
{
	Window_mgr wm;
	wm.print_screens();
	std::cout << "===" << std::endl;

	Screen s(5, 5, '*');
	wm.addScreen(s);
	wm.addScreen(s);
	wm.print_screens();
	std::cout << "===" << std::endl;

	wm.clear(1);
	wm.print_screens();
	std::cout << "===" << std::endl;
	std::cout << "===" << std::endl;

	s.some_member();
	s.some_member();
	std::cout << "===" << std::endl;
	s.some_member_nonconst();
	s.some_member_nonconst();
	std::cout << "===" << std::endl;
	std::cout << "===" << std::endl;

	const Screen cs(4, 4, '%');
	wm.addScreen(cs);
	wm.print_screens();
	std::cout << "===" << std::endl;
	std::cout << "===" << std::endl;

	cs.some_member();
	cs.some_member();
	std::cout << "===" << std::endl;
	// cs.some_member_nonconst();	// Not available for const object
}