#include <iostream>
#include <stdexcept>
#include <limits>
#include <string>


/**
* @brief Saisie sécurisée avec std::cin.
* @details Vérifie que la variable demandée est du bon type et respecte un prédicat donné.
* En cas de fermeture du flux d'entrée, une exception `std::runtime_error` est levée.
* En cas de type invalide, le flux d'entrée est vide.
* En cas de prédicat non respecté, un message d'erreur est affiché sur la sortie standard.
* 
* @tparam T Le type de la valeur à récupérer.
* @tparam Predicat Un predicat à passer pour personnaliser la vérification.
* 
* @param[out] variable Une référence sur la variable de type `T` à récupérer.
* @param[in] predicat Un prédicat que l'entrée saisie doit respecter.
* 
* @pre Le type `T` doit être utilisable avec `std::cin`.
* @pre Le prédicat doit être de la forme `bool predicat(T variable)`.
* @post La variable sera initialisée correctement avec la valeur entrée.
* 
* @exception std::runtime_error Si le flux d'entrée est fermé.
* 
* @todo Nous devrions remplacer std::cin par un flux générique.
*/
template <typename T, typename Predicat>
void entree_securisee(T& variable, Predicat predicat)
{
	while (!(std::cin >> variable) || !predicat(variable))
	{
		if (std::cin.eof())
		{
			throw std::runtime_error("Le flux est ferme !\n");
		}
		else if (std::cin.fail())
		{
			std::cout << "Entree invalide, recommence !\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			std::cout << "Le predicat n'est pas respecte !\n";
		}
	}
}


/**
* @brief Détermine si une expression est correctement parenthésée.
* @details La fonction regarde si on a bien le même nombre de parenthèses ouvrantes et fermantes
* et si celles-ci sont bien ordonnées.
* 
* @param[in] expression Une chaîne de caractères à analyser.
* 
* @returns `true` si l'expression est bien parenthésée, `false` sinon.
* 
* @note Voici un exemple d'utilisation.
* @code
* std::string const test{ "((()))" };
* parentheses(test);
* @endcode
*/
bool parentheses(std::string const& expression)
{
	int ouvrantes{ 0 };
	int fermantes{ 0 };

	for (auto const& caractere : expression)
	{
		if (caractere == '(')
		{
			++ouvrantes;
		}
		else if (caractere == ')')
		{
			++fermantes;
		}

		if (fermantes > ouvrantes)
		{
			return false;
		}
	}

	return ouvrantes == fermantes;
}

/** @enum Couleur
* @brief Liste des couleurs possibles.
* @details La liste des trois couleurs applicables à l'écran de fond du programme.
*/
enum class Couleur
{
	/// @brief Un bleu profond.
	Bleu,
	/// @brief Un rouge vif.
	Rouge,
	/// @brief Un vert magnifique.
	Vert
};

/** @struct InformationsPersonnelles
* @brief Les informations personnelles d'un membre.
* @details Permet de stocker, sous un même type, les nom/prénom ainsi que le genre et l'âge d'un membre.
* Il n'y a pas de limite à la taille du nom ou du prénom du membre.
*/
struct InformationsPersonnelles
{
	/// @brief Le prénom du membre.
	std::string prenom;
	/// @brief Le nom du membre.
	std::string nom;
	/// @brief Le genre du membre.
	std::string genre;
	/// @brief L'âge du membre.
	int age;
};

/**
* @bug Si le flux est fermé, la fonction rentre dans une boucle infinie.
* 
* @note hypot est la racine carrée de la somme des deux autres côtés élevés au carré.
* 
* @warning Les fonctions f() et g() ne doivent pas être utilisées en même temps !
*/
void fourre_tout();