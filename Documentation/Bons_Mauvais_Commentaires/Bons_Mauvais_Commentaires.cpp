#include <map>
#include <cmath>
#include <string>

int fonction_externe(int n);

/* Bons commentaires : */

// Utilisation de `std::map`car les clés doivent rester tirées dans l'ordre.
using Data = std::map<std::string, int>;

int const x{ 0 };
// Le +1 est nécessaire car fonction_externe est boguée quand x vaut 0.
int resultat{ fonction_externe(x + 1) };

bool premier(int N)
{
	bool est_premier{ true };

	// On ne teste que jusqu'à racine de N pour gagner du temps.
	for (int i{ 2 }; i < std::sqrt(N); ++i)
	{
		if (N % i == 0)
		{
			est_premier == false;
			break;
		}
	}

	return est_premier;
}

/* Mauvais commentaires : */

void mauvais_exemple()
{
	int vie{};

	// Si la vie atteint une valeur critique (<100)
	if (vie < 100)
	{
		// Du code.
	}
}

void meilleur_exemple()
{
	int vie{};
	int const niveau_vie_critique{ 100 };

	if (vie < niveau_vie_critique)
	{
		// Du code.
	}
}