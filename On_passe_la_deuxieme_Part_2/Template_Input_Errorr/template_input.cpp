#include <iostream>
#include <limits>
#include <string>

template <typename T, typename P>
void input(T& entree, P predicat)
{
	while (!(std::cin >> entree) || !(predicat(entree)))
	{
		if (std::cin.fail())
		{
			std::cout << "Il y a eu une erreur, reessayez :" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (std::cin.eof())
		{
			break;
		}
		else
		{
			std::cout << "Le predicat n'est pas respecte !" << std::endl;
		}
	}
}

template <typename T>
void input(T& entree)
{
	while (!(std::cin >> entree))
	{
		if (std::cin.fail())
		{
			std::cout << "Il y a eu une erreur, reessayez :" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			break;
		}
	}
}

int main()
{
	int jour{ 0 };
	int mois{ 0 };
	int annee{ 0 };
	double taille{ 0.0 };
	int favori{ 0 };

	std::cout << "Quel jour es-tu ne ? ";
	input(jour, [](int n) -> bool { return (n >= 1) && (n <= 31); });

	std::cout << "Quel mois es-tu ne ? ";
	input(mois, [](int n) -> bool { return (n >= 1) && (n <= 12); });

	std::cout << "Quelle annee es-tu ne ? ";
	input(annee, [](int n) -> bool { return (n >= 1900); });

	std::cout << "Quelle est ta taille ? ";
	input(taille, [](double n) -> bool { return (n > 0.0); });

	std::cout << "Quelle est ton nombre prefere ? ";
	input(favori);

	std::cout << "Tu es ne le : " << jour << '/' << mois << '/' << annee
		<< " et tu mesures " << taille << "m." << std::endl;
	std::cout << "Ton nombre prefere est " << favori << std::endl;

	return 0;
}