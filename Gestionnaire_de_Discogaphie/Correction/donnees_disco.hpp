#ifndef DONNEES_DISCO_HPP_INCLUDED
#define DONNEES_DISCO_HPP_INCLUDED

#include <vector>
#include <iostream>
#include <string>

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
    Artiste compositeur;
    Album album;
};

using Discographie = std::vector<Morceau>;

std::ostream& operator<<(std::ostream& sortie, Artiste const& artiste);
std::ostream& operator<<(std::ostream& sortie, Album const& album);
std::ostream& operator<<(std::ostream& sortie, Morceau const& morceau);
std::istream& operator>>(std::istream& entree, Morceau& morceau);

#endif