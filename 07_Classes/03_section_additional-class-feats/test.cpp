#include <iostream>

#include "Test.h"

int main(int argc, char **argv)
{
	Test obj;
	obj.setHeight(5);
	std::cout << obj.height << std::endl;

	return 0;
}