#ifndef TEST_H
#define TEST_H

#include <string>

int global_height;

class Test
{
public:
	typedef std::string::size_type po;
	void setHeight(po);
	po height = 0;
};

Test::po verify(Test::po);

void Test::setHeight(po var)
{
	height = verify(var);
}

Test::po verify(Test::po v) {
	return v;
}
#endif