#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> nombres{ -8, 7, 48, 366, 1, 4, 3 };

    std::for_each(std::begin(nombres), std::end(nombres),
        [](int& nombre) -> void
        {
            nombre *= nombre;
        });

    for (auto nombre : nombres)
    {
        std::cout << nombre << std::endl;
    }

    return 0;
}