#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	int input;
	std::vector<int> nums;

	while (std::cin >> input)
	{
		nums.push_back(input);
	}

	std::sort(nums.begin(), nums.end(), [](int i, int j) {
		return std::abs(i) < std::abs(j);
	});

	for (auto elem : nums)
	{
		std::cout << elem << std::endl;
	}

	return 0;
}