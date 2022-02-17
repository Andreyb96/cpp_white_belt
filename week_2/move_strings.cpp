#include <cassert>
#include <vector>

void MoveStrings(std::vector<std::string>& src, std::vector<std::string>& dst)
{
	dst.insert(dst.end(), src.begin(), src.end());
	src.clear();
}

int main()
{
	std::vector<std::string> source = { "a", "b", "c" };
	std::vector<std::string> destination = { "z" };
	MoveStrings(source, destination);
	assert(source.empty());
	assert(destination == std::vector<std::string>({ "z", "a", "b", "c" }));

	return 0;
}