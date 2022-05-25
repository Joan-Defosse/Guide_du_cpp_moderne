#include <iostream>
#include <sstream>
#include <string>

int main()
{
	double const pi{ 3.1415926535 };
	std::ostringstream flux_chaine;

	flux_chaine << std::scientific << std::showpos << pi << std::endl;
	std::string resultat{ flux_chaine.str() };

	std::cout << "Affichage par defaut : " << pi << std::endl;
	std::cout << "Affichage modifie : " << resultat << std::endl;

	std::istringstream flux_entree{ "f8 ad 32" };
	int rouge{ 0 };
	int vert{ 0 };
	int bleu{ 0 };

	flux_entree >> std::hex >> rouge >> vert >> bleu;

	std::cout << "Niveau de rouge : " << rouge << std::endl;
	std::cout << "Niveau de vert : " << vert << std::endl;
	std::cout << "Niveau de bleu : " << bleu << std::endl;

	return 0;
}