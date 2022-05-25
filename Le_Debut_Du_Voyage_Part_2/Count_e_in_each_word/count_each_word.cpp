#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string const phrase{ "Exemple illustrant le guide du C++ moderne." };
	std::string::const_iterator debut_mot{ std::begin(phrase) };
	std::string::const_iterator fin_mot{ std::find(std::begin(phrase), std::end(phrase), ' ') };

	std::string const mot{ debut_mot, fin_mot };
	ptrdiff_t const e_mot{ std::count(debut_mot, fin_mot, 'e') };

	std::cout << "Dans le mot '" << mot << "' il y a " << e_mot << " 'e'.\n";

	while (fin_mot != std::end(phrase))
	{
		debut_mot = ++fin_mot;
		fin_mot = std::find(debut_mot, std::end(phrase), ' ');

		std::string const mot{ debut_mot, fin_mot };
		ptrdiff_t const e_mot{ std::count(debut_mot, fin_mot, 'e') };

		std::cout << "Dans le mot '" << mot << "' il y a " << e_mot << " 'e'.\n";
	}

	return 0;
}