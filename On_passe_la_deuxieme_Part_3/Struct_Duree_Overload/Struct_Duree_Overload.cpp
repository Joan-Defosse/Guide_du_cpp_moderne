#include <iostream>
#include <tuple>

struct Duree
{
    int secondes;
};

Duree creer_duree(int secondes);
Duree creer_duree(int minutes, int secondes);
Duree creer_duree(int heures, int minutes, int secondes);

int en_secondes(Duree const& d);
std::tuple<int, int> en_minutes(Duree const& d);
std::tuple<int, int, int> en_heures(Duree const& d);

Duree operator+(Duree const& d1, Duree const& d2);
Duree operator-(Duree const& d1, Duree const& d2);
Duree operator+(Duree const& d);
Duree operator-(Duree const& d);

bool operator==(Duree const& d1, Duree const& d2);
bool operator!=(Duree const& d1, Duree const& d2);
bool operator<(Duree const& d1, Duree const& d2);
bool operator<=(Duree const& d1, Duree const& d2);
bool operator>(Duree const& d1, Duree const& d2);
bool operator>=(Duree const& d1, Duree const& d2);

std::ostream& operator<<(std::ostream& flux, Duree const& d);

int main()
{
    Duree d{ creer_duree(12, 14, 1) };
    std::cout << d << std::endl;
}

Duree creer_duree(int secondes)
{
    return { secondes };
}

Duree creer_duree(int minutes, int secondes)
{
    return { (minutes * 60) + secondes };
}

Duree creer_duree(int heures, int minutes, int secondes)
{
    return { (heures * 3600) + (minutes * 60) + secondes };
}

int en_secondes(Duree const& d)
{
    return d.secondes;
}

std::tuple<int, int> en_minutes(Duree const& d)
{
    int minutes{ (d.secondes / 60) };
    int secondes{ (d.secondes % 60) };

    return std::make_tuple(minutes, std::abs(secondes));
}


std::tuple<int, int, int> en_heures(Duree const& d)
{
    int heures{ (d.secondes / 3600) };
    int minutes{ ((d.secondes % 3600) / 60) };
    int secondes{ (d.secondes % 60) };

    return std::make_tuple(heures, std::abs(minutes), std::abs(secondes));
}

Duree operator+(Duree const& d1, Duree const& d2)
{
    return { d1.secondes + d2.secondes };
}

Duree operator-(Duree const& d1, Duree const& d2)
{
    return { d1.secondes - d2.secondes };
}

Duree operator+(Duree const& d)
{
    return d;
}

Duree operator-(Duree const& d)
{
    return { -d.secondes };
}

bool operator==(Duree const& d1, Duree const& d2)
{
    return d1.secondes == d2.secondes;
}

bool operator!=(Duree const& d1, Duree const& d2)
{
    return d1.secondes != d2.secondes;
}

bool operator<(Duree const& d1, Duree const& d2)
{
    return d1.secondes < d2.secondes;
}

bool operator<=(Duree const& d1, Duree const& d2)
{
    return d1.secondes <= d2.secondes;
}

bool operator>(Duree const& d1, Duree const& d2)
{
    return d1.secondes > d2.secondes;
}

bool operator>=(Duree const& d1, Duree const& d2)
{
    return d1.secondes >= d2.secondes;
}

std::ostream& operator<<(std::ostream& flux, Duree const& d)
{
    auto [heures, minutes, secondes] = en_heures(d);

    flux << heures << ':' << minutes << '\'' << secondes << '"';

    return flux;
}
