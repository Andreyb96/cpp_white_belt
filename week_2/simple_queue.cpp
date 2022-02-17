#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Person
{
	Person(int place) : placeInQueue(place) {}
	Person(int place, bool isWorried) : placeInQueue(place), isWorried(isWorried) {}

	int placeInQueue;
	bool isWorried = false;
};

int main()
{
	std::vector<Person> simpleQueue;
	int counter = 1;
	std::vector<int> result;

	int n;
	std::cin >> n;

	for (auto i = 0; i < n; i++)
	{
		std::string operation;
		int num;
		std::cin >> operation;

		if (operation == "COME")
		{
			std::cin >> num;
			if (num > 0)
			{
				for (auto j = 0; j < num; j++)
				{
					simpleQueue.push_back(Person(counter));
					counter++;
				}
			}
			else
			{
				simpleQueue.erase(simpleQueue.begin(), simpleQueue.begin() + std::abs(num));
			}
		}
		else if (operation == "WORRY")
		{
			std::cin >> num;
			auto it = std::find_if(simpleQueue.begin(), simpleQueue.end(), [&num](Person v)
			{
				return v.placeInQueue == num;
			});

			it->isWorried = true;
		}
		else
		{
			auto worryCount = std::count_if(simpleQueue.begin(), simpleQueue.end(), [](Person i) {return i.isWorried; });
			result.push_back(worryCount);
		}
	}

	assert(result == std::vector<int>({ 1, 2 }));

	return 0;
}