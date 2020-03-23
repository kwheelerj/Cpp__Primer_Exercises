#include <iostream>

int main(int argc, char **argv)
{
	for (int i = 1; i != argc; ++i)
		std::cout << argv[i] << std::endl;



std::cout << std::endl;

	char d[] = "-d";
	for (int i = 1; i != argc; ++i)
	{
		std::cout << "\there: " << argv[i] << std::endl;
		std::cout << "\there: " << d << std::endl;


		if (argv[i] == d)
		{
			std::cout << "true : " << argv[i] << std::endl;
		}
	}
	

	return 0;
}