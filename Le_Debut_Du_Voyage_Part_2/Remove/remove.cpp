#include <algorithm>
#include <iostream>
#include <string>

int main()
{
	std::string paroles{ "I'm blue, da ba dee da ba da !" };

	std::string::iterator fin{ std::remove(std::begin(paroles), std::end(paroles), 'a') };

	paroles.erase(fin, std::end(paroles));

	std::cout << paroles << std::endl;

	return 0;
}