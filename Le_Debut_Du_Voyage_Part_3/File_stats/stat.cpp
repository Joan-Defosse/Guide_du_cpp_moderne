#include <fstream>
#include <iostream>
#include <string>

int main()
{
	std::ifstream input{ "../test.txt" };
	std::string ligne{ "" };

	int total_lignes{ 0 };
	int total_caracteres{ 0 };
	int total_mots{ 0 };

	bool espace_caractere_precedent{ false };

	while (std::getline(input, ligne))
	{
		++total_lignes;

		for (char c : ligne)
		{
			if (isspace(c))
			{
				if (!espace_caractere_precedent)
				{
					++total_mots;
					espace_caractere_precedent = true;
				}
			}
			else
			{
				++total_caracteres;
				espace_caractere_precedent = false;
			}
		}

		if (!espace_caractere_precedent)
		{
			++total_mots;
			espace_caractere_precedent = true;
		}
	}

	std::cout << "Total de caracteres : " << total_caracteres << std::endl;
	std::cout << "Total de mots : " << total_mots << std::endl;
	std::cout << "Total de lignes : " << total_lignes << std::endl;

	return 0;
}