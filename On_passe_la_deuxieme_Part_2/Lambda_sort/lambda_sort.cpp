#include <iostream>
#include <algorithm>
#include <array>

int main()
{
	std::array<double, 4u> tableau{ 1, 3.1415, 2.1878, 1.5 };

	std::sort(std::begin(tableau), std::end(tableau),
		[](double a, double b) -> bool { return a > b; });

	for (double nombre : tableau)
	{
		std::cout << nombre << std::endl;
	}

	return 0;
}