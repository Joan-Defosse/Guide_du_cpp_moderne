#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::string const phrase{ " Salut,  ceci est une phrase.   " };
	char const delimiteur{ ' ' };

	std::vector<std::string> parties{};

    std::string::const_iterator debut{ std::find_if_not(std::begin(phrase), std::end(phrase), isspace) };
	std::string::const_iterator fin{ std::end(phrase) };
	std::string::const_iterator it{ std::find(debut, fin, delimiteur) };

	while (it != fin && debut != fin)
	{
		std::string const mot{ debut, it }; // ou mot { debut, debut + std::distance(debut, it) }

		parties.push_back(mot);

		debut = std::find_if_not(++it, fin, isspace);

		if (debut != fin)
		{
			it = std::find(debut, fin, delimiteur);
		}
	}
	
	if (debut != fin)
	{
		std::string const mot{ debut, it };

		parties.push_back(mot);
	}
	
	for (std::string mot : parties)
	{
		std::cout << mot << '_';
	}

	return 0;
}