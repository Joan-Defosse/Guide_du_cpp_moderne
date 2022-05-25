#include <fstream>
#include <string>

int main()
{
	std::ofstream fichier{ "../sortie.txt", std::ios::app };
	std::string texte{ " et Azula en rit." };

	fichier << texte;

	return 0;
}