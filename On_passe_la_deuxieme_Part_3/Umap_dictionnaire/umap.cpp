#include <iostream>
#include <unordered_map>
#include <string>

using namespace std::literals;

int main()
{
	std::unordered_map<std::string, std::string> dictionnaire
	{
		{ "Hammadi"s, "Gymnaste professionnel, il joue aussi de la batterie !"s },
		{ "Marion"s, "Illustratrice professionnelle, elle fait du roller !"s },
		{ "Angeline"s, "Couturiere, guitariste, violoniste, patissiere et Jean passe..."s },
		{ "Romain"s, "Pianiste incongru, fanatique des Doors !"s }
	};

	dictionnaire.insert({ "Emma"s, "Cascadeuse, voyageuse, la plus grande ninja !"s });
	dictionnaire.insert({
		{ "Joan"s, "C'est moi, le guitariste qui developpe en C++ !"s },
		{ "Morgane"s, "Scientifique de haut niveau, elle a beaucoup de coeur et d'ambitions !"s }
	});

	dictionnaire["Ian"s] = "Le dev le plus puissant que je connaisse, ne jure que par les memes."s;

	dictionnaire.erase("Joan"s);

	for (std::pair<std::string, std::string> const& paire : dictionnaire)
	{
		std::cout << "Cle : " << paire.first << std::endl;
		std::cout << "Valeur : " << paire.second << std::endl << std::endl;
	}

	return 0;
}