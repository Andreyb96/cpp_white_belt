#include <cassert>
#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> AverageTemp(const std::vector<int>& samples, int n, int& k)
{
	std::vector<int> result;
	int idx = 0;
	double averageTemp = std::accumulate(samples.begin(), samples.end(), 0) / n;
	for (auto elem : samples)
	{
		if (elem > averageTemp)
		{
			k++;
			result.push_back(idx);
		}
		idx++;
	}
	return result;
}

int main()
{
	std::vector<int> v;
	int n;
	std::cin >> n;

	for (auto i = 0; i < n; i++)
	{
		int a;
		std::cin >> a;
		v.push_back(a);
	}

	int k = 0;
	assert(AverageTemp(v, n, k) == std::vector<int>({ 0, 1, 4 }));
	assert(k == 3);

	return 0;
}