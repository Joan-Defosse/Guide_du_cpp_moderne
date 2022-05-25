#include <iostream>
#include <limits>

template <typename T>
T secure_input()
{
	T entree{};
	while (!(std::cin >> entree))
	{
		std::cout << "Entree invalide. Recommence : ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	return entree;
}

template <typename T>
T add(T x, T y)
{
	return x + y;
}

int main()
{
	std::cout << "Quel jour es-tu ne ? ";
	int jour{ secure_input<int>() };

	std::cout << "Quel mois ? ";
	int mois{ secure_input<int>() };

	std::cout << "Tu es ne le " << jour << '/' << mois << std::endl;

	std::cout << "1 + 3.1415 = " << add<double>(1, 3.1415) << std::endl;

	return 0;
}