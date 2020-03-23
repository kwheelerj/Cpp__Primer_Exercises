#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>
#include "Window_mgr.h"


class Screen
{
	friend void Window_mgr::clear(ScreenIndex);
	friend void Window_mgr::print_screens();
	// friend class Window_mgr;

public:
	using pos = std::string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') { }
	Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }

	char get() const { return contents[cursor]; }
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);

	void some_member() const;
	void some_member_nonconst();

	Screen &set(char);
	Screen &set(pos, pos, char);

	Screen &display(std::ostream &os) { do_display(os); return *this; }
	const Screen &display(std::ostream &os) const { do_display(os); return *this; }

	pos size() const;

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

	mutable size_t access_ctr = 0;		// may change, even in a const object
	size_t access_ctr_non_mutable = 0;

	void do_display(std::ostream &os) const { os << contents; }
};


char Screen::get(pos ht, pos wd) const
{
	pos row = ht * width;
	return contents[row + wd];

}

inline Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

void Screen::some_member() const
{
	++access_ctr;
	std::cout << "access_ctr: " << access_ctr << std::endl;
}

void Screen::some_member_nonconst()
{
	++access_ctr_non_mutable;
	std::cout << "access_ctr_non_mutable: " << access_ctr_non_mutable << std::endl;
}

inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;
	return *this;
}

Screen::pos Screen::size() const
{
	return height * width;
}

#endif