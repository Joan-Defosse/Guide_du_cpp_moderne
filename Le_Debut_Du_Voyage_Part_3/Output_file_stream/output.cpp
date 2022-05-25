#include <fstream>
#include <string>

int main()
{
	std::ofstream fichier{ "../sortie.txt" };
	std::string texte{ "Zuko dit : 'Mon honneur !'" };
	int x{ 40 };

	fichier << 3 << " " << 4;
	
	fichier << '\n' << " + 2 = " << x + 2;
	fichier << '\n' << texte;

	return 0;
}