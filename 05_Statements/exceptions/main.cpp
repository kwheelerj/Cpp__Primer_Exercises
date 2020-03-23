#include <iostream>
#include <string>
#include <stdexcept>

int main()
{
	std::string item1, item2;
	while (std::cin >> item1 >> item2)
	{
		try
		{
			if (item1 != item2)
				throw std::runtime_error("Data must refer to same ISBN");
			std::cout << item1 + item2 << std::endl;
		}
		// catch(const std::exception& e)
		catch (std::runtime_error e)
		{
			std::cerr << e.what()
			<< "\nTry Again?  Enter y or n:" << std::endl;
			char c;
			std::cin.clear();
			std::cin >> c;
			if (!std::cin || c == 'n')
				break;
		}
	}
	return 0;
}