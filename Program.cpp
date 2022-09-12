#include <iostream>
#include "IAccount.h"
#include "AccountManager.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include "CustomConsole.h"
#include "AccountFactory.h"

using namespace std;
using namespace BOS;

int main() {
	//Account Manager Instance
	AccountManager accManager;
	
	//AccountFactory Singleton Instance
	AccountFactory* accFactory = AccountFactory::createFactoryInstance();
	
	//Pointer of type belonging to parent Interface of Account
	IAccount* iacc;
	while(1) {
		int choice;
		cout << "------------------------------------------------------------" << endl;
		cout << "\tBank-of-Success MENU" << endl;
		cout << "------------------------------------------------------------" << endl;
		cout << "1. Create an Account" << endl;
		cout << "2. Close an Account" << endl;
		cout << "3. Deposit Money into Account" << endl;
		cout << "4. Withdraw Money out of Account" << endl;
		cout << "5. Display all Accounts" << endl;
		cout << "6. Print Transaction Logs" << endl;
		cout << "7. Exit Menu" << endl;
		cout << "Please enter your choice: ";
		choice = CustomConsole::ReadInt();
		
		switch(choice) {
			case 1:	
				accManager.openAccount(accFactory->createAccount());
				/*The Account Factory creates our Account(either Savings or Current Account) and gives it to Account Manager so that he can open that Account(store it in his data structure) */
				break;
			case 2: 
				cout << "Enter the Account No of the account you want to close: ";
				iacc = accManager.getAccount(CustomConsole::ReadLong());
				if(iacc != nullptr) {
					iacc->closeAccount();
				}
				/*We will ask the Account Manager to search and get the account if it exists and we close it using upcasting and calling the implemented method in child of Interface */
				break;
			case 3:
				cout << "Enter your Account Number: ";
				iacc = accManager.getAccount(CustomConsole::ReadLong());
				if(iacc != nullptr) {
					Account* acc = dynamic_cast<Account*>(iacc);
				
					cout << "Enter amount you want to deposit: ";
					double amt = CustomConsole::ReadDouble();
					if(acc->deposit(amt)) {
						//Take Current Date to insert into log
						string log = to_string(acc->getAccNumber()) + " has deposited " + to_string(amt) + "\n";
						accManager.appendTransferLog(log);
					}
					else {
						cout << "Deposit has failed!" << endl;
					}
				}	
				break;
			case 4:
				cout << "Enter your Account Number: ";
				iacc = accManager.getAccount(CustomConsole::ReadLong());
				if(iacc != nullptr) {
					Account* acc = dynamic_cast<Account*>(iacc);
				
					cout << "Enter amount you want to withdraw: ";
					double amt = CustomConsole::ReadDouble();
					if(acc->withdraw(amt)) {
						//Take Current Date to insert into log
						string log = to_string(acc->getAccNumber()) + " has withdrew " + to_string(amt) + "\n";
						accManager.appendTransferLog(log);
					}
					else {
						cout << "Withdraw has failed!" << endl;
					}
				}
				break;
			case 5:
				accManager.displayAccounts();
				/* The Account Manager goes into his data structure and displays every account in it */
				break;
			case 6: accManager.printTransferLog();
				break;
			default:
				break;
		}
		if(choice == 7) break;
	}
	return 0;
}
