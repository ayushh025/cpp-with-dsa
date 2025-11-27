#include<iostream>
#include<string>
using namespace std;

class BankAccount{
	protected:
		double balance;
		int pin;
	public:
		double accountNumber;
		string accountHolderName;
		string type;
		
		BankAccount(string accountHolderName, double accountNumber, double balance, int pin, string type){
			this->balance = balance;
			this->accountHolderName = accountHolderName;
			this->accountNumber = accountNumber;
			this->pin = pin;
			this->type = type;
		}
		
		virtual void deposit(double deposit){
			this->balance += deposit;
			cout << "Rs. " << deposit << " deposited successfully.\n";
		}
		
		virtual void withdraw(double amount){
			if(amount <= balance){
				int i, u_pin;
				for(i = 0; i < 3; i++){
					cout << "Enter PIN: ";
					cin >> u_pin;
					cin.ignore();
					
					if(this->pin == u_pin){
						this->balance -= amount;
						cout << "Rs. " << amount << " withdrew successfully..\n";
						break;
					}else {
						cout << ((i == 2) ? "You entered wrong pin 3 times try again later\n" 
								:"Wrong pin try again..\n");
					}
				}	
			} else{
				cout << "Insufficient balance..\n";
			}
		}
		
		double getBalance(){
			return this->balance;
		}
		
		virtual void calculateInterest(){
			cout << "This account type doesn’t earn interest.\n";
		}
		
		void displayAccountInfo(){
			cout << "\n--- Account Info ---\n";
			cout << "Account Holder Name: " <<accountHolderName << endl;
			cout << "Account Number: " << accountNumber << endl;
			cout << "Account type: " << type << endl;
		}
};

class SavingsAccount : public BankAccount{
	public:
		double interestRate = 6;
		SavingsAccount(string accountHolderName, double accountNumber, double balance, int pin, string type) 
			: BankAccount(accountHolderName, accountNumber, balance, pin, type){}
			
		void calculateInterest(){
			double interest = this->balance * interestRate / 100;
			cout << "Your intrest in a year is Rs. " << interest << endl;
		}
};

class CheckingAccount : public BankAccount{
	public:
		CheckingAccount(string accountHolderName, double accountNumber, double balance, int pin, string type) 
			: BankAccount(accountHolderName, accountNumber, balance, pin, type){}
			
		double overdraftLimit = -10000;
		double withdrawable;
		
		void withdraw (double amount) override{
			double withdrawable = this->balance + (overdraftLimit * -1);
			if(this->balance <= overdraftLimit){
				cout << "You can't withdraw now, You reached your limit\n";
				cout << "Your balance is Rs. " << this->balance;
			}else{	
				if(amount > withdrawable){
					cout << "You can't withdraw Rs. " << amount << endl;
					cout << "You can maximum withdraw Rs. " << withdrawable << endl; 
				}else{
					this->balance -= amount;
					cout << "Rs. " << amount << " Withdrew successfully..\n";
				}
			}
		}
};
class FixedDepositAccount : public BankAccount{
	public:
		FixedDepositAccount(string accountHolderName, double accountNumber, double balance, int pin, double term, string type) 
			: BankAccount(accountHolderName, accountNumber, balance, pin, type){
			this->term = term;
		}
		double term;
		double rate = 8.5;
		void calculateInterest () override{
			double intrest = this->balance * (term / 12) * (rate / 100);
			cout << "\nInterest after " << term << " months: Rs. " << intrest << endl;
			cout << "Total amount you will get after " << term << " months " << " is Rs. " << intrest + this->balance << endl;
		}
		void deposit(double amount) override{
			cout << "You can't deposit now, You can open an another FD :)\n";
		}
		void withdraw(double amount) override {
        	cout << "Withdrawals not allowed before maturity!\n";
    	}	
};
int main(){
	BankAccount *acc[100];	
	int totalAccounts = 0, ch, i;
	
	do{
		cout << "\n==== Bank Menu ====\n";
		cout << "1. Create Savings Account\n";
		cout << "2. Create Checking Account\n";
		cout << "3. Create Fixed Deposit Account\n";
		cout << "4. Deposit Money\n";
		cout << "5. Withdraw Money\n";
		cout << "6. Show Account Info \n";
		cout << "7. Calculate Interest\n";
		cout << "8. Show All Accounts\n";
		cout << "9. Check Balance\n";
		cout << "10. Exit\n";
		cin >> ch;
		cin.ignore();
		
		switch(ch){
			case 1:{		
				string name;
				int pin = 0, temp_pin = 1;
				double balance;
				cout << "Enter You name: ";
				getline(cin, name);
				double accountNumber = totalAccounts + 1001;
				while(pin != temp_pin){
					cout << "Set pin: ";
					cin >> pin;
					cin.ignore();
					cout << "Enter pin again: ";
					cin >> temp_pin;
					cin.ignore();
					if(temp_pin == pin){
						cout << "PIN set successfully\n";
					}else{
						cout << "Both pin didn't match, Enter again\n";
					}
				}
				cout << "Enter initial amount to be diposited: ";
				cin >> balance;
				cin.ignore();
				acc[totalAccounts] = new SavingsAccount(name, accountNumber, balance, pin, "Saving");
				totalAccounts++;
				cout << "\nSaving account created! Account No: " << accountNumber << endl;
				break;
			}
			case 2:{
				string name2;
				int pin2 = 0, temp_pin2 = 1;
				double balance2;
				cout << "Enter You name: ";
				getline(cin, name2);
				double accountNumber2 = totalAccounts + 2001;
				while(pin2 != temp_pin2){
					cout << "Set pin: ";
					cin >> pin2;
					cin.ignore();
					cout << "Enter pin again: ";
					cin >> temp_pin2;
					cin.ignore();
					if(temp_pin2 == pin2){
						cout << "PIN set successfully\n";
					}else{
						cout << "Both pin didn't match, Enter again\n";
					}
				}
				cout << "Enter initial amount to be diposited: ";
				cin >> balance2;
				cin.ignore();
				acc[totalAccounts] = new CheckingAccount(name2, accountNumber2, balance2, pin2, "Checking");
				totalAccounts++;
				cout << "\nChecking account created! Account No: " << accountNumber2 << endl;
				break;
			}
			case 3:{
				string name3;
				int pin3 = 0, temp_pin3 = 1;
				double balance3, term;
				cout << "Enter You name: ";
				getline(cin, name3);
				double accountNumber3 = totalAccounts + 3001;
				while(pin3 != temp_pin3){
					cout << "Set pin: ";
					cin >> pin3;
					cin.ignore();
					cout << "Enter pin again: ";
					cin >> temp_pin3;
					cin.ignore();
					if(temp_pin3 == pin3){
						cout << "PIN set successfully\n";
					}else{
						cout << "Both pin didn't match, Enter again\n";
					}
				}
				cout << "Enter amount for your FD: ";
				cin >> balance3;
				cin.ignore();
				cout << "Enter months for you FD: ";
				cin >> term;
				acc[totalAccounts] = new FixedDepositAccount(name3, accountNumber3, balance3, pin3, term, "Fixed Deposit");
				totalAccounts++;
				cout << "\nFixed Deposit account created! Account No: " << accountNumber3 << endl;
				break;
			}
			case 4:{
				double accNo, amount;
				if(totalAccounts > 0){
					cout << "Enter Account No. :";
					cin >> accNo;
					for(i = 0; i < totalAccounts ; i++){
						if(acc[i]->accountNumber == accNo){
							if(acc[i]->type != "Fixed Deposit"){
								cout << "Enter amount to be withdrew: ";
								cin >> amount;
								cin.ignore();
								acc[i]->deposit(amount);
							} else{
								acc[i]->deposit(amount);
							}
						}
					}	
				}else {
					cout << "No account is created yet..\n";
				}
				break;
			}
			case 5:{
				double accNo2, amount2;
				if(totalAccounts > 0){
					cout << "Enter Account No. :";
					cin >> accNo2;
					cin.ignore();
					for(i = 0; i < totalAccounts ; i++){
						if(acc[i]->accountNumber == accNo2){
							if(acc[i]->type != "Fixed Deposit"){
								cout << "Enter amount to be withdrew: ";
								cin >> amount2;
								cin.ignore();
								acc[i]->withdraw(amount2);
							} else{
								acc[i]->withdraw(amount2);
							}	
						}
					}	
				}else {
					cout << "No account is created yet..\n";
				}
				break;
			}
			case 6:{
				double accNo3;
				if(totalAccounts > 0){
					cout << "Enter Account No. :";
					cin >> accNo3;
					cin.ignore();
					for(i = 0; i < totalAccounts ; i++){			
						if(accNo3 == acc[i]->accountNumber){
							acc[i]->displayAccountInfo();	
						}
						cout << endl;
					}	
				}else {
					cout << "No account is created yet..\n";
				}
				break;
			}
			case 7:{
				double accNo4;
				if(totalAccounts > 0){
					cout << "Enter Account No. :";
					cin >> accNo4;
					for(i = 0; i < totalAccounts ; i++){
						if(acc[i]->accountNumber == accNo4){
							acc[i]->calculateInterest();	
						}
					}	
				}else {
					cout << "No account is created yet..\n";
				}
				break;
			}
			case 8:{
				if(totalAccounts > 0){
					for(i = 0; i < totalAccounts ; i++){
						cout << "Account " << i+1;
						acc[i]->displayAccountInfo();
						cout << endl;
					}	
				}else {
					cout << "No account is created yet..\n";
				}
				break;
			}
			case 9:{
				if(totalAccounts > 0){
					double accNo5;
					cout << "Enter Account No. :";
					cin >> accNo5;
					cin.ignore();
					for(i = 0; i < totalAccounts ; i++){			
						if(accNo5 == acc[i]->accountNumber){
							cout << "Balance is Rs. " << acc[i]->getBalance();	
						}
						cout << endl;
					}	
				}else {
					cout << "No account is created yet..\n";
				}
				break;
			}
			case 10:{
				return 0;
			}
			default:
				cout << "Invalid choice..\n";	
		}
	}while(1);
	
	return 0;
}
