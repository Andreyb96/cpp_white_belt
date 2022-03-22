#include <string>

struct Specialization
{
public:
	Specialization(const std::string& str) :
		_str(str)
	{}

	Specialization(const char* spec) = delete;

	std::string GetString() const
	{
		return _str;
	}
private:
	std::string _str;
};

struct Course
{
public:
	Course(const std::string& str) :
		_str(str)
	{}

	Course(const char* spec) = delete;

	std::string GetString() const
	{
		return _str;
	}
private:
	std::string _str;
};

struct Week
{
public:
	Week(const std::string& str) :
		_str(str)
	{}

	Week(const char* spec) = delete;

	std::string GetString() const
	{
		return _str;
	}
private:
	std::string _str;
};

struct LectureTitle {
public:
	LectureTitle(const Specialization& spec
		, const Course& course
		, const Week& week) :
		_specialization(spec.GetString())
		, _course(course.GetString())
		, _week(week.GetString())
	{}
private:
	std::string _specialization;
	std::string _course;
	std::string _week;
};

int main() {
	LectureTitle title(
		Specialization(std::string("C++")),
		Course(std::string("White belt")),
		Week(std::string("4th"))
	);

	return 0;
}
