#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string accountNumber, double initialBalance) 
        : accountNumber(accountNumber), balance(initialBalance) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Withdrew: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }

    double getBalance() const { return balance; }
    string getAccountNumber() const { return accountNumber; }

    virtual void showAccountDetails() const {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }

    virtual ~BankAccount() {}
};

