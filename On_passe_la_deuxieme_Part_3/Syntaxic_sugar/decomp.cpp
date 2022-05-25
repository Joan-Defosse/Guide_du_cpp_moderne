/* using oss = std::ostringstream; 
* using ListeResultats = std::vector<std::tuple<std::string, int>> */

#include <cmath>
#include <iostream>
#include <string>
#include <tuple>
#include <numbers>
#include <cassert>

using namespace std::numbers;

struct Personne
{
	std::string nom;
	std::string prenom;
	int age;
};

std::tuple<int, std::string> f()
{
	using namespace std::literals;
	return { 20, "Clem"s };
}

std::tuple<double, double> g(double angle)
{
	return { std::cos(angle), std::sin(angle) };
}

Personne h()
{
	return { "Lagrume", "Clem", 4 };
}

int main()
{
	auto [note, nom] = f();
	std::cout << "Tu t'appelles " << nom << " et tu as obtenu " << note << "/20." << std::endl;

	auto [cosinus, sinus] = g(pi / 4.);
	std::cout << "Voici le cosinus de PI / 4 : " << cosinus << std::endl;
	std::cout << "Voici le sinus de PI / 4 : " << sinus << std::endl;

	using namespace std::literals;

	auto bookmark = std::make_tuple(
		"https://zestedesavoir.com"s,
		"Zeste de Savoir"s,
		30
	);

	auto& [url, titre, visites] = bookmark;
	++visites;

	assert(std::get<2>(bookmark) == 31);

	auto [name, prenom, age] = h();

	std::cout << "Voici " << prenom << ' ' << name << " et elle a " << age << " ans." << std::endl;

	return 0;
}