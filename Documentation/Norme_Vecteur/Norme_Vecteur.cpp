#include <cassert>
#include <cmath>

int main()
{
	int const x{ 5 };
	int const y{ 12 };
	int norme{ 0 };

	norme = std::hypot(x, y);

	assert(norme == 13 && "La norme du vecteur(5; 12) vaut 13.");

	return 0;
}
