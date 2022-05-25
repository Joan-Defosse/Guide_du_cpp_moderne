#include <iostream>

int main()
{
	unsigned int age{};
	std::cout << "Quel est ton âge ?\n";
	std::cin >> age;

	if (age >= 21u)
	{
		std::cout << "Tu es majeur aux U.S.A." << std::endl;;
	}
	else if (age >= 18u)
	{
		std::cout << "Tu es majeur en France." << std::endl;
	}
	else
	{
		std::cout << "Tu es mineur." << std::endl;
	}

	return 0;
}