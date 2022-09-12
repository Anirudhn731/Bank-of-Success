#include <iostream>
#include <ctime>
#include <string>
#include "AccountFactory.h"
#include "Account.h"
#include "CustomConsole.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"

using namespace std;

namespace BOS{

	int AccountFactory::_count = 0;
	AccountFactory* AccountFactory::_instance = 0;
	
	AccountFactory::~AccountFactory() {}
	
	AccountFactory* AccountFactory::createFactoryInstance() {
		AccountFactory* af;
		if(_count == 0) {
			af = new AccountFactory();
			_instance = af;
		}
		else {
			af = _instance;
		}
		
		return af;
	}

    Account* AccountFactory::createSavingsAccount() {
    	Account* acc;
	cout << "Enter DOB(dd/mm/yyyy): ";
	string dob = CustomConsole::ReadString();
	
	time_t time = std::time(nullptr);
	tm* now = localtime(&time);
	int curr_year = (now->tm_year + 1900);
	int dob_year = stoi(dob.substr(6, 4));
		
	if((curr_year - dob_year) < 18) {
		cout << "Age is less than 18!" << endl;
		cout << "Cannot process Account creation!" << endl;
		acc = nullptr;
		return acc;
	}
        else {
               	acc = new SavingsAccount(dob);
               	return acc;
        }    	
    }
    
    Account* AccountFactory::createCurrentAccount() {
    	Account* acc;
    	cout << "Enter Company Registration Number: ";
    	long regNo = CustomConsole::ReadLong();
    	if(regNo) {
               	acc = new CurrentAccount(regNo);
               	return acc;
        }
        else {
               	cout << "Company Registration Number cannot be null!" << endl;
               	cout << "Cannot process Account creation!" << endl;
               	acc = nullptr;
               	return acc;
        }
    }

    Account* AccountFactory::createAccount(){
        Account* acc;
        int choice = 0;
        std::cout<<"Enter the type of Account you want to create: \n 1. Savings \n 2. Current\n";
        cout << "Please enter your choice: ";
        choice = CustomConsole::ReadInt();

        switch(choice){
            case 1:
            	return this->createSavingsAccount();
                break;
            case 2:
                return this->createCurrentAccount();
                break;
            default:
                std::cout<<"Invalid Choice!"<<std::endl;
        }
        
        return AccountFactory::createAccount();
    }
}
