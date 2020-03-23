#include <string>
#include <cstddef>
#include <memory>


// simplified implementation of the memory allocation strategy for a vector-like class
class StrVec
{
public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec &operator=(const StrVec&);
	~StrVec();

	void push_back(const std::string&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }

private:
	static std::allocator<std::string> alloc;
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	// utilities used by the copy constructor, assignment operator, and destructor
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free();
	void reallocate();
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};

std::allocator<std::string> StrVec::alloc;

void StrVec::push_back(const std::string& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	if (elements)
	{
		for (auto p = first_free; p != elements; )
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);	
	}
}

/* the copy control members */
StrVec::StrVec(const StrVec &orig)
{
	auto new_data = alloc_n_copy(orig.begin(), orig.end());
	elements = new_data.first;
	first_free = cap = new_data.second;
}

StrVec::~StrVec()
{
	free();
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}


void StrVec::reallocate()
{
	auto new_capacity = size() ? 2 * size() : 1;
	auto new_data = alloc.allocate(new_capacity);
	
	auto dest = new_data;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));	// move constructor used

	free();
	elements = new_data;
	first_free = dest;
	cap = elements + new_capacity;
}