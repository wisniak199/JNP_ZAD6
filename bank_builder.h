#ifndef __BANK_BUILDER_H__
#def __BANK_BUILDER_H__

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

#endif /*__BANK_BUILDER_H__*/
