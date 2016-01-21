#ifndef __BANK_ACCOUNT_INFO_H__
#define __BANK_ACCOUNT_INFO_H__

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

#endif /*__BANK_ACCOUNT_INFO_H__*/
