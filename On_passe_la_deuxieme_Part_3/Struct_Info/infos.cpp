#include <iostream>
#include <fstream>
#include <string>
#include <limits>

struct Informations {
	std::string firstname;
	std::string name;
	std::string sex;
	int age;
};

template <typename T, typename P>
void secure_input(T& entree, P predicate);

template <typename T>
void secure_input(T& entree);

Informations ask();

std::string save(Informations const& info);

int main()
{
	Informations info{ ask() };
	auto filename{ save(info) };

	std::cout << "Data saved in file : " << filename << std::endl;

	return 0;
}

template <typename T, typename P>
void secure_input(T& entree, P predicate)
{
	while (!(std::cin >> entree) || !predicate(entree))
	{
		if (std::cin.eof())
		{
			std::cout << "Closed stream." << std::endl;
			break;
		}
		else if (std::cin.fail())
		{
			std::cout << "Type error, try again : ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			std::cout << "Predicate was not respected, try again : ";
		}
	}
}

template <typename T>
void secure_input(T& entree)
{
	while (!(std::cin >> entree))
	{
		if (std::cin.eof())
		{
			std::cout << "Closed stream." << std::endl;
			break;
		}
		else
		{
			std::cout << "Type error, try again : ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

Informations ask()
{
	Informations info{};
	std::cout << "Name ? ";
	secure_input(info.name);
	std::cout << "Firstname ? ";
	secure_input(info.firstname);
	std::cout << "Sex ? ";
	secure_input(info.sex);
	std::cout << "Age ? ";
	secure_input(info.age, [](int n) -> bool { return n > 0; });

	return info;
}

std::string save(Informations const& info)
{
	std::string filename{ info.firstname + '.' + info.name + ".csv" };
	std::ofstream file{ filename };
	file << info.name << ',' << info.firstname << ',' << info.sex << ',' << info.age << std::endl;
	file.close();

	return filename;
}