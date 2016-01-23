#ifndef __BANK_BUILDER_H__
#define __BANK_BUILDER_H__

#include "bank.h"
#include "bank_system.h"

// Budowanie banku.
class BankBuilder {
    private:
        // Kolejne wolne ID do przypisania nowemu bankowi.
        Bank::BankID nextID;

        // Szablon dla banku, który modyfikujemy podczas tworzenia nowej
        //  instancji banku.
        Bank bankTemplate;

        // Parametry nowego banku.
        BankAccountInfo *settingAccount;

    public:
        BankBuilder() { settingAccount = &bankTemplate.checkingAccountInfo; }

        BankBuilder& name(const std::string& n) {
            bankTemplate.myName = n;
            return *this;
        }

        Bank& createBank() {
            bankTemplate.id = nextID++;
            return bankSystem().addBank(bankTemplate);
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

BankBuilder& bankBuilder();

#endif /*__BANK_BUILDER_H__*/
