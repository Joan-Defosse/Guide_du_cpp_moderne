#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

int main()
{
	std::vector<int> tableau{ -8, 5, 45, -945 };

	// ou bien : std::greater<int> foncteur {};

	std::sort(std::begin(tableau), std::end(tableau), std::greater<int> {});

	// ou bien : std::sort(std::begin(tableau), std::end(tableau), foncteur);

	for (int i : tableau)
	{
		std::cout << i << ", ";
	}

	std::cout << std::endl;

	return 0;
}