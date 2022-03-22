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

	Rational(int numerator, int denominator)
		: _numerator(numerator)
		, _denominator(denominator)
	{
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

int main()
{
	{
		const Rational r(3, 10);
		assert(r.Numerator() == 3 && r.Denominator() == 10);
	}

	{
		const Rational r(8, 12);
		assert(r.Numerator() == 2 && r.Denominator() == 3);
	}

	{
		const Rational r(-4, 6);
		assert(r.Numerator() == -2 && r.Denominator() == 3);
	}

	{
		const Rational r(4, -6);
		assert(r.Numerator() == -2 && r.Denominator() == 3);
	}

	{
		const Rational r(0, 15);
		assert(r.Numerator() == 0 && r.Denominator() == 1);
	}

	{
		const Rational r;
		assert(r.Numerator() == 0 && r.Denominator() == 1);
	}

	assert(Rational(4, 6) == Rational(2, 3));
	assert(Rational(2, 3) + Rational(4, 3) == Rational(2, 1));
	assert(Rational(5, 7) - Rational(2, 9) == Rational(31, 63));
	assert(Rational(2, 3) * Rational(4, 3) == Rational(8, 9));
	assert(Rational(5, 4) / Rational(15, 8) == Rational(2, 3));

	{
		std::ostringstream output;
		output << Rational(-6, 8);
		assert(output.str() == "-3/4");
	}

	{
		std::istringstream input("5/7");
		Rational r;
		input >> r;
		assert(r == Rational(5, 7));
	}

	{
		std::istringstream input("");
		Rational r;
		assert(!(input >> r));
	}

	{
		std::istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		assert(r1 == Rational(5, 7) && r2 == Rational(5, 4));

		input >> r1;
		input >> r2;
		assert(r1 == Rational(5, 7) && r2 == Rational(5, 4));
	}

	{
		std::istringstream input1("1*2"), input2("1/"), input3("/4");
		Rational r1, r2, r3;
		input1 >> r1;
		input2 >> r2;
		input3 >> r3;
		assert(r1 == Rational() && r2 == Rational() && r3 == Rational());
	}

	{
		std::istringstream input("2/4/6/8");
		Rational r1;
		input >> r1;
		assert(!(r1 == Rational(1, 2)));
	}

	return 0;
}