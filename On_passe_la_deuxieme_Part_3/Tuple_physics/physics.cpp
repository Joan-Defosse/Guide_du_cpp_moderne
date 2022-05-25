#include <cmath>
#include <iostream>
#include <string>
#include <tuple>
#include <numbers>

std::tuple<double, double> equations_mouvements(double vitesse_initiale, double angle, double t)
{
	double const g{ 9.80665 };
	double const x{ vitesse_initiale * std::cos(angle) * t };
	double const y{ (-g * (t * t) / 2.) + (vitesse_initiale * std::sin(angle) * t) };

	return { x, y };
}

int main()
{
	double const vitesse_initiale{ 8.0 };
	double const angle{ std::numbers::pi / 4 };

	for (double t{}; t < 10; t += 0.1)
	{
		std::tuple coordonnees{ equations_mouvements(vitesse_initiale, angle, t) };

		if (std::get<1>(coordonnees) < 0)
		{
			break;
		}

		std::cout << "A l'instant t = " << t << ", on a :\n"
			<< "x = " << std::get<0>(coordonnees) << '\n'
			<< "y = " << std::get<1>(coordonnees) << '\n'
			<< std::endl;
	}

	return 0;
}