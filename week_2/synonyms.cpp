#include <cassert>
#include <iostream>
#include <set>
#include <string>
#include <map>

int main()
{
	std::map <std::string, std::set<std::string>> synonyms;
	int n;
	std::cin >> n;
	for (auto i = 0; i < n; i++)
	{
		std::string command;
		std::cin >> command;

		if (command == "ADD")
		{
			std::string syn1, syn2;
			std::cin >> syn1 >> syn2;
			auto it1 = synonyms.find(syn1);
			if (it1 == synonyms.end())
			{
				synonyms.insert({ syn1, {syn2} });
			}
			else
			{
				it1->second.insert(syn2);
			}
			auto it2 = synonyms.find(syn2);
			if (it2 == synonyms.end())
			{
				synonyms.insert({ syn2, {syn1} });
			}
			else
			{
				it2->second.insert(syn1);
			}
		}
		else if (command == "CHECK")
		{
			std::string syn1, syn2;
			std::cin >> syn1 >> syn2;

			auto it = synonyms.find(syn1);
			if (it != synonyms.end() && it->second.find(syn2) != it->second.end())
			{
				std::cout << "YES" << std::endl;
			}
			else
			{
				std::cout << "NO" << std::endl;
			}
		}
		else if (command == "COUNT")
		{
			std::string word;
			std::cin >> word;
			auto it = synonyms.find(word);
			if (it == synonyms.end())
			{
				std::cout << 0 << std::endl;
			}
			else
			{
				std::cout << it->second.size() << std::endl;
			}
		}
	}

	return 0;
}