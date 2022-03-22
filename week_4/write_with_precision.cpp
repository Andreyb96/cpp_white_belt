#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

int main() {
	std::string line;
	std::ifstream inFile("input_2.txt");
	std::cout.precision(3);
	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			std::cout << std::fixed << std::stod(line) << std::endl;
		}
		inFile.close();
	}
	return 0;
}