#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <utility>
#include <vector>

#include "bank_account_info.h"
#include "citizen.h"
#include "history_entry.h"
#include "currency.h"

class Bank;

class Depositable {
    virtual void deposit(std::pair<double, Currency> data) = 0;
    virtual void deposit(double money) = 0;
};

class Withdrawable {
    virtual void withdraw(std::pair<double, Currency> data) = 0;
    virtual void withdraw(double money) = 0;
};

class Account {
    public:
        using AccountID = std::pair<size_t, size_t>;
    protected:
        friend class Bank;
        AccountID id;
        BankAccountInfo &info;
        Citizen &owner;
        Currency currency;
        Bank& bank;
        double money; //to do
        std::vector<HistoryEntry> history;

    public:
    Account(BankAccountInfo& info, Citizen& owner, Currency& currency, Bank& bank) :
                                            info(info), owner(owner), currency(currency), bank(bank) {}
    //pure virtual
    //virtual void transfer(const double money, const AccountID id, const std::string& title) = 0;
};

class SavingAccount : public Account {
    public:
        SavingAccount(BankAccountInfo& info, Citizen& owner, Currency cur, Bank& bank) : Account(info, owner, cur, bank) {}
        //virtual void transfer(const double money, const AccountID id, const std::string& title) override;
};

class CurrencyAccount : public Account, Withdrawable, Depositable {
    Currency currency;
    public:
        CurrencyAccount(BankAccountInfo& info, Citizen& owner, Currency cur, Bank& bank) : Account(info, owner, cur, bank) {}

        virtual void deposit(std::pair<double, Currency> data) override;

        virtual void deposit(double money) override;

        virtual void withdraw(std::pair<double, Currency> data) override;

        virtual void withdraw(double money) override;

        //virtual void transfer(const double money, const AccountID id, const std::string& title) override;
};

class CheckingAccount : public Account, Withdrawable, Depositable {
    public:
        CheckingAccount(BankAccountInfo& info, Citizen& owner, Currency cur, Bank& bank) : Account(info, owner, cur, bank) {}

        virtual void deposit(std::pair<double, Currency> data) override;

        virtual void deposit(double money) override;

        virtual void withdraw(std::pair<double, Currency> data) override;
        virtual void withdraw(double money) override;

        //virtual void transfer(const double money, const AccountID id, const std::string& title) override;
};

#endif /*__ACCOUNT_H__*/
