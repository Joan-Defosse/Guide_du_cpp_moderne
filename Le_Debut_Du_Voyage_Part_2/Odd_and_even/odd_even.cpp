#include <iostream>
#include <vector>

int main()
{
	std::vector<int> const entiers{ 15, -5, 98, 758, 101, 97 };
	std::vector<int> pairs{};
	std::vector<int> impairs{};

	for (int const i : entiers)
	{
		if (i % 2 == 0)
		{
			pairs.push_back(i);
		}
		else
		{
			impairs.push_back(i);
		}
	}

	std::cout << "Les pairs sont :\n";
	for (int i : pairs)
	{
		std::cout << i << std::endl;
	}

	std::cout << "Les impairs sont :\n";
	for (int i : impairs)
	{
		std::cout << i << std::endl;
	}

	return 0;
}