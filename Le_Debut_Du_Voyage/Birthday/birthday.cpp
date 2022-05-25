#include <iostream>

int main()
{
	int jour{};
	int mois{};

	std::cout << "Quel jour es-tu né ? ";
	
	while (!(std::cin >> jour))
	{
		std::cout << "Entrée invalide, recommence : ";
		std::cin.clear();
		std::cin.ignore(255, '\n');
	}

	std::cout << "Quel mois es-tu né ? ";

	do
	{
		if (std::cin.fail())
		{
			std::cout << "Entrée invalide, recommence : ";
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
	} while (!(std::cin >> mois));

	std::cout << "Tu es né le " << jour << '/' << mois << ".\n";

	return 0;
}