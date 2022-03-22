#include <fstream>
#include <iostream>
#include <string>

int main() {
	std::string line;
	std::ifstream myfile("input.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			std::cout << line << std::endl;
		}
		myfile.close();
	}
	return 0;
}