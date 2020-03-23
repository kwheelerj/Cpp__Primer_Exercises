#include <iostream>
#include <string>

void swap(int*, int*);
std::string::size_type find_char(const std::string &, char, std::string::size_type &);
void swap(int &, int &);

int main()
{
	int v1 = 5, v2 = 3;
	std::cout << "v1 = " << v1 << " and v2 = " << v2 << std::endl;
	swap(&v1, &v2);
	std::cout << "v1 = " << v1 << " and v2 = " << v2 << std::endl;

	std::cout << std::endl;

	std::string str = "banana";
	char ch = 'c';
	decltype(str.size()) ctr;
	auto answer = find_char(str, ch, ctr);
	std::cout << str << " has the character " << ch << " " << ctr << " times." << std::endl;
	if (answer != str.size())
		std::cout << "The first occurence of character " << ch << " is at index " << answer << " of string " << str << std::endl;

	ch = 'a';
	answer = find_char(str, ch, ctr);
	std::cout << str << " has the character " << ch << " " << ctr << " times." << std::endl;
	if (answer != str.size())
		std::cout << "The first occurence of character " << ch << " is at index " << answer << " of string " << str << std::endl;


	std::cout << std::endl;

	int n1 = 5, n2 = 3;
	std::cout << "n1 = " << n1 << " and n2 = " << n2 << std::endl;
	swap(n1, n2);
	std::cout << "n1 = " << n1 << " and n2 = " << n2 << std::endl;
	return 0;
}

void swap(int *num1, int *num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

/* returns the index of the first occurence of char c in string s
 *	&occurs counts number of c characters
 */
std::string::size_type find_char(const std::string &s, char c, std::string::size_type &occurs)
{
	std::string::size_type ret = s.size();
	occurs = 0;
	// for (std::string::const_iterator *beg = s.cbegin(); beg != s.cend(); ++beg)
	for (std::string::size_type i = 0; i != s.size(); ++i)
	{
		if (s[i] == c)
		{
			++occurs;
			ret = ret == s.size() ? i : ret;
		}
	}
	return ret;
}

void swap(int &num1, int &num2)
{
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}