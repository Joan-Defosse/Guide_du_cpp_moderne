#include <iostream>
#include <vector>

int main()
{
	double moyenne{};
	std::vector<double> valeurs{};

	std::cout << "Nous allons calculer la moyenne de vos valeurs.\n";

	while (true)
	{
		double note{};

		std::cout << "Entrez une valeur, négative pour arrêter, positive pour continuer : ";
		
		while (!(std::cin >> note))
		{
			std::cout << "Votre valeur doit être un réel : ";
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}

		if (note < 0)
		{
			break;
		}
		
		valeurs.push_back(note);
	}

	if (!std::empty(valeurs))
	{
		for (double const i : valeurs)
		{
			moyenne += i;
		}

		moyenne /= std::size(valeurs);

		std::cout << "La moyenne de vos valeur est " << moyenne << std::endl;
	}
	else
	{
		std::cout << "Vous avez oublié de rentrer des notes !\n";
	}

	return 0;
}