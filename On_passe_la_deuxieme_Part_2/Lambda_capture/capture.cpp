#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	bool const un_booleen{ true };
	int un_entier{ 42 };

	auto lambda_display{ [un_booleen]() -> void
	{
		std::cout << "Le booleen vaut " << std::boolalpha << un_booleen << std::endl;
	} };

	lambda_display();

	auto lambda_mutable{ [un_entier]() mutable -> void
	{
		un_entier = 0;
		std::cout << "L'entier vaut : " << un_entier << " dans la lambda.\n";
	} };

	lambda_mutable();

	std::cout << "L'entier vaut : " << un_entier << " dans main.\n";

	std::vector<int> const nombres{ 8, 7, 5, 4, 31, 98, 2, 77, 648 };

	int const diviseur{ 2 };
	int somme{ 0 };

	std::for_each(std::cbegin(nombres), std::cend(nombres),
		[diviseur, &somme](int element) -> void
		{
			if (element % diviseur == 0)
			{
				somme += element;
			}
		});

	std::cout << "La somme de tous les elements divisibles par " << diviseur << " vaut " << somme << std::endl;

	return 0;
}