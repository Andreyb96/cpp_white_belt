#include <iostream>
#include <string>

constexpr auto SEARCH_SUBSTR = 'f';

int main()
{
	std::string inputStr;
	std::cin >> inputStr;

	auto foundFirst = inputStr.find(SEARCH_SUBSTR);
	if (foundFirst == std::string::npos)
		std::cout << -2;

	auto foundSecond = inputStr.find(SEARCH_SUBSTR, foundFirst + 1);
	if (foundSecond == std::string::npos)
		std::cout << -1;
	else
		std::cout << foundSecond;

	return 0;
}