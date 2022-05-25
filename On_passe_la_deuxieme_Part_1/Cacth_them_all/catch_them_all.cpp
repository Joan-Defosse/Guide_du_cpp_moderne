#include <iostream>
#include <stdexcept>
#include <string>

int main()
{
	try
	{
		int entier{ std::stoi("jajube") };
		std::cout << "Entier : " << entier << std::endl;
	}
	catch (std::invalid_argument const& exception)
	{
		std::cout << "Argument invalide : " << exception.what() << std::endl;
	}
	catch (std::out_of_range const& exception)
	{
		std::cout << "Chaine trop longue : " << exception.what() << std::endl;
	}
	catch (std::exception const& exception)
	{
		std::cout << "Une erreur est survenue : " << exception.what() << std::endl;
	}

	return 0;
}