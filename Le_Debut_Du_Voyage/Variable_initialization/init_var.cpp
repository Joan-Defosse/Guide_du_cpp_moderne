#include <iostream>
#include <string>

int main()
{
	int reponse{ 42 };
	std::cout << "La réponse à la Grande question est " << reponse << std::endl;

	int mauvaise_reponse = 4 ;
	std::cout << "La réponse à la Grande question n'est pas " << mauvaise_reponse << std::endl;

	double pi{ 3.1415926 };
	std::cout << "Voici la valeur du célèbre nombre pi : " << pi << std::endl;

	char lettre{ 'A' };
	std::cout << "La première lettre de l'alphabet français est " << lettre << std::endl;

	std::string phrase{ "Bonjour tout le monde !" };
	std::cout << "En entrant dans la salle, il s'écria : " << phrase << std::endl;

	int default_entier{};
	std::cout << "La valeur par défaut d'un entier est : " << default_entier << std::endl;

	double default_reel{};
	std::cout << "La valeur par défaut d'un réel est : " << default_reel << std::endl;

	char default_lettre{};
	std::cout << "La valeu par défaut d'un caractère est : " << default_lettre << std::endl;

	std::string default_chaine{};
	std::cout << "La valeur par défaut d'une chaîne est : " << default_chaine << std::endl;

	return 0;
}