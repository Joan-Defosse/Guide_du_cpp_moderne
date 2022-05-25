#include <iostream>

void display_rectangle(int height, int width)
{
	for (int i{ 0 }; i < height; ++i)
	{
		for (int j{ 0 }; j < width; ++j)
		{
			std::cout << '*';
		}

		std::cout << std::endl;
	}
}

int main()
{
	int w{ 0 };
	int h{ 0 };
	
	std::cout << "Enter the width of the rectangle : ";
	
	while (!(std::cin >> w))
	{
		std::cin.clear();
		std::cin.ignore(255, '\n');
		std::cout << "You must enter an integer ! Try again : ";
	}

	std::cout << "Enter the height of the rectangle : ";
	
	while (!(std::cin >> h))
	{
		std::cin.clear();
		std::cin.ignore(255, '\n');
		std::cout << "You must enter an integer ! Try again : ";
	}

	display_rectangle(abs(h), abs(w));

	return 0;
}