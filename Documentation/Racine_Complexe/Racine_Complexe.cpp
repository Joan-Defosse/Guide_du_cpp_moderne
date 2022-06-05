#include <iostream>
#include <cassert>
#include <complex>

int main()
{
	auto resultat{ std::sqrt(std::complex<double>{ -1, 0 }) };

	std::cout << "La racine carrée de -1 donne " << resultat.real() << " + " << resultat.imag() << "i." << std::endl;

	return 0;
}