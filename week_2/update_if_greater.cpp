#include <algorithm>
#include <cassert>

void UpdateIfGreater(int& first, int& second)
{
	if (first > second)
	{
		std::swap(first, second);
	}
}

int main()
{
	int a = 4;
	int b = 2;
	UpdateIfGreater(a, b);
	assert(a == 2 && b == 4);

	return 0;
}