#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> const values { 1, 2, 3, -4, 5 };

	if (any_of(std::cbegin(values), std::cend(values),
		[](int val) -> bool { return val < 0; }))
	{
		std::cout << "Il y a des elements negatifs !" << std::endl;
	}
	else
	{
		std::cout << "Le tableau est entierement positif !" << std::endl;
	}

	return 0;
}