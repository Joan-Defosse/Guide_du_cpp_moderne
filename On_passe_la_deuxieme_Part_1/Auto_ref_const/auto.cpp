#include <iostream>
#include <vector>

int main()
{
	int variable{ 2 };
	int& reference{ variable };

	auto toujours_variable_1{ variable };
	auto toujours_variable_2{ reference };

	auto& toujours_reference_1{ variable };
	auto& toujours_reference_2{ reference };

	auto const toujours_const{ variable };
	auto const& toujours_reference_const{ variable };

	std::vector<int> tableau{ -8, 45, 35, 9 };
	
	decltype(auto) deuxieme_element_reference{ tableau[1] };

	return 0;
}