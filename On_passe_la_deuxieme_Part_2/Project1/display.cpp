#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main()
{
	std::vector<std::string> const chaines{
		"Un mot",
		"Autre chose",
		"Du blabla",
		"Du texte",
		"Des lettres"
	};

	std::for_each(std::begin(chaines), std::end(chaines),
		[](std::string const& message) -> void
		{
			std::cout << "Message recu : " << message << std::endl;
		});

	return 0;
}