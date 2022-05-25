#include <iostream>
#include <string>
#include <vector>

using namespace std::literals;

int main()
{
	std::vector<int> const nombres{ 1, 2, 3, 4, 5, 6, };
	std::vector<std::string> const mots{
		"Mot"s,
		"lettre"s,
		"test"s
	};

	auto lambda{ []<typename T>(std::vector<T> const& tableau) -> void
	{
		std::cout << "Le tableau donne contient " << std::size(tableau) << " elements.\n";
	} };

	lambda(nombres);
	lambda(mots);

	return 0;
}