#include <iostream>
#include <functional>
#include <numeric>
#include <vector>

int main()
{
	std::vector<int> const nombres{ 1, 2, 3, 4, 5, 10 };

	int somme{ std::accumulate(std::cbegin(nombres), std::cend(nombres), 0) };

	int produit{ std::accumulate(std::cbegin(nombres), std::cend(nombres), 1, std::multiplies<int>{}) };

	std::cout << somme << std::endl;

	std::cout << produit << std::endl;

	return 0;
}