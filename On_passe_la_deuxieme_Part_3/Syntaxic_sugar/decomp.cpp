/* using oss = std::ostringstream; 
* using ListeResultats = std::vector<std::tuple<std::string, int>> */

#include <cmath>
#include <iostream>
#include <string>
#include <tuple>
#include <numbers>

using namespace std::numbers;

std::tuple<int, std::string> f()
{
	using namespace std::literals;
	return { 20, "Clem"s };
}

std::tuple<double, double> g(double angle)
{
	return { std::cos(angle), std::sin(angle) };
}

int main()
{
	auto [note, nom] = f();
	std::cout << "Tu t'appelles " << nom << " et tu as obtenu " << note << "/20." << std::endl;

	auto [cosinus, sinus] = g(pi / 4.);
	std::cout << "Voici le cosinus de PI / 4 : " << cosinus << std::endl;
	std::cout << "Voici le sinus de PI / 4 : " << sinus << std::endl;

	return 0;
}