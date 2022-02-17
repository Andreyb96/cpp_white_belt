#include <iostream>
#include <cassert>
#include <string>

bool IsPalindrom(const std::string& str)
{
	return str == std::string(str.rbegin(), str.rend());
}

int main()
{
	assert(IsPalindrom("madam"));
	assert(!IsPalindrom("gentleman"));
	assert(IsPalindrom("X"));

	return 0;
}