#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::toupper;

int main()
{

	vector<string> svec;
	string word;
	while (cin >> word)
		svec.push_back(word);
	for (auto s : svec)
		cout << s << " ";
	cout << endl;

	// for (auto &c : svec[0])
		// c = toupper(c);

	for (string &s : svec)
		s[0] = toupper(s[0]);

	for (auto s : svec)
		cout << s << " ";
	cout << endl;

cout << endl;

	vector<int> ivec(10, 42);
	vector<int> ivec2{42,42,42,42,42,42,42,42,42,42};
	vector<int> ivec3(10);
	for (auto &i : ivec3)
		i = 42;

	for (auto i : ivec)
		cout << i << " ";
	cout << endl;

	for (auto i : ivec2)
		cout << i << " ";
	cout << endl;

	for (auto i : ivec3)
		cout << i << " ";
	cout << endl;


cout << endl;

	vector<int> ivec4;
	int i;
	cin.clear();
	while (cin >> i)
		ivec4.push_back(i);
	
	decltype(ivec4.size()) j;
	auto _size = ivec4.size();

	for (auto i : ivec4)
		cout << i << " ";
	cout << endl;

	int sum;
	for (j = 0; j < _size-1; j += 2) 
	{
		sum = ivec4[j] + ivec4[j+1];
		cout << sum << " ";
	}
	cout << endl;

	for (j = 0; j < _size/2; ++j)
	{
		sum = ivec4[j] + ivec4[_size-j-1];
		cout << sum << " ";
	}

	return 0;
}