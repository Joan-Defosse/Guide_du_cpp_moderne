#include <iostream>

int main()
{
	unsigned int n{};
	unsigned int diviseur{};
	bool premier{ true };

	std::cout << "Choisis une valeur pour l'entier n : ";
	
	while (!(std::cin >> n))
	{
		std::cout << "Tu dois entrer un entier : ";
		std::cin.clear();
		std::cin.ignore(255, '\n');
	}

	for (int i = 2; i < n; ++i)
	{
		if (n % i == 0)
		{
			diviseur = i;
			premier = false;
			break;
		}
	}

	if (premier)
	{
		std::cout << n << " est premier !" << std::endl;
	}
	else
	{
		std::cout << n << " n'est pas un nombre premier, il est divisible par " << diviseur << ".\n";
	}

	return 0;
}