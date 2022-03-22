#include <cassert>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

std::vector<int> Separate(const std::string& s)
{
	std::vector<int> line;
	std::string token;
	std::istringstream iss(s);
	while (std::getline(iss, token, ','))
		line.push_back(std::stoi(token));
	return line;
}

void PrettyPrint(const std::string& line)
{
	auto v = Separate(line);

	for (auto elem : v)
	{
		std::cout << std::left << std::setw(10);
		std::cout << elem;
	}
	std::cout << std::endl;
}

int main()
{
	std::string line;
	std::ifstream myfile("input.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			auto spaceIt = line.find(' ');
			if (spaceIt != std::string::npos)
			{
				continue;
			}
			else
			{
				PrettyPrint(line);
			}
		}
		myfile.close();
	}

	return 0;
}