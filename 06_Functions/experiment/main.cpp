#include <iostream>
#include <string>


void print(const int ia[], std::size_t size);
void print(int (&ia)[8]);


int main()
{
	int iarr[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	size_t sz = 0;

	print(iarr, sz);	
	print(iarr);

	return 0;
}