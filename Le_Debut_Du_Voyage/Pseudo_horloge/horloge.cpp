#include <iostream>

int main()
{
	int heure{};

	std::cout << "Quelle heure est-il ?" << std::endl;
	
	if (!(std::cin >> heure))
	{
		std::cout << "Vous n'avez pas rentr� un entier, il y a eu une erreur.\n";
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
			std::cout << "Vous devriez dormir � cette heure-l� !\n";
		}
		else if (heure >= 8 && heure < 12)
		{
			std::cout << "C'est le matin, une bonne journ�e s'annonce !\n";
		}
		else if (heure == 12)
		{
			std::cout << "Il est midi, bon app�tit !\n";
		}
		else if (heure >= 13 && heure < 18)
		{
			std::cout << "Il fait chaud cet apr�s-midi !\n";
		}
		else if (heure >= 19 && heure < 24)
		{
			std::cout << "Quelle soir�e !\n";
		}
		else
		{
			std::cout << "Votre horloge a s�rement un probl�me de r�glage !\n";
		}
	}

	return 0;
}