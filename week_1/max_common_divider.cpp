#include <iostream>
#include <algorithm>

int main()
{
	int a, b;
	std::cin >> a >> b;

	auto nod = 1;

	for (int i = 1; i <= std::min(a, b); i++)
	{
		if (a%i == 0 && b%i == 0)
			nod = i;
	}

	std::cout << nod;

	return 0;
}