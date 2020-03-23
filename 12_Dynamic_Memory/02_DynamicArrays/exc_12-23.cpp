#include <iostream>
#include <memory>
#include <cstddef>
#include <cstring>
#include <iterator>


char* concat(char*, char*);
std::unique_ptr<char[]> concat_up(char*, char*);
std::string concat(std::string, std::string);

int main()
{
	char carr1[] = "banana";
	char carr2[] = "pancakes";

	std::cout << carr1 << " " << carr2 << std::endl;

	char *cp = concat(carr1, carr2);
	std::cout << cp << std::endl;

	delete [] cp;

	std::cout << std::endl;

	std::unique_ptr<char[]> up = concat_up(carr1, carr2);
	std::cout << up.get() << std::endl;

	std::cout << std::endl;

	std::string s1 = "time";
	std::string s2 = "warp";
	std::cout << concat(s1, s2) << std::endl;
	

	return 0;
}


std::unique_ptr<char[]> concat_up(char *c1, char *c2)
{
	std::size_t sz1 = std::strlen(c1);
	std::size_t sz2 = std::strlen(c2);
	std::size_t f_sz = sz1 + sz2 + 1;
	std::unique_ptr<char[]> u(new char[f_sz]);
	std::size_t j = 0;
	for (std::size_t i = 0; i != sz1; ++i, ++j)
		u[j] = c1[i];
	for (std::size_t i = 0; i != sz2; ++i, ++j)
		u[j] = c2[i];
	u[j] = '\0';
	return u;
}

char* concat(char *c1, char *c2)
{
	std::size_t sz1 = std::strlen(c1);
	std::size_t sz2 = std::strlen(c2);
	std::size_t f_sz = sz1 + sz2 + 1;
	char *cp = new char[f_sz];
	std::size_t j = 0;
	for (std::size_t i = 0; i != sz1; ++i, ++j)
		cp[j] = c1[i];
	for (std::size_t i = 0; i != sz2; ++i, ++j)
		cp[j] = c2[i];
	cp[j] = '\0';
	return cp;
}

std::string concat(std::string s1, std::string s2)
{
	return s1 + s2;
}