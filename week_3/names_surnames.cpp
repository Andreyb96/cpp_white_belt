#include <cassert>
#include <algorithm>
#include <string>
#include <map>

class Person {
public:
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
private:
	std::map <int, std::string> _firstNames;
	std::map <int, std::string> _lastNames;
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	assert(person.GetFullName(1900) == "Incognito");
	assert(person.GetFullName(1965) == "Polina with unknown last name");
	assert(person.GetFullName(1990) == "Polina Sergeeva");

	person.ChangeFirstName(1970, "Appolinaria");
	assert(person.GetFullName(1969) == "Polina Sergeeva");
	assert(person.GetFullName(1970) == "Appolinaria Sergeeva");

	person.ChangeLastName(1968, "Volkova");
	assert(person.GetFullName(1969) == "Polina Volkova");
	assert(person.GetFullName(1970) == "Appolinaria Volkova");

	return 0;
}
