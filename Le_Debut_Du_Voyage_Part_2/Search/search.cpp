#include <iostream>
#include <algorithm>
#include <string>

int main()
{
	std::string const phrase{ "Un exemple de phrase contenant des mots." };
	
	std::cout << std::boolalpha;

	std::string mot{ "mot" };
	std::cout << (std::search(std::begin(phrase), std::end(phrase), std::begin(mot), std::end(mot)) != std::end(phrase)) << std::endl;

	mot = "exemple";

	std::cout << (std::search(std::begin(phrase), std::end(phrase), std::begin(mot), std::end(mot)) != std::end(phrase)) << std::endl;

	return 0;
}