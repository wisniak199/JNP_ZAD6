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
        AccountID _id;
        BankAccountInfo &info;
        Citizen &owner;
        Currency currency;
        Bank& bank;
        double money; //to do
        std::vector<HistoryEntry> _history;

        std::ostream& write(std::ostream& os) const;

    public:
    Account(BankAccountInfo& info, Citizen& owner, Currency& currency, Bank& bank) :
                                            info(info), owner(owner), currency(currency), bank(bank) {}

    void transfer(const double value, const AccountID to, std::string title = "");
    const AccountID& id() { return _id; }
    std::string balance() const;
    std::string history() const;

    friend std::ostream& operator<<(std::ostream& os, const Account& account) {
        return account.write(os);
    }
};

class SavingAccount : public Account {
    public:
        SavingAccount(BankAccountInfo& info, Citizen& owner, Currency cur, Bank& bank) : Account(info, owner, cur, bank) {}
};

class CurrencyAccount : public Account, Withdrawable, Depositable {
    Currency currency;
    public:
        CurrencyAccount(BankAccountInfo& info, Citizen& owner, Currency cur, Bank& bank) : Account(info, owner, cur, bank) {}

        virtual void deposit(std::pair<double, Currency> data) override;

        virtual void deposit(double money) override;

        virtual void withdraw(std::pair<double, Currency> data) override;

        virtual void withdraw(double money) override;
};

class CheckingAccount : public Account, Withdrawable, Depositable {
    public:
        CheckingAccount(BankAccountInfo& info, Citizen& owner, Currency cur, Bank& bank) : Account(info, owner, cur, bank) {}

        virtual void deposit(std::pair<double, Currency> data) override;

        virtual void deposit(double money) override;

        virtual void withdraw(std::pair<double, Currency> data) override;
        virtual void withdraw(double money) override;
};

std::string AccountIDToString(const AccountID& id);

#endif /*__ACCOUNT_H__*/
