#include <iostream>
#include <vector>
#include "Header1.hpp"

int main()
{
	while (true)
	{
		std::string answer;
		std::cout << "Enter 'create', 'access', or 'delete'.\n";
		std::cout << "Would you like to create an account, access an account, or delete an account?\n";
		std::cin >> answer;
		if (answer != "create" && answer != "access" && answer != "delete")
		{
			std::cout << "Try again.\n";
			continue;
		}
		else
		{
			if (answer == "create")
			{
				CreateAccount();
			}
			else if (answer == "access")
			{
				AccessAccount();
			}
			else
			{
				DeleteAccount();
			}
		}
	}
}