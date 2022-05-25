#include <iostream>

enum class Day
{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

void message(Day day_week)
{
	if ((day_week == Day::Saturday) || (day_week == Day::Sunday))
	{
		std::cout << "Nice week-end !" << std::endl;
	}
	else
	{
		std::cout << "Courage !" << std::endl;
	}
}

int main()
{
	Day const today{ Day::Wednesday };
	message(today);

	return 0;
}