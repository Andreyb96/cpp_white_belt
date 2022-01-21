#include <iostream>
#include <string>

int main()
{
	int a;
	std::cin >> a;
	std::string outStr;

	while (a > 1)
	{
		outStr += std::to_string(a % 2);
		a /= 2;
	}

	outStr += std::to_string(a);
	std::cout << std::string(outStr.rbegin(), outStr.rend());

	return 0;
}