#include <iostream>
#include <map>
#include <vector>

class Bank;
class BankBuilder;
class BankAccountInfo;

using AccountID = size_t;

class Depositanle {

}

class Withdrawable {
    void withdraw(std::pair<double, Currency> data)
    void withdraw(int money);
}


class Account {
    private:
        friend class Bank;
        AccountInfo &info;
        Citizen &owner;
        Bank &bank;
        int money; //to do

    public:
    void transfer(const double money, const AccountID id, const std::string& title) {

    }
}

class CheckingAccount : Account {

}

class CurrencyAccount : Account {

}

class
class BankAccountInfo {
    private:
        double monthlyCharge;
        double transferCharge;
        double interestRate;


    public:
        void setMonthlyCharge(double charge) { monthlyCharge = charge;}
        double getMonthlyCharge() {return monthlyCharge;}
        void setTransferCharge(double charge) { transferCharge = charge;}
        double getTransferCharge() {return transferCharge;}
        void setInterestRate(double rate) {interestRate = rate;}
        double getInterestRate() {return interestRate;}
};

class Bank {
    protected:
        friend class BankBuilder;
        friend class BankSystem;
        size_t id;
        size_t nextAccountId;
        std::string myName;
        BankAccountInfo checkingAccountInfo;
        BankAccountInfo savingAccountInfo;
        BankAccountInfo currencyAccountInfo;
    public:
        void setName(std::string n) {myName = n;}

        Account
};

class BankSystem {
    protected:
        friend class BankBuilder;
        static size_t nextId;
        static std::map<size_t, Bank> banks;
        static Bank& addBank(Bank& bank) {
            auto addedBank = banks.emplace(nextId, bank);
            addedBank.first->second.id = nextId++;
            return addedBank.first->second;
        }
};

enum class Currency {
    ENC,
    BIC,
    DIL,
    LIT,
};

class BankBuilder {
    private:
        static Bank bankTemplate;
        BankAccountInfo *settingAccount;
    public:
        BankBuilder() { settingAccount = &bankTemplate.checkingAccountInfo; }

        BankBuilder& name(const std::string& n) {
            bankTemplate.myName = n;
            return *this;
        }

        Bank& createBank() {
            return BankSystem::addBank(bankTemplate);
        }

        BankBuilder& checkingAccount() {
            settingAccount = &bankTemplate.checkingAccountInfo;
            return *this;
        }

        BankBuilder& savingAccount() {
            settingAccount = &bankTemplate.savingAccountInfo;
            return *this;
        }

        BankBuilder& currencyAccount() {
            settingAccount = &bankTemplate.currencyAccountInfo;
            return *this;
        }

        BankBuilder& monthlyCharge(double charge) {
            settingAccount->setMonthlyCharge(charge);
            return *this;
        }

        BankBuilder& transferCharge(double charge) {
            settingAccount->setTransferCharge(charge);
            return *this;
        }

        BankBuilder& interestRate(double rate) {
            settingAccount->setInterestRate(rate);
            return *this;
        }
};


class gkb {
    /*private:
        size_t nextId;
        static std::vector<Bank*> banks;
    public:
        BankBuilder& bankApplication() { //refernecja moze psuc
            return BankBuilder();
        }

        void registerBank(Bank* bank) {

        }*/

};


class Citizen {
    protected:
        std::string name;
        int id;
    public:
        Citizen(std::string& name, int id) : name(name), id(id) {}
        std::string& getName() { return name; }
};

class StandardPlanet {
    protected:
        int nextId;
        std::map<int, Citizen> idToName;

    public:
        virtual Citizen& findCitizen(int id) {
            return (*(idToName.find(id))).second;
        }

        virtual Citizen registerCitizen(std::string& name) {
            Citizen c = Citizen(name, nextId);
            idToName.emplace(nextId, std::move(c));
            nextId++;
            return findCitizen(nextId - 1);
        }
};

class Earth : StandardPlanet {};
class Qonos : StandardPlanet {};


int main() {
    /*auto& enterpriseBank = gkb().bankApplication()
        .name("Enterprise Bank")
        .savingAccount().monthlyCharge(2.00).transferCharge(1.00).interestRate(5)
        .currencyAccount().transferCharge(2.00).interestRate(1.5)
        .createBank();*/
    return 0;
}
