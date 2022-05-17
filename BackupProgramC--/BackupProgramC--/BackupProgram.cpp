#include <iostream>
#include <filesystem>
#include <fstream>

int main()
{
	std::string answer;
	std::cout << "Enter location of directory 1: ";
	std::cin >> answer;
	bool exist = std::filesystem::exists(answer);
	if (!exist)
	{
		std::cout << "Directory does not exist.";
	}
	else
	{
		std::cout << "Directory does exist.";
	}

}