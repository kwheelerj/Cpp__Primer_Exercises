#include <iostream>
#include <stdexcept>

int main()
{
	int num1, num2, res;
	std::cout << "Enter digits: ";
	while (std::cin >> num1 >> num2)
	{
		try
		{
			if (num2 == 0)
				throw std::runtime_error("divide by 0");
			res = num1 / num2;
			std::cout << res << std::endl;
		}
		catch(std::runtime_error e)
		{
			std::cerr << e.what() << '\n';
			std::cout << "Try again?  (Y/n): " << std::endl;
			std::cin.clear();
			char c;
			std::cin >> c;
			if ( !std::cin || (c == 'n' || c == 'N') )
			{
				std::cout << "breaking from loop" << std::endl;
				break;
			}
			// std::cin.clear();
		}
		std::cout << "Enter digits: ";
	}

	return 0;
}