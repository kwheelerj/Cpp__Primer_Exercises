#include "Chapter6.h"

int fact(int num)
{
	int res = 1;
	while (num > 1)
	{
		res *= num--;
	}
	return res;
}