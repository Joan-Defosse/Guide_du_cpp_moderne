#include <iostream>

int main()
{
	unsigned int age{};
	std::string nom{};

	std::cout << "Entre ton âge : ";
	if (std::cin >> age)
	{
		std::cout << "Entre ton nom : ";
		std::cin >> nom;

		std::cout << "Tu t'appelles " << nom << " et tu as " << age << " ans." << std::endl;
	}
	else {

		std::cout << "Tu n'as pas rentré un entier, il y a eu une erreur." << std::endl;
		std::cin.clear();
		std::cin.ignore(255, '\n');

		std::cout << "Entre ton nom : ";
		std::cin >> nom;

		std::cout << "Tu t'appelles " << nom << '.' << std::endl;
	}

	return 0;
}