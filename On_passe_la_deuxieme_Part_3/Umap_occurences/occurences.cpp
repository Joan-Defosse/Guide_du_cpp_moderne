#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

void occurences_mots(std::string const& phrase)
{
	std::istringstream iss{ phrase };
	std::string mot{};
	std::unordered_map<std::string, int> occurences{};

	while (iss >> mot)
	{
		++occurences[mot];
	}

	for (auto const& paire : occurences)
	{
		std::cout << "Le mot " << paire.first << " apparait " << paire.second << " fois." << std::endl;
	}
}

int main()
{
	occurences_mots("Bonjour, ceci est un test avec une phrase qui est longue et est une phrase en francais.");

	return 0;
}