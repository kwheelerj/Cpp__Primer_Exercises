#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::cout << "test" << std::endl;

	unsigned char i = -1;
	std::cout << "unsigned char | i = " << i << std::endl;
	std::cout << "unsigned char | +i = " << +i << std::endl;
	std::cout << "unsigned char | (0 + i) = " << (0 + i) << std::endl;
	std::cout << "----------" << std::endl;

	i = 256;
	std::cout << "unsigned char | i = " << i << std::endl;
	std::cout << "unsigned char | +i = " << +i << std::endl;
	std::cout << "unsigned char | (0 + i) = " << (0 + i) << std::endl;
	std::cout << "----------" << std::endl;

	i = 257;
	std::cout << "unsigned char | i = " << i << std::endl;
	std::cout << "unsigned char | +i = " << +i << std::endl;
	std::cout << "unsigned char | (0 + i) = " << (0 + i) << std::endl;
	std::cout << "----------" << std::endl;

	signed char c = 255;
	/* undefined behavior, range between -128 and 127 */
	std::cout << "signed char | c = " << c << std::endl;
	std::cout << "signed char | +c = " << +c << std::endl;
	std::cout << "signed char | (0 + c) = " << 0 + c << std::endl;
	std::cout << "----------" << std::endl;

	c = 127;
	std::cout << "signed char | c = " << c << std::endl;
	std::cout << "signed char | +c = " << +c << std::endl;
	std::cout << "signed char | (0 + c) = " << 0 + c << std::endl;
	std::cout << "----------" << std::endl;

	c = 128;
	/* undefined behavior, range between -128 and 127 */
	std::cout << "signed char | c = " << c << std::endl;
	std::cout << "signed char | +c = " << +c << std::endl;
	std::cout << "signed char | (0 + c) = " << 0 + c << std::endl;
	std::cout << "----------" << std::endl;

	signed char c1 = 0xab;
	std::cout << (static_cast<int>(c1) & 0xff) << std::endl;
	std::cout << "----------" << std::endl;

	/* some array stuff - a refresher */
	unsigned cnt = 10;
	constexpr unsigned i_cnt = 12;
	
	int arr1[10];
	int arr2[cnt];
	int arr3[i_cnt];
	std::string bad[cnt];
	// auto ar[5] = { 1, 2, 3, 4, 5 };
	



	return 0;
}