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
	std::map <std::string, std::vector<std::string>> stops;
	std::map <std::string, std::vector<std::string>> buses;

	int n;
	std::cin >> n;

	for (auto i = 0; i < n; i++)
	{
		std::string task;
		std::cin >> task;

		if (task == "NEW_BUS")
		{
			std::string busNum;
			int stopsNum;
			std::cin >> busNum >> stopsNum;

			for (auto i = 0; i < stopsNum; i++)
			{
				std::string stop;
				std::cin >> stop;
				buses[busNum].push_back(stop);
				stops[stop].push_back(busNum);
			}
		}
		else if (task == "BUSES_FOR_STOP")
		{
			std::string stop;
			std::cin >> stop;

			auto it = stops.find(stop);

			if (it == stops.end())
			{
				std::cout << "No stop" << std::endl;
			}
			else
			{
				std::cout << MakeStringFromVector(it->second) << std::endl;
			}
		}
		else if (task == "STOPS_FOR_BUS")
		{
			std::string bus;
			std::cin >> bus;

			auto it = buses.find(bus);

			if (it == buses.end())
			{
				std::cout << "No bus" << std::endl;
			}
			else
			{
				for (auto elem : it->second)
				{
					std::cout << "Stop " << elem << ": " << MakeStringFromVector(stops.find(elem)->second) << std::endl;
				}
			}
		}
		else
		{
			if (buses.empty())
			{
				std::cout << "No buses" << std::endl;
			}
			else
			{
				for (auto bus : buses)
				{
					std::cout << "Bus " << bus.first << ": " << MakeStringFromVector(bus.second) << std::endl;
				}
			}
		}
	}

	return 0;
}