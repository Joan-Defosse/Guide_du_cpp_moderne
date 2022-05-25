#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream texte{ "../texte.txt" };
	std::string phrase{};
	int reponse{};
	int malheur{};

	texte >> reponse >> malheur >> std::ws;

	std::cout << "La reponse a la grande question est " << reponse << " et " << malheur << " porte malheur.\n";

	if (std::getline(texte, phrase))
	{
		std::cout << phrase;
	}

	return 0;
}