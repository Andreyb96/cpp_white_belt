#include <cassert>
#include <iostream>
#include <set>
#include <string>

int main()
{
	int n;
	std::cin >> n;
	std::set<std::string> lines;

	for (auto i = 0; i < n; i++)
	{
		std::string line;
		std::cin >> line;
		lines.insert(line);
	}

	std::cout << lines.size() << std::endl;

	return 0;
}