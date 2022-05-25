#include <fstream>
#include <iostream>
#include <string>

int main()
{
	std::ofstream output{ "../flush.txt" };
	std::string phrase{ "" };

	output << std::boolalpha << true << ' ' << std::noboolalpha << true << '\n';

	output << std::showpos << 42 << ' ' << -48 << '\n';

	std::cout << "Tapez une phrase : ";
	std::cin >> phrase;

	output << phrase << std::flush;

	return 0;
}