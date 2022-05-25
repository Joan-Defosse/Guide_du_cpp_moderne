#include <iostream>

int main()
{
	unsigned int a{};
	unsigned int b{};
	unsigned int r{};

	std::cout << "Calculons le PGCD de deux nombres !\nEntrez le premier nombre : ";

	while (!(std::cin >> a))
	{
		std::cin.clear();
		std::cin.ignore(255, '\n');
		std::cout << "Vous n'avez rentré un entier, il y a eu une erreur, réessayez : ";
	}

	std::cout << "Entrez le deuxième nombre : ";

	while (!(std::cin >> b))
	{
		std::cin.clear();
		std::cin.ignore(255, '\n');
		std::cout << "Vous n'avez rentré un entier, il y a eu une erreur, réessayez : ";
	}

	r = a % b;
	
	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}

	std::cout << "Leur PGCD est " << b << std::endl;

	return 0;
}