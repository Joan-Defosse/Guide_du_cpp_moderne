#include <iostream>

int main()
{
	int poids_linge{};
	int machines_5kg{};
	int machines_10kg{};

	std::cout << "Entrez le poids du linge : ";
	while (!(std::cin >> poids_linge))
	{
		std::cin.clear();
		std::cin.ignore(255, '\n');
		std::cout << "Vous n'avez rentré un entier, il y a eu une erreur, réessayez : ";
	}

	while (poids_linge > 5)
	{
		++machines_10kg;
		poids_linge -= 10;
	}

	if (poids_linge > 0)
	{
		++machines_5kg;
	}

	std::cout << "Vous devriez utiliser " << machines_5kg << " machines de 5 kg et " << machines_10kg << " de 10kg." << std::endl;

	return 0;
}