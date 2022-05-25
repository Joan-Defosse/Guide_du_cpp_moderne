#include <iostream>
#include <array>
#include <list>
#include <vector>
#include <string>

template <typename Collection>
void afficher(Collection const& iterable)
{
	for (auto const& e : iterable)
	{
		std::cout << e << '\n';
	}

	std::cout << std::endl;
}

void afficher(std::string const& str)
{
	std::cout << str << std::endl;
}

int main()
{
	std::vector<int> tableau_entiers{ 1, 3, 5, 7, 9 };
	afficher(tableau_entiers);

	std::array<double, 4> const tableau_reels{ 1.2, 3.1415, 12.5, 2.7 };
	afficher(tableau_reels);

	std::list<std::string> liste_chaines{
		"Hello",
		"World",
		"Les templates",
		"C'est super !"
	};
	afficher(liste_chaines);

	std::string const chaine{
		u8"Ça marche même avec des chaînes de caractères !"
	};
	afficher(chaine);

	return 0;
}