#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <vector>

#include "bank.h"
#include "bank_account_info.h"
#include "citizen.h"

using AccountID = size_t;
#include "history_entry.h"


class Depositable {
    virtual void deposit(std::pair<double, Currency> data) = 0;
    virtual void deposit(double money) = 0;
};

class Withdrawable {
    virtual void withdraw(std::pair<double, Currency> data) = 0;
    virtual void withdraw(double money) = 0;
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
    //pure virtual
    virtual void transfer(const double money, const AccountID id, const std::string& title) = 0;
};

class CheckingAccount : Account {
    public:
        CheckingAccount(BankAccountInfo& info, Citizen& owner, Bank& bank) : Account(info, owner, bank) {}
    //virtual void transfer(const double money, const AccountID id, const std::string& title) override;
};

class CurrencyAccount : Account, Withdrawable, Depositable {
    Currency currency;
    public:
        CurrencyAccount(BankAccountInfo& info, Citizen& owner, Bank& bank) : Account(info, owner, bank) {}

        virtual void deposit(std::pair<double, Currency> data) override;

        virtual void deposit(double money) override;

        virtual void withdraw(std::pair<double, Currency> data) override;

        virtual void withdraw(double money) override;
};

class SavingAccount : Account, Withdrawable, Depositable {
    public:
        SavingAccount(BankAccountInfo& info, Citizen& owner, Bank& bank) : Account(info, owner, bank) {}

        virtual void deposit(std::pair<double, Currency> data) override;

        virtual void deposit(double money) override;

        virtual void withdraw(std::pair<double, Currency> data) override;
        virtual void withdraw(double money) override;
};

#endif /*__ACCOUNT_H__*/
