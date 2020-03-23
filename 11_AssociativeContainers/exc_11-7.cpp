#include <iostream>
#include <map>
#include <string>
#include <vector>

void print_menu(void);

int main()
{
	bool run = true;
	std::string family_name;
	std::string child_name;
	std::map<std::string, std::vector<std::string>> families;
	while (run)
	{
		print_menu();
		int choice;
		std::cin >> choice;
		switch(choice) {
		case 0:
			std::cout << "Quitting..." << std::endl;
			run = false;
			break;
		case 1:
			std::cout << "Enter family name: ";
			std::cin >> family_name;
			families[family_name];
			break;
		case 2:
			std::cout << "What family will the child be added to? ";
			std::cin >> family_name;
			if (families.find(family_name) == families.end())
				std::cout << "Family does not exist." << std::endl;
			else
			{
				std::cout << "What is the child's name? ";
				std::cin >> child_name;
				families[family_name].push_back(child_name);
			}
			break;
		case 3:
			for (const auto &vec : families)
			{
				std::cout << vec.first << std::endl;
				for (auto ch : vec.second)
					std::cout << "\t" << ch << std::endl;
				std::cout << std::endl;
			}
			break;
		default:
			std::cout << "Invalid entry" << std::endl;
			break;
		}
	}

	return 0;
}

void print_menu()
{
	std::cout << "Menu" << std::endl;
	std::cout << "1 - Add Family" << std::endl;
	std::cout << "2 - Add Child" << std::endl;
	std::cout << "3 - Print All" << std::endl;
	std::cout << "0 - Quit" << std::endl;
}