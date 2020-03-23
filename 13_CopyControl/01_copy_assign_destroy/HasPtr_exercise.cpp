#include <iostream>
#include <string>

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr&);
	HasPtr& operator=(const HasPtr&);
	void print() { std::cout << *ps << std::endl; }
	~HasPtr()
	{
		delete ps;
	}
private:
	std::string *ps;
	int i;
};

// the copy constructor (answer)
HasPtr::HasPtr(const HasPtr &orig) :
	ps( new std::string( *(orig.ps) ) ),
	i(orig.i) {}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	ps = new std::string(*rhs.ps);
	i = rhs.i;
	return *this;
}

int main()
{
	HasPtr obj1 = HasPtr("test1");

	HasPtr obj2 = obj1;

	obj1.print();
	obj2.print();
	{
		HasPtr obj3;
		obj3 = obj2;
		obj3.print();
	}
	std::cout << std::endl;

	obj1.print();
	obj2.print();

	return 0;
}