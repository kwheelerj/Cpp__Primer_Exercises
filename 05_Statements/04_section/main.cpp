#include <iostream>

int main()
{
	unsigned aCnt = 0, iCnt = 0, uCnt = 0, eCnt = 0, oCnt = 0,
		wsCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;

	char ch;
	while (std::cin >> std::noskipws >> ch)
	{
		std::cout << "char is >" << ch << "<" << std::endl;
		switch (ch)
		{
			case 'a': case 'A':
				++aCnt;
				break;
			case 'i': case 'I':
				++iCnt;
				break;
			case 'u': case 'U':
				++uCnt;
				break;
			case 'e': case 'E':
				++eCnt;
				break;
			case 'o': case 'O':
				++oCnt;
				break;
			case ' ': case '\t': case '\n':
				++wsCnt;
				break;
			case 'f':
				std::cout << "here in f" << std::endl;
				std::cin >> ch;
				switch (ch)
				{
					case 'f':
						++ffCnt;
						break;
					case 'l':
						++flCnt;
						break;
					case 'i':
						++fiCnt;
						break;
				}
				break;
			default:
				break;
		}
	}	

	std::cout << "a or A:\t" << aCnt << std::endl;
	std::cout << "i or I:\t" << iCnt << std::endl;
	std::cout << "u or U:\t" << uCnt << std::endl;
	std::cout << "e or E:\t" << eCnt << std::endl;
	std::cout << "o or O:\t" << oCnt << std::endl;
	std::cout << "white space:\t" << wsCnt << std::endl;
	std::cout << "ff:\t" << ffCnt << std::endl;
	std::cout << "fl:\t" << flCnt << std::endl;
	std::cout << "fi:\t" << fiCnt << std::endl;

	return 0;

	std::string input;
	while (std::cin >> input)
	{
		unsigned vowelCount = 0;
		std::cout << input << std::endl;
		for (auto c : input)
		{
			std::cout << "\tletter is >" << c << "<" << std::endl;
			if (c == 'a')
				++vowelCount;
			else if (c == 'i')
				++vowelCount;
			else if (c == 'u')
				++vowelCount;
			else if (c == 'e')
				++vowelCount;
			else if (c == 'o')
				++vowelCount;
		}
		std::cout << "Vowel count in \"" << input << "\" is " << vowelCount << std::endl;
	}

	return 0;
}