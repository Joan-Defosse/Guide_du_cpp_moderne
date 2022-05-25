#include <iostream>
#include <limits>

void input(int& to_read)
{
	while (!(std::cin >> to_read))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "You must enter an integer ! Try again : ";
	}
}

void input(double& to_read)
{
	while (!(std::cin >> to_read))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "You must enter a reel number ! Try again : ";
	}
}

int main()
{
	int day{};
	int month{};
	int year{};
	double size{};

	std::cout << "Which day were you born ? ";
	input(day);

	std::cout << "Which month ? ";
	input(month);

	std::cout << "Which year ? ";
	input(year);

	std::cout << "What is your size ? ";
	input(size);

	std::cout << "You were born on " << month << '/' << day << '/' << year
		<< " and you are " << size << "cm tall !" << std::endl;

	return 0;
}