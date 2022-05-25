#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
	auto enumeration{ [](auto const& parametre) -> void
	{
		std::cout << "Parametre recu : " << parametre << std::endl;
	} };

	std::vector<std::string> const chaines{
		"Un mot",
		"Autre chose",
		"Du blabla",
		"Du texte",
		"Des lettres"
	};
	
	std::for_each(std::begin(chaines), std::end(chaines), enumeration);

	std::vector<int> const nombres{ 1, 5, -7, 67, -4454, 7888 };

	std::for_each(std::begin(nombres), std::end(nombres), enumeration);

	return 0;
}