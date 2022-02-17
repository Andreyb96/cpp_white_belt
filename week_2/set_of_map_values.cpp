#include <cassert>
#include <iostream>
#include <set>
#include <string>
#include <map>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m)
{
	std::set<std::string> result;

	for (auto elem : m)
	{
		result.insert(elem.second);
	}

	return result;
}

int main()
{
	assert(BuildMapValuesSet({
	{1, "odd"},
	{2, "even"},
	{3, "odd"},
	{4, "even"},
	{5, "odd"}
		}) == std::set<std::string>({ "even", "odd" }));

	return 0;
}