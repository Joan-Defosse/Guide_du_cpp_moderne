#include <iostream>

int main()
{
	int const a{ 20 };
	int const b{ 20 };

	std::cout << std::boolalpha;

	std::cout << "a == b : " << (a == b) << std::endl;
	std::cout << "a != b : " << (a != b) << std::endl;
	std::cout << "a < b : " << (a < b) << std::endl;
	std::cout << "a <= b : " << (a <= b) << std::endl;

	bool const plus_grand{ a > b };
	bool const plus_grand_ou_egal{ a >= b };

	std::cout << "a > b : " << plus_grand << std::endl;
	std::cout << "a >= b : " << plus_grand_ou_egal << std::endl;

	return 0;
}