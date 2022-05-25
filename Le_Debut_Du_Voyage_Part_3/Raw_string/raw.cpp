#include <iostream>

int main()
{
	std::cout << R"(Elle a dit "Va dans le dossier C:\Windows".)" << std::endl;

	std::cout << R"&(Il a écrit "f(x)" au tableau.)&" << std::endl;

	std::cout << R"abc(On choisit son délimiteur de cette façon.)abc" << std::endl;

	return 0;
}