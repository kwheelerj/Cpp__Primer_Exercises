#include <iostream>

int main()
{
	std::string input;
	std::string save;
	std::string result = "No words were repeated";
	while (std::cin >> input && !input.empty())
	{
		if (!isupper(input[0]))
			continue;
		if (input == save)
		{
			result = "\"" + input + "\" was repeated";
			break;
		}
		save = input;
	}
	std::cout << result << std::endl;

	return 0;
}