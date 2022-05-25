#include <iostream>
#include <vector>

int main()
{
	std::vector<char> const lettres{ 'a', 'b', 'c', 'b', 'd', 'd', 'd', 'b', 'c', 'g', 'h' };
	char const lettre_a_compter{ 'b' };
	int total{};

	for (char lettre : lettres)
	{
		if (lettre == lettre_a_compter)
		{
			++total;
		}
	}

	std::cout << "Le caractère " << lettre_a_compter << " apparaît " << total << " fois." << std::endl;

	return 0;
}