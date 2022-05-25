#include <iostream>
#include <vector>

int main()
{
	std::vector<int> const conteneur{ 15, 24, 1, 14, 87, 59 };
	int max{ conteneur.front() };
	int min{ conteneur.front() };

	std::vector<int>::const_iterator it = ++conteneur.begin();

	for (it; it != conteneur.end(); ++it)
	{
		if (*it > max)
		{
			max = *it;
		}
		if (*it < min)
		{
			min = *it;
		}
	}

	std::cout << "Le minimum est " << min << " et le maximum est " << max << '.' << std::endl;

	return 0;
}