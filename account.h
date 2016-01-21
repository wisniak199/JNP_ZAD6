#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <vector>

#include "bank.h"
#include "bank_account_info.h"
#include "citizen.h"
#include "history_entry.h"

using AccountID = size_t;
class Depositable {
    virtual void deposit(std::pair<double, Currency> data);
    virtual void deposit(double money);
};

class Withdrawable {
    virtual void withdraw(std::pair<double, Currency> data);
    virtual void withdraw(double money);
};

class Account {
    protected:
        friend class Bank;
        BankAccountInfo &info;
        Citizen &owner;
        Bank &bank;
        double money; //to do
        std::vector<HistoryEntry> history;

    public:
    Account(BankAccountInfo& info, Citizen& owner, Bank& bank) : info(info), owner(owner), bank(bank) {}
    virtual void transfer(const double money, const AccountID id, const std::string& title);
};

class CheckingAccount : Account {
    public:
        CheckingAccount(BankAccountInfo& info, Citizen& owner, Bank& bank) : Account(info, owner, bank) {}
    virtual void transfer(const double money, const AccountID id, const std::string& title);
};

class CurrencyAccount : Account, Withdrawable, Depositable {
    Currency currency;
    public:
        CurrencyAccount(BankAccountInfo& info, Citizen& owner, Bank& bank) : Account(info, owner, bank) {}

        virtual void deposit(std::pair<double, Currency> data);

        virtual void deposit(double money);

        virtual void withdraw(std::pair<double, Currency> data);

        virtual void withdraw(double money);
};

class SavingAccount : Account, Withdrawable, Depositable {
    public:
        SavingAccount(BankAccountInfo& info, Citizen& owner, Bank& bank) : Account(info, owner, bank) {}

        virtual void deposit(std::pair<double, Currency> data);

        virtual void deposit(double money);

        virtual void withdraw(std::pair<double, Currency> data);
        virtual void withdraw(double money);
};

#endif /*__ACCOUNT_H__*/
