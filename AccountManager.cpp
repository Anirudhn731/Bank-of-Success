#include <iostream>
#include <map>
#include <vector>
#include "AccountManager.h"
#include "Account.h"

using namespace std;

namespace BOS {
		
	void AccountManager::printTransferLog() {
		cout << _transferLog << endl;
	}
	
	void AccountManager::openAccount(Account* account) {
		if(account != nullptr) 
			_accounts.insert({account->getAccNumber(), account});
	}
	
	Account* AccountManager::getAccount(long accNumber) {
		if(_accounts.find(accNumber) != _accounts.end())
			return _accounts[accNumber];
		else {
			cout << "Alas! Your Account cannot be found!" << endl;
			return nullptr;
		}
	}
	
	void AccountManager::displayAccounts() {
		cout << "------------------------------------------------------------" << endl;
		cout << "AccNo" << "\t";
		cout << "Holder Name" << "\t";
		cout << "Balance" << "\t";
		cout << "Privelege" << "\t";
		cout << "isActive?" << "\t";
		cout << "Activation Date" << "\t";
		cout << "Closing Date" << endl;
		cout << "------------------------------------------------------------" << endl;
		
		for(auto iter = _accounts.begin(); iter != _accounts.end(); iter++) {
			cout << iter->first << "\t";
			cout << (iter->second)->getName() << "\t\t";
			cout << (iter->second)->getBalance() << "\t";
			cout << (iter->second)->getBuiltPrivilege() << "\t\t";
			cout << (iter->second)->getIsActive() << "\t\t";
			cout << (iter->second)->getActivationDate() << "\t";
			cout << (iter->second)->getClosingDate() << endl;
		}
	}
	
	void AccountManager::appendTransferLog(string log) {
		_transferLog += log;
	}
	
	AccountManager::~AccountManager() {}
}
