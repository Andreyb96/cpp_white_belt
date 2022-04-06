#include "Database.h"

#include <iostream>

constexpr auto ZERO = '0';
constexpr auto NUM_YEAR_DIGITS = 4;
constexpr auto NUM_MONTH_DIGITS = 2;
constexpr auto NUM_DAY_DIGITS = 2;

namespace
{
	std::string CreateDateString(const std::string& date)
	{
		std::string result;
		auto dateStruct = CreateDate(date);

		result += std::string((NUM_YEAR_DIGITS - dateStruct.firstHyphenPos), ZERO) + dateStruct.year;
		result += HYPHEN;
		result += std::string((NUM_MONTH_DIGITS - (dateStruct.secondHyphenPos - dateStruct.firstHyphenPos - 1)), ZERO) + dateStruct.month;
		result += HYPHEN;
		result += std::string((NUM_DAY_DIGITS - (date.size() - dateStruct.secondHyphenPos - 1)), ZERO) + dateStruct.day;

		return result;
	}
} //anonymos

Date CreateDate(const std::string& date)
{
	auto pos1 = date.find_first_of(HYPHEN);
	auto pos2 = date.find_last_of(HYPHEN);

	auto year = date.substr(0, pos1);
	auto month = date.substr(pos1 + 1, pos2 - pos1 - 1);
	auto day = date.substr(pos2 + 1);

	return Date({ year, month, day, pos1, pos2 });
}

void Database::AddEvent(const std::string& date, const std::string& event)
{
	auto it = _events.find(date);
	if (it == _events.end())
	{
		_events.insert({ date, {event} });
		return;
	}
	it->second.insert(event);
}

void Database::DeleteEvent(const std::string& date, const std::string& event)
{
	auto mapIt = _events.find(date);
	if (mapIt == _events.end())
	{
		std::cout << "Event not found" << std::endl;
		return;
	}

	auto& dateSet = mapIt->second;
	auto setIt = dateSet.find(event);

	if (setIt == dateSet.end())
	{
		std::cout << "Event not found" << std::endl;
		return;
	}

	dateSet.erase(setIt);
	std::cout << "Deleted successfully" << std::endl;
}

void Database::DeleteAllEventsForDate(const std::string& date)
{
	auto mapIt = _events.find(date);
	if (mapIt == _events.end())
	{
		std::cout << "Deleted 0 events" << std::endl;
		return;
	}

	auto n = mapIt->second.size();
	_events.erase(mapIt);
	std::cout << "Deleted " << n << " events" << std::endl;
}

void Database::Find(const std::string& date)
{
	auto mapIt = _events.find(date);
	if (mapIt == _events.end())
	{
		std::cout << "Event not found" << std::endl;
		return;
	}

	for (const auto& elem : mapIt->second)
	{
		std::cout << elem << std::endl;
	}
}

void Database::PrintEvents()
{
	for (auto datePair : _events)
	{
		auto date = CreateDateString(datePair.first);
		for (auto event : datePair.second)
		{
			std::cout << date << " " << event << std::endl;
		}
	}
}