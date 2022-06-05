#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

int main()
{
	std::string const phrase{ "Voici une phrase longue que je veux en majuscules." };
	std::string sortie{ "" };

	std::transform(std::begin(phrase), std::end(phrase), std::back_inserter(sortie), toupper);

	std::cout << sortie << std::endl;

	return 0;
}