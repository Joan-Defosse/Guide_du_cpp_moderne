#include <cassert>
#include <iostream>
#include <vector>

void test_push_back_taille_augmentee()
{
	std::vector<int> tableau{ 1, 2, 3 };

	assert(std::size(tableau) == 3 && "La taille doit etre de 3 avant l'insertion.");

	tableau.push_back(-78);

	assert(std::size(tableau) == 4 && "La taille doit etre de 4 apres l'insertion.");
}

void test_push_back_element_bonne_position()
{
	std::vector<int> tableau{ 1, 2, 3 };
	int const element{ 4 };

	tableau.push_back(element);

	assert(tableau[std::size(tableau) - 1] == element && "Le dernier element doit etre 4.");
}

int main()
{
	test_push_back_taille_augmentee();
	test_push_back_element_bonne_position();

	return 0;
}