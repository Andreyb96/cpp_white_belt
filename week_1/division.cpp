#include <iostream>

int main()
{
	int a, b;
	std::cin >> a >> b;

	if (b == 0)
		std::cout << "Impossible";

	std::cout << a / b;

	return 0;
}