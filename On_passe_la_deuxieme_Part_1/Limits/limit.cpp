#include <iostream>
#include <limits>

int main()
{
	std::cout << "Valeur minimale d'un int : " << std::numeric_limits<int>::min() << std::endl;
	std::cout << "Valeur maximale d'un int : " << std::numeric_limits<int>::max() << std::endl;

	std::cout << "Valeur minimale d'un double : " << std::numeric_limits<double>::min() << std::endl;
	std::cout << "Valeur maximale d'un double : " << std::numeric_limits<double>::max() << std::endl;

	return 0;
}