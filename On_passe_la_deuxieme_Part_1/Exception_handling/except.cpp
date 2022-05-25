#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<std::string> read_file(std::string const& filename);
std::string ask_filename();

int main()
{
	std::string filename{ ask_filename() };
	bool file_is_valid{ true };

	do
	{
		try
		{
			std::vector<std::string> lines{ read_file(filename) };
			std::cout << "Here is the content of the file : " << std::endl;
			for (std::string const& line : lines)
			{
				std::cout << line << std::endl;
			}

			file_is_valid = true;
		}
		catch (std::runtime_error const& exception)
		{
			std::cout << "Error : " << exception.what() << std::endl;
			file_is_valid = false;
			filename = ask_filename();
		}

	} while (!file_is_valid);

	return 0;
}

std::vector<std::string> read_file(std::string const& filename)
{
	std::vector<std::string> lines{};
	std::string line{};
	std::ifstream file{ filename };

	if (!file)
	{
		throw std::runtime_error("File does not exist or access denied.");
	}

	while (std::getline(file, line))
	{
		lines.push_back(line);
	}

	return lines;
}

std::string ask_filename()
{
	std::string filename{};
	std::cout << "Enter filename : ";
	std::cin >> filename;

	return filename;
}