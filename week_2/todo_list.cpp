#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct ToDoList
{
	ToDoList()
	{
		for (auto i = 1; i <= daysInMonth[currentMonthIdx]; i++)
		{
			taskList.insert({ i, {} });
		}
	}

	void AddTask(int dayIdx, const std::string& taskName)
	{
		taskList[dayIdx].push_back(taskName);
	}

	std::string PrintTasksForDay(int dayIdx)
	{
		std::string printStr = std::to_string(taskList[dayIdx].size());
		for (auto elem : taskList[dayIdx])
		{
			printStr += " " + elem;
		}

		return printStr;
	}

	void Update()
	{
		for (auto i = daysInMonth[currentMonthIdx + 1] + 1; i <= daysInMonth[currentMonthIdx]; i++)
		{
			taskList[daysInMonth[currentMonthIdx + 1]].insert(taskList[daysInMonth[currentMonthIdx + 1]].end(), taskList[i].begin(), taskList[i].end());
			taskList.erase(taskList.find(i));
		}

		currentMonthIdx++;
	}

	std::map <int, std::vector<std::string>> taskList;
	int currentMonthIdx = 1;

	std::map<int, int> daysInMonth = {
	{1, 31},
	{2, 28},
	{3, 31},
	{4, 30},
	{5, 31},
	{6, 30},
	{7, 31},
	{8, 31},
	{9, 30},
	{10, 31},
	{11, 30},
	{12, 31}
	};
};

int main()
{
	auto taskList = ToDoList();

	int counter = 1;
	int n;
	std::cin >> n;

	for (auto i = 0; i < n; i++)
	{
		std::string operation;
		std::cin >> operation;

		if (operation == "ADD")
		{
			int dayIdx;
			std::string taskName;
			std::cin >> dayIdx >> taskName;
			taskList.AddTask(dayIdx, taskName);
		}
		else if (operation == "NEXT")
		{
			taskList.Update();
		}
		else
		{
			int dayIdx;
			std::cin >> dayIdx;

			switch (counter)
			{
			case 1:
				assert(taskList.PrintTasksForDay(dayIdx) == "1 Salary");
				break;
			case 2:
			case 5:
				assert(taskList.PrintTasksForDay(dayIdx) == "2 WalkPreparations Walk");
				break;
			case 3:
			case 4:
				assert(taskList.PrintTasksForDay(dayIdx) == "0");
				break;
			case 6:
				assert(taskList.PrintTasksForDay(dayIdx) == "3 WalkPreparations Walk Payment");
				break;
			}

			counter++;
		}
	}

	return 0;
}