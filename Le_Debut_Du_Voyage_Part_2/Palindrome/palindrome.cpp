#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string const mot{ "kayak" };

	if (std::equal(std::cbegin(mot), std::cend(mot), std::crbegin(mot), std::crend(mot)))
	{
		std::cout << mot << " est un palindrome !" << std::endl;
	}
	else
	{
		std::cout << mot << " n'est pas un palindrome !" << std::endl;
	}

	return 0;
}