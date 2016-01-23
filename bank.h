#ifndef __BANK_H__
#define __BANK_H__
#include <iostream>
#include <memory>

#include "bank_account_info.h"
#include "exchange_table.h"
#include "account.h"
#include "transfer_info.h"

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
        std::map<size_t, std::shared_ptr<Account>> accounts;
        void registerAccountID(Account& account);
        void monhtlyChargeOfAccounts();

    public:
        void setName(std::string n) {myName = n;}
        const ExchangeTable& getExchangeTable() { return exchangeTable; }
        CheckingAccount& openCheckingAccount(Citizen c);
        SavingAccount& openSavingAccount(Citizen c);
        CurrencyAccount& openCurrencyAccount(Citizen c, Currency cur);
        void registerAccountID(std::shared_ptr<Account> account);
        void transferTo(TransferInfo& info);
        void transferFrom(TransferInfo& info);
        void monhtlyChargeOfAccounts();
        bool accountExist(Account::AccountID id);
        // @TODO
        // Account
};

#endif /*__BANK_H__*/
