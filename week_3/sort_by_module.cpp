#include <cassert>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> SortByAbs(const std::string& inputStr)
{
	std::vector<int> result;
	auto copyStr = inputStr;
	auto pos = copyStr.find(' ');
	auto n = std::stoi(copyStr.substr(0, pos));
	copyStr = copyStr.substr(pos + 1);
	for (auto i = 0; i < n; i++)
	{
		pos = copyStr.find(' ');
		if (pos != std::string::npos)
		{
			result.push_back(std::stoi(copyStr.substr(0, pos)));
			copyStr = copyStr.substr(pos + 1);
		}
	}
	result.push_back(std::stoi(copyStr));
	std::sort(result.begin(), result.end(), [](int a, int b) {
		return std::abs(a) < std::abs(b);
	});
	return result;
}

int main()
{
	assert(SortByAbs("2 -4 3") == std::vector<int>({ 3, -4 }));
	assert(SortByAbs("3 1 -3 2") == std::vector<int>({ 1, 2, -3 }));
	return 0;
}