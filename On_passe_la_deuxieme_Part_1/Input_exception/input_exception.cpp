#include <iostream>
#include <limits>

int main()
{
	int jour{};
	std::cout << "Quel jour es-tu ne ? ";

	while (!(std::cin >> jour) || jour < 1 || jour > 31)
	{
		if (std::cin.eof())
		{
			throw std::runtime_error("Le flux a ete ferme !");
		}
		else if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Entree invalide, recommence : ";
		}
		else
		{
			std::cout << "Le jour doit etre compris entre 1 et 31. Recommence : ";
		}
	}

	int mois{};
	std::cout << "Quel mois es-tu ne ? ";

	while (!(std::cin >> mois) || mois < 1 || mois > 12)
	{
		if (std::cin.eof())
		{
			throw std::runtime_error("Le flux a ete ferme !");
		}
		else if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Entree invalide, recommence : ";
		}
		else
		{
			std::cout << "Le mois doit etre compris entre 1 et 12. Recommence : ";
		}
	}

	std::cout << "Tu es ne le " << jour << '/' << mois << '.' << std::endl;

	return 0;
}