#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> const nombres{ 2, 4, 6, 8, 9, 10, 11, 13, 16 };
	std::vector<int>::const_iterator it{ std::begin(nombres) };

	do
	{
		it = std::find_if(it, std::end(nombres),
			[](int nombre) -> bool { return (nombre % 2) != 0; });

		if (it != std::end(nombres))
		{
			std::cout << "Nombre impair : " << *it << std::endl;
			++it;
		}

	} while (it != std::end(nombres));

	return 0;
}