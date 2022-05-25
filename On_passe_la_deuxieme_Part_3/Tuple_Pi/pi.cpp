#include <cmath>
#include <iostream>
#include <string>
#include <tuple>
#include <numbers>

using namespace std::numbers;

std::tuple<int, std::string> f()
{
	using namespace std::literals;

	return std::make_tuple(20, "Clem"s);
}

std::tuple<double, double> g(double angle)
{
	return { std::cos(angle), std::sin(angle) };
}

int main()
{
	std::tuple resultats_scolaires{ f() };
	std::cout << "Tu t'appelles " << std::get<std::string>(resultats_scolaires)
		<< " et tu as obtenu " << std::get<int>(resultats_scolaires) << "/20." << std::endl;

	std::tuple calculs{ g(pi / 2.) };
	std::cout << "Voici le cosinus de PI / 2 : " << std::get<0>(calculs) << std::endl;
	std::cout << "Voici le sinus de PI / 2 : " << std::get<1>(calculs) << std::endl;

	return 0;

}