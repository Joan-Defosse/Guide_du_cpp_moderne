#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

int main()
{
	std::vector<int> v_chiffres{ 3, 2, 1, 6, 5, 4, 9, 8, 7, 0 };
	std::list<int> l_chiffres{ 30, 20, 10, 60, 50, 40, 90, 80, 70, 00 };

	std::sort(std::begin(v_chiffres), std::end(v_chiffres));
	
	l_chiffres.sort();

	for (int chiffre : v_chiffres)
	{
		std::cout << chiffre << ", ";
	}

	std::cout << std::endl;
	
	for (int chiffre : l_chiffres)
	{
		std::cout << chiffre << ", ";
	}

	std::cout << std::endl;

	std::reverse(std::begin(l_chiffres), std::end(l_chiffres));

	for (int chiffre : l_chiffres)
	{
		std::cout << chiffre << ", ";
	}

	std::cout << std::endl;

	return 0;
}