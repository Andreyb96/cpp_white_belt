#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::string MakeStringFromVector(std::vector<std::string> vec)
{
	std::string result;

	for (auto elem : vec)
	{
		result += elem + " ";
	}

	return result.substr(0, result.size() - 1);
}

int main()
{
	std::map <std::string, int> buses;
	int counter = 1;
	int n;
	std::cin >> n;

	for (auto i = 0; i < n; i++)
	{
		int numStops;
		std::cin >> numStops;
		std::vector<std::string> stops;
		std::string stop;

		for (auto j = 0; j < numStops; j++)
		{
			std::cin >> stop;
			stops.push_back(stop);
		}

		auto stopsList = MakeStringFromVector(stops);
		auto it = buses.find(stopsList);
		if (it == buses.end())
		{
			buses.insert({ stopsList, counter });
			std::cout << "New bus " << counter << std::endl;
			counter++;
		}
		else
		{
			std::cout << "Already exists for " << it->second << std::endl;
		}
	}

	return 0;
}