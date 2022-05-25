#include <iostream>
#include <vector>
#include <array>

int main()
{
	std::vector<int> dynamique{};
	std::array<int, 5> statique{};

	std::cout << "Taille actuelle de mon tableau dynamique : "
		<< std::size(dynamique) << " éléments.\n";

	std::cout << "Elements de mon tableau statique : \n";
	for (int const n : statique)
	{
		std::cout << n << ", ";
	}

	std::cout << '\n';

	dynamique.assign(10, 42);

	std::cout << "Taille actuelle de mon tableau dynamique : "
		<< std::size(dynamique) << " éléments.\n";

	std::cout << "Elements de mon tableau dynamique : \n";
	for (int const n : dynamique)
	{
		std::cout << n << ", ";
	}

	std::cout << '\n';

	statique.fill(5);

	std::cout << "Elements de mon tableau statique : \n";
	for (int const n : statique)
	{
		std::cout << n << ", ";
	}

	std::cout << '\n';

	return 0;
}