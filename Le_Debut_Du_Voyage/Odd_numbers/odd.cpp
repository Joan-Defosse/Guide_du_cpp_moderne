#include <iostream>

int main()
{
	int n{};

	std::cout << "Entre un nombre n : ";

	while (!(std::cin >> n))
	{
		std::cout << "Tu dois entrer un entier : ";
		std::cin.clear();
		std::cin.ignore(255, '\n');
	}

	for (int i{ 1 }; i <= n; ++i)
	{
		if (i % 2 == 0)
		{
			continue;
		}

		std::cout << i << std::endl;
	}

	return 0;
}