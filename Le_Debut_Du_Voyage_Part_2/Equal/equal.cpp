#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> premier{ 1, 2, 3, 4, 5 };
	std::vector<int> deuxieme{ 1, 2, 3, 4 };
	std::vector<int> troisieme{ 1, 2, 3, 4, 5 };

	std::cout << std::boolalpha;

	std::cout << std::equal(std::begin(premier), std::end(premier), std::begin(deuxieme), std::end(deuxieme)) << std::endl;

	std::cout << std::equal(std::begin(premier), std::end(premier), std::begin(troisieme), std::end(troisieme)) << std::endl;

	return 0;
}