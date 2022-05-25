#include <iostream>

int main()
{
	int entier{ 40 };
	int& reference_entier{ entier };

	std::cout << "Entier vaut : " << entier << std::endl;
	std::cout << "Reference vaut : " << reference_entier << std::endl;

	reference_entier += 2;

	std::cout << "Entier vaut : " << entier << std::endl;
	std::cout << "Reference vaut : " << reference_entier << std::endl;

	int const entier_constant{ 0 };
	int const& reference_const_entier_const{ entier_constant };

	int const& reference_const_entier{ entier };

	std::cout << "Entier vaut : " << entier << std::endl;
	std::cout << "Reference constante vaut : " << reference_const_entier << std::endl;

	entier = 8;

	std::cout << "Entier vaut : " << entier << std::endl;
	std::cout << "Reference constante vaut : " << reference_const_entier << std::endl;

	return 0;
}