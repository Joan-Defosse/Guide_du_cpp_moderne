#include <vector>
#include <iostream>

int main()
{
    std::vector<int> nombres{ -8, 7, 48, 366, 1, 4, 3 };

    for (int i = 0; i < nombres.size(); ++i)
    {
        nombres[i] *= nombres[i];
    }

    for (auto nombre : nombres)
    {
        std::cout << nombre << std::endl;
    }

    return 0;
}