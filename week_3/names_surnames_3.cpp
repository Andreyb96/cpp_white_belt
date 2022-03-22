#include <cassert>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

namespace
{
	std::string MakeNameString(const std::vector<std::string>& names)
	{
		std::string result;

		for (auto i = 0; i < names.size(); i++)
		{
			if (i == 0)
			{
				result += names[i];
			}
			else if (i == 1)
			{
				result += " (" + names[i];
			}
			else
			{
				result += ", " + names[i];
			}
		}

		if (result.find("(") != std::string::npos)
		{
			result += ")";
		}

		return result;
	}

	std::string MakeNameHistoryString(const std::vector<std::string>& firstNames,
		const std::vector<std::string>& lastNames)
	{
		if (firstNames.empty() && lastNames.empty())
		{
			return "No person";
		}

		if (firstNames.empty())
		{
			return MakeNameString(lastNames) + " with unknown first name";
		}

		if (lastNames.empty())
		{
			return MakeNameString(firstNames) + " with unknown last name";
		}

		return MakeNameString(firstNames) + " " + MakeNameString(lastNames);
	}
} //anonymos

class Person {
public:
	Person(const std::string& firstName, const std::string& lastName, int year) :
		_firstNames{ {year, firstName} }
		, _lastNames{ { year, lastName } }
	{

	}

	void ChangeFirstName(int year, const std::string& first_name)
	{
		auto it = _firstNames.find(year);
		if (it == _firstNames.end())
		{
			_firstNames.insert({ year, first_name });
		}
		else
		{
			it->second = first_name;
		}
	}

	void ChangeLastName(int year, const std::string& last_name)
	{
		auto it = _lastNames.find(year);
		if (it == _lastNames.end())
		{
			_lastNames.insert({ year, last_name });
		}
		else
		{
			it->second = last_name;
		}
	}

	std::string GetFullName(int year)
	{
		if (_lastNames.begin()->first > year && _firstNames.begin()->first > year)
		{
			return "Incognito";
		}

		std::string firstPart;
		std::string secondPart;

		auto firstNameIt = _firstNames.begin();
		auto lastNameIt = _lastNames.begin();

		if (_lastNames.begin()->first > year)
		{
			while (firstNameIt->first <= year)
			{
				firstPart = firstNameIt->second;
				firstNameIt++;
				if (firstNameIt == _firstNames.end())
				{
					break;
				}
			}

			secondPart = "with unknown last name";
		}
		else if (_firstNames.begin()->first > year)
		{
			while (lastNameIt->first <= year)
			{
				firstPart = lastNameIt->second;
				lastNameIt++;
				if (lastNameIt == _lastNames.end())
				{
					break;
				}
			}

			secondPart = "with unknown first name";
		}
		else
		{
			while (firstNameIt->first <= year)
			{
				firstPart = firstNameIt->second;
				firstNameIt++;
				if (firstNameIt == _firstNames.end())
				{
					break;
				}
			}

			while (lastNameIt->first <= year)
			{
				secondPart = lastNameIt->second;
				lastNameIt++;
				if (lastNameIt == _lastNames.end())
				{
					break;
				}
			}
		}

		return firstPart + " " + secondPart;
	}

	std::string GetFullNameWithHistory(int year)
	{
		auto firstNamesIt = _firstNames.rbegin();
		std::vector<std::string> firstNamesHistory;

		while (firstNamesIt != _firstNames.rend())
		{
			if (firstNamesIt->first <= year &&
				std::find(firstNamesHistory.begin(), firstNamesHistory.end(), firstNamesIt->second) == firstNamesHistory.end())
			{
				firstNamesHistory.push_back(firstNamesIt->second);
			}
			firstNamesIt++;
		}

		auto lastNamesIt = _lastNames.rbegin();
		std::vector<std::string> lastNamesHistory;

		while (lastNamesIt != _lastNames.rend())
		{
			if (lastNamesIt->first <= year &&
				std::find(lastNamesHistory.begin(), lastNamesHistory.end(), lastNamesIt->second) == lastNamesHistory.end())
			{
				lastNamesHistory.push_back(lastNamesIt->second);
			}
			lastNamesIt++;
		}
		return MakeNameHistoryString(firstNamesHistory, lastNamesHistory);
	}

private:
	std::map <int, std::string> _firstNames;
	std::map <int, std::string> _lastNames;
};

int main() {
	Person person("Polina", "Sergeeva", 1960);
	assert(person.GetFullNameWithHistory(1959) == "No person");
	assert(person.GetFullNameWithHistory(1960) == "Polina Sergeeva");

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	assert(person.GetFullNameWithHistory(1965) == "Appolinaria (Polina) Sergeeva");
	assert(person.GetFullNameWithHistory(1967) == "Appolinaria (Polina) Ivanova (Sergeeva)");

	return 0;
}
