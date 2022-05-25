#include <iostream>

int gcd(int a, int b)
{
	int r{ a % b };

	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}

	return b;
}

int sum(int n)
{
	return (n * (n + 1)) / 2;
}

bool x_or(bool a, bool b)
{
	return (a && !b) || (!a && b);
}

int main()
{
	int const a{ 845 };
	int const b{ 314 };

	std::cout << "The gcd of " << a << " and " << b << " is " << gcd(a, b) << std::endl;

	std::cout << "The sum of every integer from 1 to 25 is " << sum(25) << std::endl;

	std::cout << std::boolalpha << "XOR(true, false) is " << x_or(true, false) << std::endl;

	return 0;
}