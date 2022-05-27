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
	std::string titre;
	std::string album;
	std::string artiste;
};

using Collection = std::vector<Musique>;

void s_trim(std::string& s);

Commande to_instruction(std::string s);
Commande get_instruction(std::string& s);

void execution(Collection& disc, Commande cmd, std::string& input);
void affichage(Collection const& disc, std::string& s);
void ajouter_musique(Collection& disc, std::string& s);
void ajouter_titre(Collection& disc, std::string& s);
void ajouter_album(Collection& disc, std::string& s);
void ajouter_artiste(Collection& disc, std::string& s);
void afficher_aide(std::string& s);
void chargement(Collection& disc, std::string& s);
void sauvegarde(Collection const& disc, std::string& s);

int main()
{
	Collection discographie{};
	Commande cmd{};

	while (cmd != quitter)
	{
		std::string input{};

		std::cout << "> ";
		getline(std::cin, input);

		cmd = get_instruction(input);

		execution(discographie, cmd, input);
	}

	return 0;
}

// Implémentation des fonctions :

void s_trim(std::string& s)
{
	auto it{ find_if_not(begin(s), end(s), isspace) };

	s.erase(begin(s), it);

	it = find_if_not(rbegin(s), rend(s), isspace).base();

	s.erase(it, end(s));
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
	auto it{ find_if(begin(s), end(s), isspace) };
	std::string instruction{ begin(s), it };
	s.erase(begin(s), it);
	s_trim(s);

	return to_instruction(instruction);
}

void execution(Collection& disc, Commande cmd, std::string& input)
{
	switch (cmd)
	{
		case afficher:

			affichage(disc, input);
			break;

		case ajouter:

			ajouter_musique(disc, input);
			break;

		case aide:

			afficher_aide(input);
			break;
			
		case charger:

			chargement(disc, input);
			break;

		case enregistrer:

			sauvegarde(disc, input);
			break;

		case invalide:

			std::cout << "Votre commande est invalide, 'aide' pour la liste des commandes." << std::endl;
			break;
			
		case quitter:

			std::cout << "Au plaisir de vous revoir !" << std::endl;
			break;
	}
}

void affichage(Collection const& disc, std::string& s)
{

}

void ajouter_musique(Collection& disc, std::string& s)
{
	int n = count(begin(s), end(s), '|');

	switch (n)
	{
		case 0:

			ajouter_titre(disc, s);
			break;


		case 1:

			ajouter_album(disc, s);
			break;


		case 2:

			ajouter_artiste(disc, s);
			break;

		default:

			std::cout << "Il y a trop d'arguments, 'aide ajouter' pour des explications." << std::endl;
	}
}

void ajouter_titre(Collection& disc, std::string& s)
{
	auto debut{ find_if_not(begin(s), end(s), isspace) };
	auto fin{ find_if(begin(s), end(s), isspace) };
	std::string titre{};

	if (debut == fin)
	{
		titre = "Titre inconnu";
	}
	else
	{
		titre = { debut, fin };
	}

	disc.push_back({ titre, "Album inconnu", "Artiste inconnu" });
}

void ajouter_album(Collection& disc, std::string& s)
{
	std::string titre{};
	std::string album{};

	auto separateur{ find(begin(s), end(s), '|') };
	auto debut_titre{ find_if_not(begin(s), end(s), isspace) };
	auto fin_titre{ find_if(begin(s), end(s), isspace) };
	auto debut_album{ find_if_not(separateur + 1, end(s), isspace) };
	auto fin_album{ find_if(separateur + 1, end(s), isspace) };

	if (debut_titre == separateur)
	{
		titre = "Titre inconnu";
	}
	else if (fin_titre >= separateur)
	{
		std::cout << "Erreur d'espacement, 'aide ajouter' pour plus d'informations." << std::endl;
		return;
	}
	else
	{
		titre = { debut_titre, fin_titre };
	}

	if (debut_album == fin_album)
	{
		album = "Album inconnu";
	}
	else if (!isspace(*(separateur + 1)))
	{
		std::cout << "Erreur d'espacement, 'aide ajouter' pour plus d'informations." << std::endl;
		return;
	}
	else
	{
		album = { debut_album, fin_album };
	}

	disc.push_back({ titre, album, "Artiste inconnu" });
}

void ajouter_artiste(Collection& disc, std::string& s)
{

}

void afficher_aide(std::string& s)
{

}

void chargement(Collection& disc, std::string& s)
{

}

void sauvegarde(Collection const& disc, std::string& s)
{

}