#include <iostream>
#include <string>
#include <unordered_map>

using namespace std::literals;

int main()
{
	std::unordered_map<std::string, double> constantes
	{
		{ "pi"s, 3.1415926535 },
		{ "e"s, 2. }
	};

	auto paire_phi{ constantes.insert({"phi"s, 1.61803 }) };
	if (paire_phi.second)
	{
		std::cout << "La valeur de " << paire_phi.first->first << " a bien ete ajoutee." << std::endl;
	}

	auto paire_pi{ constantes.insert({ "pi"s, 3. }) };
	if (!paire_pi.second)
	{
		std::cout << "La cle " << paire_pi.first->first << " existe deja et vaut " << paire_pi.first->second << '.' << std::endl;
	}

	auto paire_e{ constantes.insert_or_assign("e"s, 2.71828) };
	if (paire_e.second)
	{
		std::cout << "La valeur " << paire_e.first->first << " a bien ete ajoutee." << std::endl;
	}
	else
	{
		std::cout << "La valeur " << paire_e.first->first << " a bien ete mise a jour et vaut "
			<< paire_e.first->second << '.' << std::endl;
	}

	return 0;
}