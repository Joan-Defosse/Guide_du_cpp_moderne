#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

int main()
{
	char const lettre{ 'A' };

	std::cout << "Est-ce que " << lettre << " est une minuscule ? " << islower(lettre) << std::endl;
	std::cout << "Est-ce que " << lettre << " est une majuscule ? " << isupper(lettre) << std::endl;
	std::cout << "Est-ce que " << lettre << " est un chiffre ? " << isdigit(lettre) << std::endl;

	char const chiffre{ '7' };

	std::cout << "Est-ce que " << chiffre << " est un chiffre ? " << isdigit(chiffre) << std::endl;
	std::cout << "Est-ce que " << chiffre << " est un signe de ponctuation ? " << ispunct(chiffre) << std::endl;

	std::string const numero{ "0185017204" };

	if (std::all_of(std::cbegin(numero), std::cend(numero), isdigit))
	{
		std::cout << "C'est un numéro de téléphone correct." << std::endl;
	}
	else
	{
		std::cout << "Entrée invalide." << std::endl;
	}

	return 0;
}