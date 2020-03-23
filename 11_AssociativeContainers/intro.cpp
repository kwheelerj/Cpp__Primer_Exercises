#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cctype>

int main()
{
	/* classic map (key and value) example: word counting */
	std::map<std::string, size_t> word_count;
	/* classic set (just key) example: ignore certain words in word_count */
	// std::set<std::string> exclude = { "The", "But", "And", "Or", "An", "A",
										// "the", "but", "and", "or", "a", "an" };
	std::set<std::string> exclude { "the", "but", "and", "or", "a", "an" };

	std::string word;

	while (std::cin >> word)
	{
		/* exc 11.4: normalize the input to ignore caps and puncts */
		for (auto &c : word)
			if (std::isupper(c))
				std::tolower(c);
		if (std::ispunct(word[word.size()-1]))
		{
			std::cout << ">" << word[word.size()-1] << "<" << std::endl;
			word[word.size()-1] = '\0';
		}
		
		/* test */
		// for (auto &c : word)
			// std::cout << ">" << c << "<" << std::endl;
		std::cout << ">" << word << "<" << std::endl;
		/* END of test */
		/* END of exc 11.4 */
		if (exclude.find(word) == exclude.end())
			++word_count[word];
	}
	for (const auto &w : word_count)
		std::cout << w.first << " occurs " << w.second << (w.second > 1 ? " times" : " time") << std::endl;

	std::map<std::string, size_t>::iterator ret = word_count.erase(word_count.begin());
	std::cout << ret->first << " : " << ret->second << std::endl;

	std::set<std::string>::iterator ret2 = exclude.erase(exclude.begin());
	std::cout << *ret2 << std::endl;


	return 0;
}