#include <iostream>
#include <cmath>
#include <tuple>
#include <numbers>

using namespace std::numbers;

std::tuple<double, double, double> f(double angle)
{
    return { std::cos(angle), std::sin(angle), std::tan(angle) };
}

int main()
{
    double cosinus{};
    double tangente{};

    std::tie(cosinus, std::ignore, tangente) = f(pi);

    std::cout << "Cosinus de pi : " << cosinus << std::endl;
    std::cout << "Tangente de pi : " << tangente << std::endl;

    return 0;
}