#include <cassert>
#include <iostream>
#include <map>
#include <string>

std::map <char, int> BuildMap(const std::string& word)
{
	std::map <char, int> result;
	for (auto elem : word)
	{
		if (result.find(elem) == result.end())
		{
			result.insert({ elem, 1 });
		}
		else
		{
			result[elem]++;
		}
	}
	return result;
}

int main()
{
	std::map <std::string, std::string> capitals;

	int n;
	std::cin >> n;

	for (auto i = 0; i < n; i++)
	{
		std::string task;
		std::cin >> task;

		if (task == "CHANGE_CAPITAL")
		{
			std::string country;
			std::string newCapital;
			std::cin >> country >> newCapital;

			if (capitals.find(country) == capitals.end())
			{
				capitals.insert({ country, newCapital });
				std::cout << "Introduce new country " + country + " with capital " + newCapital << std::endl;
			}
			else
			{
				if (capitals[country] == newCapital)
				{
					std::cout << "Country " + country + " hasn't changed its capital" << std::endl;
				}
				else
				{
					std::cout << "Country " + country + " has changed its capital from " + capitals[country] + " to " + newCapital << std::endl;
					capitals[country] = newCapital;
				}
			}
		}
		else if (task == "RENAME")
		{
			std::string oldCountryName;
			std::string newCountryName;
			std::cin >> oldCountryName >> newCountryName;

			if (oldCountryName == newCountryName
				|| capitals.find(oldCountryName) == capitals.end()
				|| capitals.find(newCountryName) != capitals.end())
			{
				std::cout << "Incorrect rename, skip" << std::endl;
			}
			else
			{
				std::cout << "Country " + oldCountryName + " with capital " + capitals[oldCountryName] + " has been renamed to " + newCountryName << std::endl;
				capitals[newCountryName] = capitals[oldCountryName];
				capitals.erase(capitals.find(oldCountryName));
			}
		}
		else if (task == "ABOUT")
		{
			std::string country;
			std::cin >> country;
			if (capitals.find(country) == capitals.end())
			{
				std::cout << "Country " + country + " doesn't exist" << std::endl;
			}
			else
			{
				std::cout << "Country " + country + " has capital " + capitals[country] << std::endl;
			}
		}
		else
		{
			if (capitals.empty())
			{
				std::cout << "There are no countries in the world" << std::endl;
			}
			else
			{
				for (auto elem : capitals)
				{
					std::cout << elem.first + "/" + elem.second << std::endl;
				}
			}
		}
	}

	return 0;
}