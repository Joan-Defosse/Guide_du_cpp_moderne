/************************************************
***             Fichiers d'en-tête
*************************************************/

#include <cassert>
#include <exception>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <vector>

/************************************************
***             Définitions
*************************************************/

struct Artiste
{
    std::string nom;
};

struct Album
{
    std::string nom;
};

struct Morceau
{
    std::string nom;
    Album album;
    Artiste compositeur;
};

using Discographie = std::vector<Morceau>;

std::ostream& operator<<(std::ostream& sortie, Artiste const& artiste);
std::ostream& operator<<(std::ostream& sortie, Album const& album);
std::ostream& operator<<(std::ostream& sortie, Morceau const& morceau);
std::istream& operator>>(std::istream& entree, Morceau& morceau);
void ajouter_morceau(Discographie& disco, std::string const& nom_morceau, std::string const& nom_album, std::string const& nom_artiste);

void test_creation_morceau_entree_complete();
void test_creation_morceau_entree_espaces_partout();
void test_creation_morceau_entree_chanson_artiste();
void test_creation_morceau_entree_chanson_uniquement();
void test_creation_morceau_entree_vide();

enum class Affichage { Artiste, Album, Morceau };

void affichage(Discographie& discographie, Affichage type_affichage);

void tri_morceau(Discographie& discographie);
void tri_album(Discographie& discographie);
void tri_artiste(Discographie& discographie);

void affichage_morceau(Discographie const& discographie);
void affichage_album(Discographie const& discographie);
void affichage_artiste(Discographie const& discographie);

void enregistrement(Discographie const& discographie, std::string const& nom_fichier);
void chargement(Discographie& discographie, std::string const& nom_fichier);

/************************************************
***             Progamme principal
*************************************************/


int main()
{
    std::cout << "Hello World!\n";
}

/************************************************
***             Implémentation
*************************************************/

std::string traitement_chaine(std::string const& chaine)
{
    std::string copie{ chaine };

    auto premier_non_espace{ std::find_if_not(std::begin(copie), std::end(copie), isspace) };
    copie.erase(std::begin(copie), premier_non_espace);

    premier_non_espace = std::find_if_not(std::rbegin(copie), std::rend(copie), isspace).base();
    copie.erase(premier_non_espace, std::end(copie));

    return copie;
}

std::ostream& operator<<(std::ostream& sortie, Artiste const& artiste)
{
    sortie << artiste.nom;
    return sortie;
}

std::ostream& operator<<(std::ostream& sortie, Album const& album)
{
    sortie << album.nom;
    return sortie;
}

std::ostream& operator<<(std::ostream& sortie, Morceau const& morceau)
{
    sortie << morceau.nom << " | " << morceau.album << " | " << morceau.compositeur;
    return sortie;
}

std::istream& operator>>(std::istream& entree, Morceau& morceau)
{
    std::string mot{};
    std::ostringstream flux{};

    while (entree >> mot && mot != "|")
    {
        flux << mot << " ";
    }

    std::string nom_morceau{ flux.str() };
    if (std::empty(nom_morceau))
    {
        nom_morceau = "Morceau inconnu";
    }
    morceau.nom = traitement_chaine(nom_morceau);
    flux.str(std::string{});

    while (entree >> mot && mot != "|")
    {
        flux << mot << " ";
    }

    std::string nom_album{ flux.str() };
    if (std::empty(nom_album))
    {
        nom_album = "Album inconnu";
    }
    morceau.album.nom = traitement_chaine(nom_album);
    flux.str(std::string{});

    while (entree >> mot && mot != "|")
    {
        flux << mot << " ";
    }

    std::string nom_artiste{ flux.str() };
    if (std::empty(nom_artiste))
    {
        nom_artiste = "Artiste inconnu";
    }
    morceau.compositeur.nom = traitement_chaine(nom_artiste);
    flux.str(std::string{});

    return entree;
}

void ajouter_morceau(Discographie& disco, std::string const& nom_morceau, std::string const& nom_album, std::string const& nom_artiste)
{
    
}

void affichage(Discographie& discographie, Affichage type_affichage)
{

}

void tri_morceau(Discographie& discographie)
{
    std::sort(std::begin(discographie), std::end(discographie), [](Morceau const& lhs, Morceau const& rhs)
    {
        return lhs.nom < rhs.nom;
    });
}

void tri_album(Discographie& discographie)
{
    std::sort(std::begin(discographie), std::end(discographie), [](Morceau const& lhs, Morceau const& rhs)
    {
        return (lhs.album.nom < rhs.album.nom) || ((lhs.album.nom == rhs.album.nom) && (lhs.nom < rhs.nom));
    });
}

void tri_artiste(Discographie& discographie)
{
    std::sort(std::begin(discographie), std::end(discographie), [](Morceau const& lhs, Morceau const& rhs)
    {
        return lhs.compositeur.nom < rhs.compositeur.nom 
            || (lhs.compositeur.nom == rhs.compositeur.nom && (lhs.album.nom < rhs.album.nom
            || (lhs.album.nom == rhs.album.nom && lhs.nom < rhs.nom)));
    });
}

void affichage_morceau(Discographie const& discographie)
{

}

void affichage_album(Discographie const& discographie)
{

}

void affichage_artiste(Discographie const& discographie)
{

}

void enregistrement(Discographie const& discographie, std::string const& nom_fichier)
{
    std::ofstream fichier{ nom_fichier };
    if (!fichier)
    {
        throw std::runtime_error("Impossible d'ouvrir le fichier en ecriture.");
    }

    for (Morceau const& morceau : discographie)
    {
        fichier << morceau << std::endl;
    }
}

void chargement(Discographie& discographie, std::string const& nom_fichier)
{
    std::ifstream fichier{ nom_fichier };
    if (!fichier)
    {
        throw std::runtime_error("Impossible d'ouvrir le fichier en lecture.");
    }

    std::string ligne{};
    while (std::getline(fichier, ligne))
    {
        Morceau morceau{};
        std::istringstream flux{ ligne };
        flux >> morceau;

        discographie.push_back(morceau);
    }
}

/************************************************
***             Jeux de tests
*************************************************/

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

    assert(morceau.nom == "Moceau inconnu" && "Le nom du morceau doit etre 'Morceau inconnu'.");
    assert(morceau.album.nom == "Album inconnu" && "Le nom de l'album doit etre 'Album inconnu'.");
    assert(morceau.compositeur.nom == "Artiste inconnu" && "Le nom de l'artiste doit etre 'Artiste inconnu'.");
}