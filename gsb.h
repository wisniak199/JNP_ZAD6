#include <iostream>
#include <map>
#include <vector>

enum class Currency {
    ENC,
    BIC,
    DIL,
    LIT,
};

class BankAccountInfo {
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
};

class Bank {
    protected:
        size_t id;
        size_t nextAccountId;
        std::string myName;
        BankAccountInfo checkingAccountInfo;
        BankAccountInfo savingAccountInfo;
        BankAccountInfo currencyAccountInfo;
    public:
        void setName(std::string n);
};

class BankBuilder : public Bank {
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
};

class gkb {
    private:
        size_t nextId;
        static std::vector<Bank*> banks;
    public:
        BankBuilder& bankApplication();
        void registerBank(Bank* bank);
};


class Citizen {
    protected:
        std::string name;
        int id;
    public:
        Citizen(std::string& name, int id) : name(name), id(id);
        std::string& getName();
};

class StandardPlanet {
    protected:
        int nextId;
        std::map<int, Citizen> idToName;

    public:
        virtual Citizen& findCitizen(int id);

        virtual Citizen registerCitizen(std::string& name)
};

class Earth : StandardPlanet {};
class Qonos : StandardPlanet {};

