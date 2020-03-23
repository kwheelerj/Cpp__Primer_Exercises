#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <vector>

class Screen;

class Window_mgr
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	Window_mgr();
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen&);
	void print_screens();
private:
	std::vector<Screen> screens;
};

#include "Screen.h"

Window_mgr::Window_mgr() : screens{Screen(24, 80, ' ')} {}

void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
	screens.push_back(s);
	return screens.size() - 1;
}

void Window_mgr::print_screens()
{
	std::cout << "Window_mgr::print_screens()" << std::endl;
	for (auto s : screens)
	{
		std::cout << "\t>" << s.get() << "<" << std::endl;
	}
}

#endif