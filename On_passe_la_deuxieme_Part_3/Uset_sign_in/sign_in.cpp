#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_set>

void ajouter_membre(std::unordered_set<std::string>& membres, std::string const& pseudo)
{
	auto it = membres.insert(pseudo);
	if (it.second)
	{
		std::cout << "Bienvenue sur Zeste de savoir, " << pseudo << '.' << std::endl;
	}
	else
	{
		std::cout << "Desole, le pseudo " << std::quoted(pseudo) << " est deja pris." << std::endl;
	}
}

int main()
{
	std::unordered_set<std::string> pseudos
	{
		"mehdidou99",
		"informaticienzero"
	};

	pseudos.insert("Dwayn");
	pseudos.insert("Taurre");

	ajouter_membre(pseudos, "gbdivers");
	ajouter_membre(pseudos, "informaticienzero");

	pseudos.erase("Dwayn");

	for (auto const& cle : pseudos)
	{
		std::cout << cle << std::endl;
	}

	if (pseudos.find("Gabbro") == std::end(pseudos))
	{
		std::cout << "Le pseudo " << std::quoted("Gabbro") << " est libre." << std::endl;
	}

	return 0;
}
