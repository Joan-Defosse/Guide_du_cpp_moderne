#include "discographie.hpp"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>

void affichage(Discographie& discographie, Affichage type_affichage)
{
    if (type_affichage == Affichage::Album)
    {
        tri_album(discographie);
        affichage_album(discographie);
    }
    else if (type_affichage == Affichage::Artiste)
    {
        tri_artiste(discographie);
        affichage_artiste(discographie);
    }
    else if (type_affichage == Affichage::Morceau)
    {
        tri_morceau(discographie);
        affichage_morceau(discographie);
    }
    else
    {
        throw std::runtime_error("Commande d'affichage inconnue.");
    }
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
    for (Morceau const& morceau : discographie)
    {
        std::cout << "--> " << morceau << std::endl;
    }
}

void affichage_album(Discographie const& discographie)
{
    Album album_precedent{};

    for (Morceau const& morceau : discographie)
    {
        if (morceau.album.nom != album_precedent.nom)
        {
            std::cout << "--> " << morceau.album << " | "
                << morceau.compositeur << std::endl;
        }

        std::cout << "\t/--> " << morceau.nom << std::endl;

        album_precedent = morceau.album;
    }
}

void affichage_artiste(Discographie const& discographie)
{
    Artiste artiste_precedent{};
    Album album_precedent{};

    for (Morceau const& morceau : discographie)
    {
        if (morceau.compositeur.nom != artiste_precedent.nom)
        {
            std::cout << "--> " << morceau.compositeur << std::endl;
        }

        if (morceau.album.nom != album_precedent.nom)
        {
            std::cout << "\t/--> " << morceau.album << std::endl;
        }

        std::cout << "\t\t/--> " << morceau.nom << std::endl;

        artiste_precedent = morceau.compositeur;
        album_precedent = morceau.album;
    }
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