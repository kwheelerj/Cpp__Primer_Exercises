#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class HasPtr
{
friend void swap(HasPtr&, HasPtr&);

public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr&);
	HasPtr& operator=(const HasPtr&);
	void print() const { std::cout << *ps << std::endl; }
	~HasPtr()
	{
		delete ps;
	}
	bool operator<(const HasPtr&);

private:
	std::string *ps;
	int i;
};

HasPtr::HasPtr(const HasPtr &orig) :
	ps( new std::string( *(orig.ps) ) ),
	i(orig.i) {}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	auto newp = new std::string(*rhs.ps);
	delete ps;
	ps = newp;
	i = rhs.i;
	return *this;
}

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
	std::cout << "\tswapping " << lhs.ps << " (" << *lhs.ps << ") and "
				<< rhs.ps << " (" << *rhs.ps << ")" << std::endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);	// swap the pointers, not the string data
	swap(lhs.i, rhs.i);
}

bool HasPtr::operator<(const HasPtr &rhs)
{
	std::cout << "< operator" << std::endl;
	return *ps < *rhs.ps;
}

int main()
{
	HasPtr obj1 = HasPtr("test1");
	HasPtr obj2 = HasPtr("test2");

	obj1.print();
	obj2.print();
	swap(obj1, obj2);

	std::cout << std::endl;

	obj1.print();
	obj2.print();


	std::cout << std::endl;

	std::vector<HasPtr> hvec { obj1, obj2 };
	hvec.push_back(HasPtr("abc"));

	for (auto it = hvec.cbegin(); it != hvec.cend(); ++it)
		it->print();

	std::cout << std::endl;
	std::sort(hvec.begin(), hvec.end());
	std::cout << std::endl;

	// swap was not called, am I doing something wrong here?
	

	for (auto it = hvec.cbegin(); it != hvec.cend(); ++it)
		it->print();

	return 0;
}