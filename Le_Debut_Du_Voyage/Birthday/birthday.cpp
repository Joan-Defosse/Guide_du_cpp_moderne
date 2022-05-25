#include <iostream>

int main()
{
	int jour{};
	int mois{};

	std::cout << "Quel jour es-tu n� ? ";
	
	while (!(std::cin >> jour))
	{
		std::cout << "Entr�e invalide, recommence : ";
		std::cin.clear();
		std::cin.ignore(255, '\n');
	}

	std::cout << "Quel mois es-tu n� ? ";

	do
	{
		if (std::cin.fail())
		{
			std::cout << "Entr�e invalide, recommence : ";
			std::cin.clear();
			std::cin.ignore(255, '\n');
		}
	} while (!(std::cin >> mois));

	std::cout << "Tu es n� le " << jour << '/' << mois << ".\n";

	return 0;
}