#include <iostream>
#include <string>

int main()
{
	int const entier{ -5 };
	double const flottant{ 3.1415926535 };

	std::string affichage{ "Voici des nombres : " };
	affichage += std::to_string(entier) + ", " + std::to_string(flottant);
	std::cout << affichage << std::endl;

	int const nombre_entier{ std::stoi("-8") };
	double const nombre_flottant{ std::stod("2.71878") };

	std::cout << nombre_entier + nombre_flottant << std::endl;

	return 0;
}