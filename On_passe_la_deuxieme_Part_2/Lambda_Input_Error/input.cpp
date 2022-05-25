#include <iostream>
#include <limits>
#include <stdexcept>

int main()
{
	int jour{ 0 };
	int mois{ 0 };
	int annee{ 0 };
	double taille{ 0.0 };
	
	auto input{ [](auto& entree, auto predicat) -> void
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
				throw std::runtime_error("Le flux est ferme !");
			}
			else
			{
				std::cout << "Le predicat n'est pas respecte !" << std::endl;
			}
		}
	} };

	std::cout << "Quel jour es-tu ne ? ";
	input(jour, [](int n) -> bool { return (n >= 1) && (n <= 31); });

	std::cout << "Quel mois es-tu ne ? ";
	input(mois, [](int n) -> bool { return (n >= 1) && (n <= 12); });

	std::cout << "Quelle annee es-tu ne ? ";
	input(annee, [](int n) -> bool { return (n >= 1900); });

	std::cout << "Quelle est ta taille ? ";
	input(taille, [](double n) -> bool { return (n > 0.0); });

	std::cout << "Tu es ne le : " << jour << '/' << mois << '/' << annee
		<< " et tu mesures " << taille << "m." << std::endl;

	return 0;
}