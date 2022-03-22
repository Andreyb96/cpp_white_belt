#include <fstream>
#include <iostream>
#include <string>

int main() {
	std::string line;
	std::ifstream inFile("input.txt");
	std::ofstream outFile("output.txt");
	if (inFile.is_open() && outFile.is_open())
	{
		while (getline(inFile, line))
		{
			outFile << line << "\n";
		}
		inFile.close();
	}
	return 0;
}