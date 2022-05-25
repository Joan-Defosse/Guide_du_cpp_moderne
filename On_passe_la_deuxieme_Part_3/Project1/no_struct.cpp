#include <iostream>
#include <fstream>
#include <string>
#include <limits>

template <typename T, typename P>
void secure_input(T& entree, P predicate);

template <typename T>
void secure_input(T& entree);

void ask(std::string& name, std::string& firstname, std::string& sex, int& age);

std::string save(std::string const& name, std::string const& firstname, std::string const& sex, int age);

int main()
{
	std::string name{};
	std::string firstname{};
	std::string sex{};
	int age{};

	ask(name, firstname, sex, age);
	auto filename{ save(name, firstname, sex, age) };

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

void ask(std::string& name, std::string& firstname, std::string& sex, int& age)
{
	std::cout << "Name ? ";
	secure_input(name);
	std::cout << "Firstname ? ";
	secure_input(firstname);
	std::cout << "Sex ? ";
	secure_input(sex);
	std::cout << "Age ? ";
	secure_input(age, [](int n) -> bool { return n > 0; });
}

std::string save(std::string const& name, std::string const& firstname, std::string const& sex, int age)
{
	std::string filename{ firstname + '.' + name + ".csv" };
	std::ofstream file{ filename };
	file << name << ',' << firstname << ',' << sex << ',' << age << std::endl;
	file.close();

	return filename;
}