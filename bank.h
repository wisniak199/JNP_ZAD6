#ifndef __BANK_H__
#define __BANK_H__
#include <iostream>

#include "bank_account_info.h"
#include "exchange_table.h"

class Bank {
    public:
        using BankID = size_t;
    protected:
        friend class BankBuilder;
        friend class BankSystem;
        BankID id;
        size_t nextAccountId;
        std::string myName;
        BankAccountInfo checkingAccountInfo;
        BankAccountInfo savingAccountInfo;
        BankAccountInfo currencyAccountInfo;
        ExchangeTable exchangeTable;
    public:
        void setName(std::string n) {myName = n;}
        const ExchangeTable& getExchangeTable() { return exchangeTable; }
        // @TODO
        // Account
};

#endif /*__BANK_H__*/
