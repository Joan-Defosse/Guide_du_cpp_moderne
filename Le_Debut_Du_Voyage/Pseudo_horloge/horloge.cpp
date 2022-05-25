#include <iostream>

int main()
{
	int heure{};

	std::cout << "Quelle heure est-il ?" << std::endl;
	
	if (!(std::cin >> heure))
	{
		std::cout << "Vous n'avez pas rentré un entier, il y a eu une erreur.\n";
		std::cin.clear();
		std::cin.ignore(255, '\n');
	}
	else
	{
		if (heure == 0 || heure == 24)
		{
			std::cout << "Entendez-vous les douzes coups de minuit ?\n";
		}
		else if (heure >= 1 && heure < 8)
		{
			std::cout << "Vous devriez dormir à cette heure-là !\n";
		}
		else if (heure >= 8 && heure < 12)
		{
			std::cout << "C'est le matin, une bonne journée s'annonce !\n";
		}
		else if (heure == 12)
		{
			std::cout << "Il est midi, bon appétit !\n";
		}
		else if (heure >= 13 && heure < 18)
		{
			std::cout << "Il fait chaud cet après-midi !\n";
		}
		else if (heure >= 19 && heure < 24)
		{
			std::cout << "Quelle soirée !\n";
		}
		else
		{
			std::cout << "Votre horloge a sûrement un problème de réglage !\n";
		}
	}

	return 0;
}