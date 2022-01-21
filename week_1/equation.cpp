#include <iostream>
#include <cmath>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	auto d = pow(b, 2) - 4 * a*c;

	if (a == 0)
	{
		std::cout << static_cast<double>(-c) / static_cast<double>(b);
	}
	else
	{
		auto x1 = (-1 * b - sqrt(d)) / (2 * a);

		if (d == 0.0)
		{
			std::cout << x1;
		}
		else if (d > 0)
		{
			auto x2 = (-1 * b + sqrt(d)) / (2 * a);
			std::cout << x1 << x2;
		}
	}

	return 0;
}