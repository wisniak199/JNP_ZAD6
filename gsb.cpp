#include <iostream>
#include <map>

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
        void setMonthlyCharge(double charge) { monthlyCharge = charge;}
        double getMonthlyCharge() {return monthlyCharge;}
        void setTransferCharge(double charge) { transferCharge = charge;}
        double getTransferCharge() {return transferCharge;}
        void setInterestRate(double rate) {interestRate = rate;}
        double getInterestRate() {return interestRate;}
};

class Bank {
    protected:
        std::string myName;
        BankAccountInfo checkingAccountInfo;
        BankAccountInfo savingAccountInfo;
        BankAccountInfo currencyAccountInfo;
    public:
        void setName(std::string n) {myName = n;}
};

class BankBuilder : public Bank {
    private:
        BankAccountInfo *settingAccount;
    public:
        BankBuilder() { settingAccount = &checkingAccountInfo; }

        BankBuilder& name(std::string n) {
            setName(n);
            return *this;
        }

        Bank& createBank() {
            return *this;
        }

        BankBuilder& checkingAccount() {
            settingAccount = &checkingAccountInfo;
            return *this;
        }

        BankBuilder& savingAccount() {
            settingAccount = &savingAccountInfo;
            return *this;
        }

        BankBuilder& currencyAccount() {
            settingAccount = &currencyAccountInfo;
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
    public:
        BankBuilder bankApplication() {
            return BankBuilder();
        }
};

int main() {
    auto& enterpriseBank = gkb().bankApplication()
        .name("Enterprise Bank")
        .savingAccount().monthlyCharge(2.00).transferCharge(1.00).interestRate(5)
        .currencyAccount().transferCharge(2.00).interestRate(1.5)
        .createBank();
    return 0;
}
