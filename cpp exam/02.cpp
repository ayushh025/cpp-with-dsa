#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;
    string ownerName;

public:
    //Constructor
    BankAccount(string accNum, string owner, double initialBalance) {
        accountNumber = accNum;
        ownerName = owner;
        balance = initialBalance;
    }

    //Function to credit amount
    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount credited: " << amount << endl;
        } else {
            cout << "Invalid credit amount!" << endl;
        }
    }

    //Function to debit amount
    void debit(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Amount debited: " << amount << endl;
        } else {
            cout << "Debit failed: Insufficient balance or invalid amount!" << endl;
        }
    }

    //Function to display account balance
    void displayBalance() const {
        cout << "Account Owner: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    //Creating an object of BankAccount
    BankAccount account("9876543210", "Ayush Prajapati", 5000.00);

    //Interacting with the object using public methods
    account.displayBalance();
    cout << endl;

    account.credit(1500);
    account.displayBalance();
    cout << endl;

    account.debit(1000);
    account.displayBalance();
    cout << endl;


    return 0;
}

