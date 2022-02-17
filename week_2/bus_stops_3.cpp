#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <set>

int main()
{
	std::map <std::set<std::string>, int> buses;
	int counter = 1;
	int n;
	std::cin >> n;

	for (auto i = 0; i < n; i++)
	{
		int numStops;
		std::cin >> numStops;
		std::string stop;
		std::set<std::string> stops;

		for (auto j = 0; j < numStops; j++)
		{
			std::cin >> stop;
			stops.insert(stop);
		}

		auto it = buses.find(stops);
		if (it == buses.end())
		{
			buses.insert({ stops, counter });
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