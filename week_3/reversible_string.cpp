#include <cassert>
#include <algorithm>
#include <string>

class ReversibleString
{
public:
	ReversibleString() :
		_str()
	{}

	ReversibleString(const std::string& str) :
		_str(str)
	{}

	const ReversibleString& operator=(const ReversibleString& revStr)
	{
		auto result = ReversibleString(revStr.ToString());
		return result;
	}

	void Reverse()
	{
		std::reverse(_str.begin(), _str.end());
	}

	std::string ToString() const
	{
		return _str;
	}
private:
	std::string _str;
};

int main() {
	ReversibleString s("live");
	s.Reverse();
	assert(s.ToString() == "evil");

	s.Reverse();
	const ReversibleString& s_ref = s;
	std::string tmp = s_ref.ToString();
	assert(tmp == "live");

	ReversibleString empty;
	assert(empty.ToString() == "");

	return 0;
}