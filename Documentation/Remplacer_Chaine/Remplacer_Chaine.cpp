#include <cassert>
#include <iostream>
#include <string>

int main()
{
	std::string phrase{ "J'aimerais annuler ce texte." };
	std::string const mot{ "remplacer" };

	phrase.replace(11, 7, mot);

	assert(phrase == "J'aimerais remplacer ce texte."
		&& "Le texte n'a pas ete modifie correctement.");

	return 0;
}