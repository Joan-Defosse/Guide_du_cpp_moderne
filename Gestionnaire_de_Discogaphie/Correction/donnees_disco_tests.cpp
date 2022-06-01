#include "donnees_disco_tests.hpp"
#include "donnees_disco.hpp"
#include <sstream>
#include <cassert>

// Test d'une entrée complète.
void test_creation_morceau_entree_complete()
{
    std::istringstream entree{ "Chanson A | Mes supers chansons | Bob le chanteur" };
    Morceau morceau{};

    entree >> morceau;

    assert(morceau.nom == "Chanson A" && "Le nom du morceau doit etre 'Chanson A'.");
    assert(morceau.album.nom == "Mes supers chansons" && "Le nom de l'album doit etre 'Mes supers chansons'.");
    assert(morceau.compositeur.nom == "Bob le chanteur" && "Le nom de l'artiste doit etre 'Bob le chanteur'.");
}

// Test d'une entrée avec beaucoup d'espaces.
void test_creation_morceau_entree_espaces_partout()
{
    std::istringstream entree{ "Chanson B\t |\n Mes supers chansons  \t |    Bob le chanteur" };
    Morceau morceau{};

    entree >> morceau;

    assert(morceau.nom == "Chanson B" && "Le nom du morceau doit etre 'Chanson B'.");
    assert(morceau.album.nom == "Mes supers chansons" && "Le nom de l'album doit etre 'Mes supers chansons'.");
    assert(morceau.compositeur.nom == "Bob le chanteur" && "Le nom de l'artiste doit etre 'Bob le chanteur'.");
}

// Test d'une entrée avec seulement le nom de la chanson et l'artiste.
void test_creation_morceau_entree_chanson_artiste()
{
    std::istringstream entree{ "Un chat qui dormait | | Alice la chanteuse" };
    Morceau morceau{};

    entree >> morceau;

    assert(morceau.nom == "Un chat qui dormait" && "Le nom du morceau doit etre 'Un chat qui dormait'.");
    assert(morceau.album.nom == "Album inconnu" && "Le nom de l'album doit etre 'Album inconnu'.");
    assert(morceau.compositeur.nom == "Alice la chanteuse" && "Le nom de l'artiste doit etre 'Alice la chanteuse'.");
}

// Test d'une entrée avec seulement le nom de la chanson.
void test_creation_morceau_entree_chanson_uniquement()
{
    std::istringstream entree{ "L'amour | |" };
    Morceau morceau{};

    entree >> morceau;

    assert(morceau.nom == "L'amour" && "Le nom du morceau doit etre 'L'amour'.");
    assert(morceau.album.nom == "Album inconnu" && "Le nom de l'album doit etre 'Album inconnu'.");
    assert(morceau.compositeur.nom == "Artiste inconnu" && "Le nom de l'artiste doit etre 'Artiste inconnu'.");
}

// Test d'une entrée vide.
void test_creation_morceau_entree_vide()
{
    std::istringstream entree{ "| |" };
    Morceau morceau{};

    entree >> morceau;

    assert(morceau.nom == "Morceau inconnu" && "Le nom du morceau doit etre 'Morceau inconnu'.");
    assert(morceau.album.nom == "Album inconnu" && "Le nom de l'album doit etre 'Album inconnu'.");
    assert(morceau.compositeur.nom == "Artiste inconnu" && "Le nom de l'artiste doit etre 'Artiste inconnu'.");
}