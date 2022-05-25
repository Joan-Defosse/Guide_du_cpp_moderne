#include <iostream>
#include <string>
#include <unordered_map>

using namespace std::literals;

int main()
{
	std::unordered_map<std::string, std::string> membres
	{
		{ "mehdidou99"s, "Un auteur du cours C++."s },
		{ "informaticienzero"s, "Un auteur du cours C++."s }
	};

	std::string const pseudo{ "informaticienzéro" };
	if (membres.find(pseudo) != std::end(membres))
	{
		std::cout << "Qui est informaticienzero ? " << membres[pseudo] << std::endl;
	}
	else
	{
		std::cout << "Ce membre n'existe pas." << std::endl;
	}

	return 0;
}