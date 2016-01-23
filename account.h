#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <utility>
#include <vector>

#include "bank_account_info.h"
#include "citizen.h"
#include "history_entry.h"
#include "currency.h"
#include "not_found_error.h"

class Bank; //@@FIXME

// Interfejs do wpłacania pieniądze.
class Depositable {
    virtual void deposit(std::pair<double, Currency> data) = 0;
    virtual void deposit(double money) = 0;
};

// Interfejs do wypłacania pieniędzy.
class Withdrawable {
    virtual void withdraw(std::pair<double, Currency> data) = 0;
    virtual void withdraw(double money) = 0;
};

// Klasa konta. Nie używamy samego Account jako konta. Jest to interfejs, który
//  implementują podklasy Account.
class Account {
    public:
        // Definicja typu identyfikatora.
        // Elementy pary, to odpowiednio numer banku i numer konta.
        using AccountID = std::pair<size_t, size_t>;

    protected:
        // @FIXME Napisać o zależnościach.
        friend class Bank;
        AccountID _id;
        // Informacje o ofercie banku dla danego typu konta.
        BankAccountInfo &info;
        Citizen &owner;
        Currency currency;
        Bank& bank;
        double money; //to do
        std::vector<HistoryEntry> _history;

        std::ostream& write(std::ostream& os) const;

    public:
        Account(BankAccountInfo& info, Citizen& owner, Currency& currency,
                Bank& bank)
                : info(info)
                , owner(owner)
                , currency(currency)
                , bank(bank)
        {}

        // Transfery pieniędzy do konta o numerze 'to'.
        void transfer(const double value, const AccountID to,
                      std::string title = "");

        // Tranfser, gdy adresata znamy tylko z napisu 'to'.
        void transfer(const double value, std::string to,
                      std::string title = "")
        { throw NotFoundError(); }

        const AccountID& id() { return _id; }
        std::string balance() const;
        std::string history() const;
        friend std::ostream& operator<<(std::ostream& os,
                                        const Account& account)
        { return account.write(os); }
};

// Konto oszczędnościowe.
class SavingAccount : public Account {
    public:
        SavingAccount(BankAccountInfo& info, Citizen& owner,
                      Currency cur, Bank& bank)
                : Account(info, owner, cur, bank)
        {}
};

// Konto walutowe.
class CurrencyAccount : public Account, Withdrawable, Depositable {
    Currency currency;
    public:
        CurrencyAccount(BankAccountInfo& info, Citizen& owner, Currency cur,
                        Bank& bank)
                : Account(info, owner, cur, bank)
        {}
        virtual void deposit(std::pair<double, Currency> data) override;
        virtual void deposit(double money) override;
        virtual void withdraw(std::pair<double, Currency> data) override;
        virtual void withdraw(double money) override;
};

// Konto rozliczeniowe.
class CheckingAccount : public Account, Withdrawable, Depositable {
    public:
        CheckingAccount(BankAccountInfo& info, Citizen& owner, Currency cur,
                        Bank& bank)
                : Account(info, owner, cur, bank)
        {}
        virtual void deposit(std::pair<double, Currency> data) override;
        virtual void deposit(double money) override;
        virtual void withdraw(std::pair<double, Currency> data) override;
        virtual void withdraw(double money) override;
};

std::string AccountIDToString(const AccountID& id);

#endif /*__ACCOUNT_H__*/
