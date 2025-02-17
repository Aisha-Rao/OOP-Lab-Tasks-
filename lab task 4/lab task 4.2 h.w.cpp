//Task - 02:
//Create an Account class that a bank might use to represent customers bank accounts. Include a data member to
//represent the account balance. Provide three member functions. Member function credit should add an amount
//to the current balance. Member function debits should withdraw money from the Account. Member function get
//Balance should return the current balance.

#include <iostream>

class Account {
private:
    double balance;

public:
    Account(double initialBalance) {
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
            std::cerr << "Initial balance was invalid. Set to 0.\n";
        }
    }
    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            std::cerr << "Invalid credit amount.\n";
        }
    }

    void debit(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            std::cerr << "Debit amount exceeded account balance or is invalid.\n";
        }
    }
    double getBalance() const {
        return balance;
    }
};

int main() {
    Account myAccount(100.0);
    
    std::cout << "Initial Balance: " << myAccount.getBalance() << "\n";
    
    myAccount.credit(50.0);
    std::cout << "After Credit: " << myAccount.getBalance() << "\n";
    
    myAccount.debit(30.0);
    std::cout << "After Debit: " << myAccount.getBalance() << "\n";
    
    myAccount.debit(150.0); 
    
    return 0;
}

