#include <iostream>
#include <string>

int main()
{
	int reponse{ 42 };
	std::cout << "La r�ponse � la Grande question est " << reponse << std::endl;

	int mauvaise_reponse = 4 ;
	std::cout << "La r�ponse � la Grande question n'est pas " << mauvaise_reponse << std::endl;

	double pi{ 3.1415926 };
	std::cout << "Voici la valeur du c�l�bre nombre pi : " << pi << std::endl;

	char lettre{ 'A' };
	std::cout << "La premi�re lettre de l'alphabet fran�ais est " << lettre << std::endl;

	std::string phrase{ "Bonjour tout le monde !" };
	std::cout << "En entrant dans la salle, il s'�cria : " << phrase << std::endl;

	int default_entier{};
	std::cout << "La valeur par d�faut d'un entier est : " << default_entier << std::endl;

	double default_reel{};
	std::cout << "La valeur par d�faut d'un r�el est : " << default_reel << std::endl;

	char default_lettre{};
	std::cout << "La valeu par d�faut d'un caract�re est : " << default_lettre << std::endl;

	std::string default_chaine{};
	std::cout << "La valeur par d�faut d'une cha�ne est : " << default_chaine << std::endl;

	return 0;
}