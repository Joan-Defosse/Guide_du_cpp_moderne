#include <iostream>
#include <vector>

std::vector<int> cash_machine(int total, std::vector<int> const existing_banknotes)
{
	std::vector<int> result{};

	for (int banknote : existing_banknotes)
	{
		result.push_back(total / banknote);
		total %= banknote;
	}

	return result;
}

void atm_output(std::vector<int> total, std::vector<int> const existing_banknotes)
{
	int i{ 0 };

	for (int banknote : total)
	{
		if (banknote != 0)
		{
			std::cout << banknote << " x " << existing_banknotes[i] << "$\n";
		}

		++i;
	}
}

int main()
{
	std::vector<int> const existing_banknotes{ 500, 200, 100, 50, 20, 10, 5, 2, 1 };

	std::vector<int> const total{ cash_machine(2485, existing_banknotes) };

	atm_output(total, existing_banknotes);

	return 0;
}