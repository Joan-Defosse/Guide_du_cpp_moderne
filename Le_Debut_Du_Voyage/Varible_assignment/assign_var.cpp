#include <iostream>

int main()
{
	int a{ 4 };
	std::cout << "Mon entier vaut " << a << std::endl;

	a = 4 * (8 + 9) - 1;
	std::cout << "Finalement non, il vaut : " << a << std::endl;

	a = a + 7;
	std::cout << "Et si j'ajoute 7 ? " << a << std::endl;

	int const b{ a * 2 };
	a = b - 4;
	std::cout << "Enfin, je change de valeur : " << a << std::endl;

	/* Calcul de 4 puissance 5 */
	int c{ 1 };
	int const multiplicateur{ 4 };
	std::cout << c << std::endl;
	c *= multiplicateur;
	std::cout << c << std::endl;
	c *= multiplicateur;
	std::cout << c << std::endl;
	c *= multiplicateur;
	std::cout << c << std::endl;
	c *= multiplicateur;
	std::cout << c << std::endl;
	c *= multiplicateur;
	std::cout << c << std::endl;

	return 0;
}