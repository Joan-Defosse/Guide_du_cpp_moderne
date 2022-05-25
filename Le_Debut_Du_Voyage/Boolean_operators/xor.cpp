/* Priorité des opérateurs :
* a && b && c == (a && b) && cc
* a || b || c == (a || b) || c
* a || b && c == a || (b && c)
* a && b || c == (a && b) || c
* !a && b == (!a) && b
* a || !b == a || (!b)
* a && b || c && d == (a && b) || (c && d)
* a || b && c || d == (a || (b && c)) || d
*/

#include <iostream>

int main()
{
	bool a{};
	bool b{};

	std::cout << std::boolalpha;

	std::cout << "Entrez la valeur de a : ";
	std::cin >> a;

	std::cout << "Entrez la valeur de b : ";
	std::cin >> b;

	bool x_or{ (!a && b) || (a && !b) };

	std::cout << "(a xor b) = " << x_or << std::endl;

	return 0;
}