#include <iostream>
#include <exception>
#include <string>
#include <ctime>

#pragma warning(disable : 4996)

std::string AskTimeServer()
{
	time_t now = time(0);
	std::string dt = std::ctime(&now);
	return dt.substr(11, 8);
}

class TimeServer {
public:
	std::string GetCurrentTime()
	{
		last_fetched_time = AskTimeServer();
		return last_fetched_time;
	}

private:
	std::string last_fetched_time = "00:00:00";
};

int main()
{
	TimeServer ts;
	try {
		std::cout << ts.GetCurrentTime() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Exception got: " << e.what() << std::endl;
	}
}