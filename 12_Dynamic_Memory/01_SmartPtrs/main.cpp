#include <iostream>
#include "StrBlob.h"


void print(const StrBlob&);

int main()
{
	std::cout << "Compilation Test" << std::endl;

	StrBlob sb;
	sb.push_back("str1");

	StrBlob sb2;
	sb2.push_back("str2");

	StrBlob sb3(sb2);
	sb3.push_back("str3");

	print(sb);
	print(sb2);
	print(sb3);

	std::cout << "\nweak_ptrs\n" << std::endl;

	StrBlobPtr wp_sb3_beg = sb3.begin();
	StrBlobPtr wp_sb3_end = sb3.end();

	std::string sb3_str_beg = wp_sb3_beg.deref();
	std::cout << sb3_str_beg << std::endl;

	std::cout << wp_sb3_beg.incr().deref() << std::endl;

	std::string sb3_str_end = wp_sb3_end.deref();	// This should throw error


	return 0;
}

void print(const StrBlob &sb)
{
	std::cout << "======" << std::endl;
	std::cout << "empty : " << sb.empty() << std::endl;
	std::cout << "size : " << sb.size() << std::endl;
	std::cout << "front : " << sb.front() << std::endl;
	std::cout << "back : " << sb.back() << std::endl;
	std::cout << "======" << std::endl;
	
}