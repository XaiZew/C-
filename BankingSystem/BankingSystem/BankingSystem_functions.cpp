#include "Header1.hpp"

std::vector <Account> accountsHolder = {};

Account::Account(std::string name, std::string pass)
{
	username = name;
	password = pass;
};

int Account::GetBalance()
{
	return balance;
}

void Account::SetBalance(int newBalance)
{
	balance = newBalance;
}

void Account::AddToBalance(int amount)
{
	balance += amount;
}

void Account::RemoveFromBalance(int amount)
{
	balance -= amount;
}

void Account::SetPassword(std::string newPassword)
{
	password = newPassword;
}

std::string Account::GetPassword()
{
	return password;
}



void CreateAccount()
{
	std::string username;
	std::string password;
	std::string passCheck;

	std::cout << "username: ";
	std::cin >> username;
	while (true)
	{
		std::cout << "\npassword: ";
		std::cin >> password;
		std::cout << "confirm password: ";
		std::cin >> passCheck;
		if (passCheck != password)
		{
			std::cout << "Try again.\n";
			continue;
		}
		else
		{
			break;
		}
	}

	Account newAccount(username, password);
	accountsHolder.push_back(newAccount);
}

void DeleteAccount()
{
	std::string username;
	std::string password;
	std::string passCheck;

	std::cout << "username: ";
	std::cin >> username;

	for (int i = 0; i < accountsHolder.size(); i++)
	{
		if (accountsHolder[i].username == username)
		{
			std::cout << "Account found.";
			while (true)
			{
				std::cout << "\npassword: ";
				std::cin >> password;
				if (password == accountsHolder[i].GetPassword())
				{
					accountsHolder.erase(accountsHolder.begin() + i);
					std::cout << "Deleted account: " << username << "\n";
					break;
				}
				else
				{
					std::cout << "Wrong password, try again.\n";
					continue;
				}
			}
			break;
		}
	}
}

void AccessAccount()
{
	std::string username;
	std::string password;
	std::string passCheck;

	std::cout << "username: ";
	std::cin >> username;
	for (int i = 0; i < accountsHolder.size(); i++)
	{
		if (accountsHolder[i].username == username)
		{
			while (true)
			{
				std::cout << "\npassword: ";
				std::cin >> password;
				if (password != accountsHolder[i].GetPassword())
				{
					std::cout << "Try again.\n";
					continue;
				}
				else
				{
					break;
				}
			}

			while (true)
			{
				std::string answer;
				std::cout << "Enter 'view', 'deposit', or 'withdraw'.";
				std::cout << "Would you like to view your account balance, deposit amount, or withdraw an amount?\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> answer;
				if (answer == "view")
				{
					std::cout << "Account balance: £" << accountsHolder[i].GetBalance() << "\n";
					continue;
				}
				else if (answer == "deposit")
				{
					while (true)
					{
						int depositAmount = 0;
						std::cout << "How much would you like to deposit? ";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cin >> depositAmount;
						if (depositAmount > 0)
						{
							accountsHolder[i].AddToBalance(depositAmount);
							std::cout << "Deposited amount: £" << depositAmount << "\n";
							break;
						}
						else
						{
							std::cout << "Try again.";
							continue;
						}
					}
				}
				else if (answer == "withdraw")
				{
					while (true)
					{
						int withdrawAmount = 0;
						std::cout << "Enter a multiple of 10.";
						std::cout << "How much would you like to deposit? ";
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cin >> withdrawAmount;
						if (withdrawAmount > 0 && withdrawAmount % 10 == 0 && withdrawAmount <= accountsHolder[i].GetBalance())
						{
							accountsHolder[i].RemoveFromBalance(withdrawAmount);
							std::cout << "Withdrew amount: £" << withdrawAmount << "\n";
							break;
						}
						else
						{
							std::cout << "Try again.";
							continue;
						}
					}
				}
			}
			break;
		}
	}
}