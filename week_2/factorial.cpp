#include <iostream>
#include <cassert>

int Factorial(int number)
{
	if (number <= 1)
		return 1;
	return number * Factorial(number - 1);
}

int main()
{
	assert(Factorial(1) == 1);
	assert(Factorial(-2) == 1);
	assert(Factorial(4) == 24);

	return 0;
}