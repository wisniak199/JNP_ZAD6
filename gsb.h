#ifndef __GSB_H__
#define __GSB_H__

#include <iostream>
#include <map>
#include <vector>

#include "bank.h"
#include "bank_system.h"
#include "bank_builder.h"
#include "bank_account_info.h"
#include "currency.h"
#include "exchange_table.h"
#include "account.h"
#include "planet.h"
#include "citizen.h"

/*enum class Currency {
    ENC,
    BIC,
    DIL,
    LIT,
};*/

Earth earth() {
    static Earth earth;
    return earth;
}

Qonos qonos() {
    static Qonos qonos;
    return qonos;
}

Bynaus bynaus() {
    static Bynaus bynaus;
    return bynaus;
}

// class HistoryEntry {
    // virtual std::string& toString();
// };

/*class ExchangeTable {
    private:
        std::map<Currency, double> courses;
    public:
        ExchangeTable() {
            courses[Currency::ENC] = 1;
            courses[Currency::BIC] = 1;
            courses[Currency::DIL] = 1;
            courses[Currency::LIT] = 1;
        }
        double getExchange(Currency c) const { return courses[c]; }
        void setExchange(Currency c, double newCourse) { courses[c] = newCourse; }
};*/

/*class BankAccountInfo {
    private:
        double monthlyCharge;
        double transferCharge;
        double interestRate;
    public:
        void setMonthlyCharge(double charge);
        double getMonthlyCharge();
        void setTransferCharge(double charge);
        double getTransferCharge();
        void setInterestRate(double rate);
        double getInterestRate();
};*/

/*class Bank {
    protected:
        size_t id;
        size_t nextAccountId;
        std::string myName;
        BankAccountInfo checkingAccountInfo;
        BankAccountInfo savingAccountInfo;
        BankAccountInfo currencyAccountInfo;
        ExchangeTable exchangeTable;
    public:
        void setName(std::string n);
        const ExchangeTable& getExchangeTable() { return exchangeTable; }
};*/

/*class BankBuilder : public Bank {
    private:
        BankAccountInfo *settingAccount;
    public:
        BankBuilder(size_t id);
        BankBuilder& name(std::string n);
        Bank& createBank();
        BankBuilder& checkingAccount();
        BankBuilder& savingAccount();
        BankBuilder& currencyAccount();
        BankBuilder& monthlyCharge(double charge);
        BankBuilder& transferCharge(double charge);
        BankBuilder& interestRate(double rate);
};*/

class gkb {
    private:
        size_t nextId;
        static std::vector<Bank*> banks;
    public:
        BankBuilder& bankApplication();
        void registerBank(Bank* bank);
};


/*class Citizen {
    protected:
        std::string name;
        int id;
    public:
        Citizen(std::string& name, int id) : name(name), id(id) {}
        std::string& getName();
};*/

/*class StandardPlanet {
    protected:
        int nextId;
        std::map<int, Citizen> idToName;

    public:
        virtual Citizen& findCitizen(int id);

        virtual Citizen registerCitizen(std::string& name);
};

class Earth : StandardPlanet {};
class Qonos : StandardPlanet {};*/

#endif /*__GSB_H__*/
