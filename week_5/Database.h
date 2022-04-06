#include <map>
#include <string>
#include <set>

constexpr auto HYPHEN = '-';

struct Date
{
	std::string year;
	std::string month;
	std::string day;

	size_t firstHyphenPos;
	size_t secondHyphenPos;
};

Date CreateDate(const std::string& date);

class Database
{
public:
	void AddEvent(const std::string& date, const std::string& event);
	void DeleteEvent(const std::string& date, const std::string& event);
	void DeleteAllEventsForDate(const std::string& date);
	void Find(const std::string& date);
	void PrintEvents();
private:
	std::map<std::string, std::set<std::string>> _events;
};