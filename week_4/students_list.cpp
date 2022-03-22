#include <cassert>
#include <string>
#include <vector>
#include <iostream>

struct Student
{
	std::string GetName()
	{
		return name;
	}

	std::string GetDate()
	{
		return date;
	}

	std::string name;
	std::string date;
};

int main()
{
	std::vector<Student> students;
	int n;
	std::string name;
	std::string surname;
	int day;
	int month;
	int year;
	std::cin >> n;

	for (auto i = 0; i < n; i++)
	{
		std::cin >> name >> surname >> day >> month >> year;
		students.push_back({ name + ' ' + surname,
			std::to_string(day) + '.' + std::to_string(month) + '.' + std::to_string(year) });
	}

	int m;
	std::cin >> m;

	for (auto i = 0; i < m; i++)
	{
		std::string request;
		int idx;
		std::cin >> request >> idx;
		if (request == "name")
		{
			std::cout << students[idx - 1].GetName() << std::endl;;
		}
		else if (request == "date")
		{
			std::cout << students[idx - 1].GetDate() << std::endl;;
		}
		else
		{
			std::cout << "bad request" << std::endl;;
		}
	}

	return 0;
}