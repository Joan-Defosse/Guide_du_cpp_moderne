#include <list>
#include <algorithm>
#include <vector>
#include <iostream>

template <typename Collection>
void au_carre(Collection& collection)
{
    std::for_each(std::begin(collection), std::end(collection),
        [](int& nombre) -> void
    {
        nombre *= nombre;
    });
}

template <typename Collection>
void affichage(Collection const& collection)
{
    for (auto element : collection)
    {
        std::cout << element << std::endl;
    }
}

int main()
{
    std::vector<int> nombres{ -8, 7, 48, 366, 1, 4, 3 };
    au_carre(nombres);
    affichage(nombres);

    std::cout << std::endl;

    std::list<int> autres{ 10, 20, 30 };
    au_carre(autres);
    affichage(autres);

    return 0;
}