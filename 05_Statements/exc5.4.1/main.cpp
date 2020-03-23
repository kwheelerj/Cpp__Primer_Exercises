#include <iostream>

int main()
{
	std::string input;
	std::string save;
	std::string max_rep_word;
	int count = 0;
	int max_count = 0;
	while (std::cin >> input)
	{
		if (input == save)
		{
			++count;
			if (max_count < count)
			{
				max_rep_word = input;
				max_count = count;
			}
		}
		else
		{
			count = 1;
			save = input;
		}
		
	}

	std::cout << ">" << max_rep_word << "< was repeated " << max_count << " times" << std::endl;

	return 0;
}