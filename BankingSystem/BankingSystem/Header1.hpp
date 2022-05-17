#include <iostream>
#include <vector>
#include <limits>

void CreateAccount();
void DeleteAccount();
void AccessAccount();

class Account {
	private:
		std::string password;
		int balance = 0;
	public:
		std::string username;

		Account(std::string name, std::string pass);

		int GetBalance();

		void SetBalance(int newBalance);

		void AddToBalance(int amount);

		void RemoveFromBalance(int amount);

		void SetPassword(std::string newPassword);

		std::string GetPassword();
};

extern std::vector<Account> accountsHolder;
