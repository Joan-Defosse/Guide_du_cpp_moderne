#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

int main()
{
	std::vector<int> values { -2, 1, 78, -6, 0, 56, -46 };

	std::function<bool(int, int)> abs_less{ [](int a, int b) -> bool { return std::abs(a) < std::abs(b); } };

	std::sort(std::begin(values), std::end(values), abs_less);

	for (int val : values)
	{
		std::cout << std::abs(val) << std::endl;
	}

	return 0;
}