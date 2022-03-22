#include <cassert>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

std::vector<std::string> SortNoRegister(const std::string& inputStr)
{
	std::vector<std::string> result;
	auto copyStr = inputStr;
	auto pos = copyStr.find(' ');
	auto n = std::stoi(copyStr.substr(0, pos));
	copyStr = copyStr.substr(pos + 1);
	for (auto i = 0; i < n; i++)
	{
		pos = copyStr.find(' ');
		if (pos != std::string::npos)
		{
			result.push_back(copyStr.substr(0, pos));
			copyStr = copyStr.substr(pos + 1);
		}
	}
	result.push_back(copyStr);
	std::sort(result.begin(), result.end(), [](std::string a, std::string b) {
		std::for_each(a.begin(), a.end(), [](char & c) {
			c = ::tolower(c);
		});
		std::for_each(b.begin(), b.end(), [](char & c) {
			c = ::tolower(c);
		});
		return a < b;

	});
	return result;
}

int main()
{
	assert(SortNoRegister("2 qq Aa") == std::vector<std::string>({ "Aa", "qq" }));
	assert(SortNoRegister("3 aA Cc bb") == std::vector<std::string>({ "aA", "bb", "Cc" }));
	return 0;
}