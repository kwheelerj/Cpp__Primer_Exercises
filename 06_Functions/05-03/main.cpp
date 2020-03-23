#include <iostream>
#include <cassert>

int main(int argc, char **argv)
{

#ifndef NDEBUG
	assert(0 == 0);

	std::cerr << "Error: " << __FILE__
		<< " : in function " << __func__
		<< " at line " << __LINE__
		<< " compiled on " << __DATE__
		<< " at " << __TIME__
		<< std::endl;
#endif /* NDEBUG */

	return 0;
}