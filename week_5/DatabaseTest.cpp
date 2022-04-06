#include "test_framework.h"
#include "Database.h"

#include <algorithm>
#include <cctype>

constexpr auto ADD_COMMAND = "Add";
constexpr auto FIND_COMMAND = "Find";
constexpr auto DELETE_COMMAND = "Del";
constexpr auto PRINT_COMMAND = "Print";

constexpr auto WRONG_DATE_FMT = "Wrong date format";

namespace
{
	void DeleteSpaces(std::string& string)
	{
		size_t index;
		size_t strBegin = string.find_first_not_of(' ');
		size_t strEnd = string.find_last_not_of(' ');
		while (((index = string.find(' ')) != std::string::npos) && (index < strBegin))
			string.erase(index, 1);
		while ((index = string.find(' ', strEnd)) != std::string::npos)
			string.erase(index, 1);
	}

	bool IsNumber(const std::string& s)
	{
		auto it = s.begin();
		while (it != s.end() && std::isdigit(*it)) ++it;
		return !s.empty() && it == s.end();
	}

	bool CheckMonth(int month)
	{
		if (month >= 1 && month <= 12)
		{
			return true;
		}

		std::cout << "Month value is invalid: " << month << std::endl;
		return false;
	}

	bool CheckDay(int day)
	{
		if (day >= 1 && day <= 31)
		{
			return true;
		}

		std::cout << "Day value is invalid: " << day << std::endl;
		return false;
	}

	bool CheckDate(const std::string& date)
	{
		if (std::count(date.begin(), date.end(), HYPHEN) != 2)
		{
			std::cout << WRONG_DATE_FMT << std::endl;
			return false;
		}

		auto dateStruct = CreateDate(date);

		if (!IsNumber(dateStruct.year)
			|| !IsNumber(dateStruct.month)
			|| !IsNumber(dateStruct.day))
		{
			std::cout << WRONG_DATE_FMT << std::endl;
			return false;
		}

		return CheckMonth(std::stoi(dateStruct.month)) && CheckDay(std::stoi(dateStruct.day));
	}
} // anonymos

int main()
{
	Database db;
	while (true)
	{
		std::string command;
		std::cin >> command;

		if (command == ADD_COMMAND)
		{
			std::string date, event;
			std::cin >> date >> event;
			if (!CheckDate(date))
			{
				break;
			}

			db.AddEvent(date, event);
			continue;
		}

		if (command == FIND_COMMAND)
		{
			std::string date;
			std::cin >> date;
			
			if (!CheckDate(date))
			{
				break;
			}
			
			db.Find(date);
			continue;
		}

		if (command == DELETE_COMMAND)
		{
			std::string inputStr;
			std::getline(std::cin, inputStr);
			DeleteSpaces(inputStr);

			auto it = inputStr.find(' ');
			if (it == std::string::npos)
			{
				if (!CheckDate(inputStr))
				{
					break;
				}
				db.DeleteAllEventsForDate(inputStr);
				continue;
			}

			auto date = inputStr.substr(0, it);
			auto event = inputStr.substr(it + 1);
			
			if (!CheckDate(date))
			{
				break;
			}
			db.DeleteEvent(date, event);
			continue;
		}

		if (command == PRINT_COMMAND)
		{
			db.PrintEvents();
			continue;
		}

		std::cout << "Unknown command" << std::endl;
	}
	
}