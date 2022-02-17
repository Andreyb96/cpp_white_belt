#include <iostream>
#include <cassert>
#include <string>
#include <vector>

bool IsPalindrom(const std::string& str)
{
	return str == std::string(str.rbegin(), str.rend());
}

std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLength)
{
	std::vector<std::string> result;
	for (auto elem : words)
	{
		if (elem.length() >= minLength && IsPalindrom(elem))
		{
			result.push_back(elem);
		}
	}
	return result;
}

int main()
{
	assert(PalindromFilter({ "abacaba", "aba" }, 5) == std::vector<std::string>({ "abacaba" }));
	assert(PalindromFilter({ "abacaba", "aba" }, 2) == std::vector<std::string>({ "abacaba", "aba" }));
	assert(PalindromFilter({ "weew", "bro", "code" }, 4) == std::vector<std::string>({ "weew" }));

	return 0;
}