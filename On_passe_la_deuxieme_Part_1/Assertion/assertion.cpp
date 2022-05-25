#include <cassert>
#include <iostream>

double division(double numerateur, double denominateur);
void input(double& to_read);

int main()
{
	double numerateur{};
	std::cout << "Numerateur : ";
	input(numerateur);

	double denominateur{};
	do
	{
		std::cout << "Denominateur : ";
		input(denominateur);
	}
	while (denominateur == 0.0);

	std::cout << "Resultat : " << division(numerateur, denominateur) << std::endl;

	return 0;
}

void input(double& to_read)
{
	while (!(std::cin >> to_read))
	{
		std::cin.clear();
		std::cin.ignore(255, '\n');
		std::cout << "You must enter a reel number ! Try again : ";
	}
}

double division(double numerateur, double denominateur)
{
	assert(denominateur != 0 && "Le denominateur ne peut pas valoir 0.");

	return numerateur / denominateur;
}