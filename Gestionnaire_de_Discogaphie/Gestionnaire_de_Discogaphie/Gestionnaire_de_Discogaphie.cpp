#include <cassert>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include <limits>
#include <vector>
#include <string>

enum Commande
{
	afficher,
	aide,
	ajouter,
	charger,
	enregistrer,
	invalide,
	quitter
};

struct Musique
{
	std::string morceau;
	std::string album;
	std::string artiste;
};

void s_trim(std::string& s);

Commande to_instruction(std::string s);
Commande get_instruction(std::string& s);

void execution(Commande cmd, std::string& input);
void affichage(std::string& s);
void ajouter_musique(std::string& s);
void afficher_aide();
void chargement(std::string& s);
void sauvegarde(std::string& s);

int main()
{
	std::vector<Musique> discogaphie{};
	Commande cmd{};

	while (cmd != quitter)
	{
		std::string input{};

		std::cout << "> ";
		std::getline(std::cin, input);

		cmd = get_instruction(input);

		execution(cmd, input);
	}

	return 0;
}

// Implémentation des fonctions :

void s_trim(std::string& s)
{
	std::string::iterator it{ std::find_if_not(std::begin(s), std::end(s), isspace) };

	s.erase(std::begin(s), it);

	it = std::find_if_not(std::rbegin(s), std::rend(s), isspace).base();

	s.erase(it, std::end(s));
}

Commande to_instruction(std::string s)
{
	if (s == "afficher")
	{
		return afficher;
	}

	if (s == "aide")
	{
		return aide;
	}

	if (s == "ajouter")
	{
		return ajouter;
	}

	if (s == "charger")
	{
		return charger;
	}

	if (s == "enregistrer")
	{
		return enregistrer;
	}

	if (s == "quitter")
	{
		return quitter;
	}

	return invalide;
}

Commande get_instruction(std::string& s)
{
	s_trim(s);
	auto it{ std::find_if(std::begin(s), std::end(s), isspace) };
	std::string instruction{ std::begin(s), it };
	s.erase(std::begin(s), it);

	return to_instruction(instruction);
}

void execution(Commande cmd, std::string& input)
{
	switch (cmd)
	{
		case afficher:

			affichage(input);
			break;

		case ajouter:

			ajouter_musique(input);
			break;

		case aide:

			afficher_aide();
			break;
			
		case charger:

			chargement(input);
			break;

		case enregistrer:

			sauvegarde(input);
			break;

		case invalide:

			std::cout << "Votre commande est invalide, 'aide' pour la liste des commandes." << std::endl;
			break;
			
		case quitter:

			std::cout << "Au revoir !" << std::endl;
			break;
	}
}