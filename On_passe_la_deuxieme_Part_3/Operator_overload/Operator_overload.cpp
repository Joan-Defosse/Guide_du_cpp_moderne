#include <iostream>
#include <string>
#include <algorithm>

struct Fraction
{
    int numerateur;
    int denominateur;
};

Fraction operator+(Fraction const& a, Fraction const& b);
Fraction operator-(Fraction const& a, Fraction const b);
Fraction operator*(Fraction const& a, Fraction const& b);
Fraction operator/(Fraction const& a, Fraction const& b);

bool operator==(Fraction const& a, Fraction const& b);
bool operator!=(Fraction const& a, Fraction const& b);
bool operator<(Fraction const& a, Fraction const& b);
bool operator>(Fraction const& a, Fraction const& b);
bool operator<=(Fraction const& a, Fraction const& b);
bool operator>=(Fraction const& a, Fraction const& b);

std::ostream& operator<<(std::ostream& flux, Fraction const& fraction);
std::istream& operator>>(std::istream& flux, Fraction & fraction);

int main()
{
    Fraction const un_demi{ 1, 2 };
    Fraction const trois_quarts{ 3, 4 };
    Fraction frac{};

    std::cout << "Entrez une fraction : ";
    std::cin >> frac;

    std::cout << un_demi << " + " << trois_quarts << " - " << frac << " = "
        << un_demi + trois_quarts - frac << std::endl;

    return 0;
}

Fraction operator+(Fraction const& a, Fraction const& b)
{
    int numerateur{ (a.numerateur * b.denominateur) + (b.numerateur * a.denominateur) };
    int denominateur{ a.denominateur * b.denominateur };

    return { numerateur, denominateur };
}

Fraction operator-(Fraction const& a, Fraction const b)
{
    int numerateur{ (a.numerateur * b.denominateur) - (b.numerateur * a.denominateur) };
    int denominateur{ a.denominateur * b.denominateur };

    return { numerateur, denominateur };
}

Fraction operator*(Fraction const& a, Fraction const& b)
{
    int numerateur{ a.numerateur * b.numerateur };
    int denominateur{ a.denominateur * b.denominateur };

    return { numerateur, denominateur };
}

Fraction operator/(Fraction const& a, Fraction const& b)
{
    int numerateur{ a.numerateur * b.denominateur };
    int denominateur{ a.denominateur * b.numerateur };

    return { numerateur, denominateur };
}

bool operator==(Fraction const& a, Fraction const& b)
{
    return (a.numerateur * b.denominateur) == (b.numerateur * a.denominateur);
}

bool operator!=(Fraction const& a, Fraction const& b)
{
    return (a.numerateur * b.denominateur) != (b.numerateur * a.denominateur);
}

bool operator<(Fraction const& a, Fraction const& b)
{
    return (a.numerateur * b.denominateur) < (b.numerateur * a.denominateur);
}

bool operator>(Fraction const& a, Fraction const& b)
{
    return (a.numerateur * b.denominateur) > (b.numerateur * a.denominateur);
}

bool operator<=(Fraction const& a, Fraction const& b)
{
    return (a.numerateur * b.denominateur) <= (b.numerateur * a.denominateur);
}

bool operator>=(Fraction const& a, Fraction const& b)
{
    return (a.numerateur * b.denominateur) >= (b.numerateur * a.denominateur);
}

std::ostream& operator<<(std::ostream& flux, Fraction const& fraction)
{
    return flux << fraction.numerateur << '/' << fraction.denominateur;
}

std::istream& operator>>(std::istream& flux, Fraction & fraction)
{
    std::string frac{};
    std::string num{};
    std::string den{};
    flux >> frac;

    auto it = std::find(std::begin(frac), std::end(frac), '/');
    num = { std::begin(frac), it };
    den = { ++it, std::end(frac) };

    fraction.numerateur = std::stoi(num);
    fraction.denominateur = std::stoi(den);

    return flux;
}