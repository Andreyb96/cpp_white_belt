#include <cassert>
#include <iostream>
#include <map>
#include <string>

std::map <char, int> BuildMap(const std::string& word)
{
	std::map <char, int> result;
	for (auto elem : word)
	{
		if (result.find(elem) == result.end())
		{
			result.insert({ elem, 1 });
		}
		else
		{
			result[elem]++;
		}
	}
	return result;
}

int main()
{
	int n;
	std::cin >> n;
	std::string firstWord;
	std::string secondWord;

	for (auto i = 0; i < n; i++)
	{
		std::cin >> firstWord >> secondWord;
		switch (i)
		{
		case 0:
		case 2:
			assert(BuildMap(firstWord) == BuildMap(secondWord));
			break;
		case 1:
			assert(BuildMap(firstWord) != BuildMap(secondWord));
			break;
		}
	}

	return 0;
}