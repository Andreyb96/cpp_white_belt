#include <cassert>
#include <vector>

void Reverse(std::vector<int>& vec)
{
	vec = std::vector<int>(vec.rbegin(), vec.rend());
}

int main()
{
	std::vector<int> numbers = { 1, 5, 3, 4, 2 };
	Reverse(numbers);
	assert(numbers == std::vector<int>({ 2, 4, 3, 5, 1 }));

	return 0;
}