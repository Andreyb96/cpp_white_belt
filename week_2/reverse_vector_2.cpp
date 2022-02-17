#include <cassert>
#include <vector>

std::vector<int> Reversed(const std::vector<int>& vec)
{
	return std::vector<int>(vec.rbegin(), vec.rend());
}

int main()
{
	std::vector<int> numbers = { 1, 5, 3, 4, 2 };
	assert(Reversed(numbers) == std::vector<int>({ 2, 4, 3, 5, 1 }));

	return 0;
}