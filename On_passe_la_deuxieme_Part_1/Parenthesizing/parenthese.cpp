#include <iostream>
#include <string>

bool parentheses(std::string expression)
{
	int opening{ 0 };
	int ending{ 0 };

	for (auto c : expression)
	{
		if (c == '(')
		{
			++opening;
		}
		else if (c == ')')
		{
			++ending;
		}

		if (ending > opening)
		{
			return false;
		}
	}

	return (opening == ending);
}

int main()
{
	std::cout << std::boolalpha;
	std::cout << parentheses("((()))") << std::endl;
	std::cout << parentheses("((())") << std::endl;
	std::cout << parentheses(")(") << std::endl;
	std::cout << parentheses("(abc)") << std::endl;

	return 0;
}