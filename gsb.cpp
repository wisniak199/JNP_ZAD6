#include <iostream>
#include <map>
#include <vector>

class Citizen;
class Bank;
class BankBuilder;
class BankAccountInfo;

using AccountID = size_t;

enum class Currency {
    ENC,
    BIC,
    DIL,
    LIT,
};


/******************************************************************************
 * Account
 */

class AccountInfo {};
class Depositanle {

};

class Withdrawable {
    void withdraw(std::pair<double, Currency> data);
    void withdraw(int money);
};


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
};

class CheckingAccount : Account {

};

class CurrencyAccount : Account {

};


/******************************************************************************
 * Bank
 */
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

        // @TODO
        // Account
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


/******************************************************************************
 * gkb
 */

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

/******************************************************************************
 * Citizen
 */
class Citizen {
    protected:
        std::string name;
        int id;
    public:
        Citizen(std::string& name, int id) : name(name), id(id) {}
        std::string& getName() { return name; }
};

/******************************************************************************
 * Planet
 */
class StandardPlanet {
    protected:
        int nextId;
        std::map<int, Citizen> idToName;

    public:
        virtual Citizen& findCitizen(int id) {
            return (*(idToName.find(id))).second;
        }

        virtual Citizen registerCitizen(const std::string& name) {
            Citizen c = Citizen(name, nextId);
            idToName.emplace(nextId, std::move(c));
            nextId++;
            return findCitizen(nextId - 1);
        }
};

/**
 * @TODO Byloby super, gdyby Ziemia rejestrowala EarthCitizen.
 */
class Earth : StandardPlanet {
};
class Qonos : StandardPlanet {};



/******************************************************************************
 * globalne
 */

Earth earth() {
    static Earth earth;
    return earth;
}

Qonos qonos() {
    static Qonos qonos;
    return qonos;
}

int main() {
    // rejestracja obywateli na poszczególnych planetach
    auto& captain = earth().registerCitizen("Jean-Luc Picard");
    // auto& officer = qonos().registerCitizen("Worf");
    // auto& b0 = bynaus().registerCitizen("00000000");
    // auto& b1 = bynaus().registerCitizen("11111111");
    // auto& binarius = bynaus().registerCitizen(b0, b1);

    // // możemy odszukać obywatela, o ile znamy jego identyfikator...
    // auto& found = earth().findCitizen(captain.id());
    // try {
        // auto& spock = earth().findCitizen("SPOCK-ID");
    // } catch (...) {
        // // ...jeśli nie istnieje, to zgłaszany jest wyjątek
        // ::std::cout << "Spock not found" << ::std::endl;
    // }

    // // nowe banki otwieramy poprzez wniosek do Gwiezdnej Komisji Bankowej
    // // hint: wzorzec Builder oraz fluent interface
    // // opłaty zawsze w ENC
    // auto& enterpriseBank = gkb().bankApplication()
        // .name("Enterprise Bank")
        // .checkingAccount()
        // .savingAccount().monthlyCharge(2.00).transferCharge(1.00).interestRate(5)
        // .currencyAccount().transferCharge(2.00).interestRate(1.5)
        // .createBank();
    // // domyślnie brak opłat oraz 0 oprocentowanie
    // auto& raisaBank = gkb().bankApplication()
        // .name("Raisa Bank")
        // .createBank();

    // // możemy otwierać różne rodzaje kont dla obywateli Zjednoczonej Federacji Planet
    // auto& picardsChecking = enterpriseBank.openCheckingAccount(captain);
    // auto& picardsSaving = enterpriseBank.openSavingAccount(captain);
    // auto& binariusCurrency = raisaBank.openCurrencyAccount(binarius, Currency::DIL);

    // // operacje na koncie rozliczeniowym
    // picardsChecking.deposit(101.5);
    // picardsChecking.withdraw({1.5, Currency::ENC});
    // picardsChecking.transfer(100, picardsSaving.id());

    // // operacje na koncie oszczędnościowym
    // picardsSaving.transfer(49.99, binariusCurrency.id(), "for binarius");

    // // przesuwamy kalendarz
    // // odsetki są kapitalizowane miesięcznie pierwszego dnia miesiąca o g. 0
    // // opłaty miesięczne za prowadzenie konta są pobierane pierwszego dnia miesiąca o g. 0
    // interstellarClock().nextMonth().nextDay();

    // // operacje na koncie walutowym
    // // domyślnie kurs jest 1 do 1
    // binariusCurrency.withdraw(1);
    // binariusCurrency.withdraw({1, Currency::ENC});

    // // zmiana kursu waluty i wypłata
    // raisaBank.exchangeTable()
        // .exchangeRate(Currency::DIL).buyingRate(2.0).sellingRate(3.0);
    // binariusCurrency.withdraw({1, Currency::ENC});
    // binariusCurrency.withdraw({1.0, Currency::DIL});

    // // stan konta rozliczeniowego Picarda
    // ::std::cout << picardsChecking.balance() << ::std::endl;
    // ::std::cout << picardsChecking.history() << ::std::endl;

    // // stan konta oszczędnościowego Picarda
    // ::std::cout << picardsSaving << ::std::endl;

    // // stan konta walutowego Binariusa
    // ::std::cout << binariusCurrency << ::std::endl;

    // // próba przelewu na nieistniejące konto...
    // try {
        // binariusCurrency.transfer(1, "Far Far In a Galaxy");
    // } catch (...) {
        // // ...powinna zakończyć się wyjątkiem
        // ::std::cout << "Account not found" << ::std::endl;
    // }
    return 0;
}
