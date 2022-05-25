#include<iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main()
{
	std::string test{ "\n\tHello\t\n" };
	std::cout << "Avant modification : " << test << ".fin" << std::endl;

	std::string::iterator premier_non_espace{ std::find_if_not(std::begin(test), std::end(test), isspace) };

	test.erase(std::begin(test), premier_non_espace);

	std::cout << "Suppression au début : " << test << ".fin" << std::endl;

	premier_non_espace = std::find_if_not(std::rbegin(test), std::rend(test), isspace).base();

	test.erase(premier_non_espace, std::end(test));

	std::cout << "Suppression à la fin : " << test << ".fin" << std::endl;

	return 0;
}