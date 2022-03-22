#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>

int FindGCD(int first, int second)
{
	auto gcd = 1;

	for (int i = 1; i <= std::min(first, second); i++)
	{
		if (first%i == 0 && second%i == 0)
			gcd = i;
	}

	return gcd;
}

class Rational {
public:
	Rational() :
		_numerator(0),
		_denominator(1)
	{}

	Rational(const std::string& rationalValue) :
		Rational(std::stoi(rationalValue.substr(0, rationalValue.find('/'))), std::stoi(rationalValue.substr(rationalValue.find('/') + 1)))
	{}

	Rational(int numerator, int denominator)
		: _numerator(numerator)
		, _denominator(denominator)
	{
		if (denominator == 0)
		{
			throw std::invalid_argument("Denominator equals zero");
		}

		if (numerator < 0 && denominator < 0)
		{
			_numerator = std::abs(numerator);
			_denominator = std::abs(denominator);
		}
		else if (denominator < 0)
		{
			_denominator = std::abs(denominator);
			_numerator = -numerator;
		}
		else if (numerator == 0)
		{
			_denominator = 1;
		}

		auto gcd = FindGCD(std::abs(_numerator), _denominator);
		_numerator /= gcd;
		_denominator /= gcd;
	}

	int Numerator() const
	{
		return _numerator;
	}

	int Denominator() const
	{
		return _denominator;
	}

	void SetNumerator(int numerator)
	{
		_numerator = numerator;
	}

	void SetDenominator(int denominator)
	{
		_denominator = denominator;
	}

	std::string ToString()
	{
		return std::to_string(_numerator) + '/' + std::to_string(_denominator);
	}
private:
	int _numerator;
	int _denominator;
};

bool operator==(const Rational& lhs, const Rational& rhs)
{
	return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

Rational operator+(Rational lhs, const Rational& rhs)
{
	return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}
Rational operator-(Rational lhs, const Rational& rhs)
{
	return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator*(Rational lhs, const Rational& rhs)
{
	return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}
Rational operator/(Rational lhs, const Rational& rhs)
{
	if (rhs.Numerator() == 0)
	{
		throw std::domain_error("Devidends numerator equals zero");
	}

	return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

std::ostream& operator<<(std::ostream& out, const Rational& r)
{
	return out << r.Numerator() << '/' << r.Denominator();
}

std::istream& operator>>(std::istream& in, Rational& r)
{
	std::string inputStr;
	in >> inputStr;

	auto it = inputStr.find('/');

	if (inputStr.empty()
		|| it == std::string::npos
		|| it == 0
		|| it == inputStr.length() - 1
		|| std::count(inputStr.begin(), inputStr.end(), '/') > 1)
	{
		return in;
	}


	r = Rational(std::stoi(inputStr.substr(0, it)), std::stoi(inputStr.substr(it + 1)));
	return in;
}

std::string Calculate(const std::string& inputStr)
{
	auto arg1 = inputStr.substr(0, inputStr.find(" "));
	auto arg2 = inputStr.substr(inputStr.rfind(" ") + 1);

	auto value1 = Rational(arg1);
	auto value2 = Rational(arg2);

	if (inputStr.find("+") != std::string::npos)
	{
		return (value1 + value2).ToString();
	}
	else if (inputStr.find("-") != std::string::npos)
	{
		return (value1 - value2).ToString();
	}
	else if (inputStr.find("*") != std::string::npos)
	{
		return (value1 * value2).ToString();
	}
	else
	{
		return (value1 / value2).ToString();
	}

	return "";
}

int main()
{
	assert(Calculate("1/2 + 1/3") == "5/6");

	try
	{
		Calculate("1/2 + 5/0");
	}
	catch (std::invalid_argument& ex)
	{
		assert(ex.what() == std::string("Denominator equals zero"));
	}

	try
	{
		Calculate("4/5 / 0/8");
	}
	catch (std::domain_error& ex)
	{
		assert(ex.what() == std::string("Devidends numerator equals zero"));
	}

	return 0;
}