#include <cassert>
#include <vector>
#include <algorithm>
#include <string>

class SortedStrings {
public:
	void AddString(const std::string& s)
	{
		_strCollection.push_back(s);
		std::sort(_strCollection.begin(), _strCollection.end());
	}
	std::vector<std::string> GetSortedStrings()
	{
		return _strCollection;
	}
private:
	std::vector<std::string> _strCollection;
};

int main()
{
	SortedStrings strings;

	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	assert(strings.GetSortedStrings() == std::vector<std::string>({ "first", "second", "third" }));

	strings.AddString("second");
	assert(strings.GetSortedStrings() == std::vector<std::string>({ "first", "second", "second", "third" }));

	return 0;
}