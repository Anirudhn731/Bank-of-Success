#pragma once

#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"

namespace BOS{

    class AccountFactory{
    	    static int _count;
    	    Account* createSavingsAccount();
    	    Account* createCurrentAccount();
    	    static AccountFactory* _instance;
            AccountFactory(){
                //empty
            }
        public:
            Account* createAccount();
            static AccountFactory* createFactoryInstance();
            ~AccountFactory();
    };

}
