#ifndef __BANK_SYSTEM_H__
#define __BANK_SYSTEM_H__

#include <memory>

#include "bank.h"
#include "transfer_info.h"

class BankSystem {
    protected:
        friend class BankBuilder;
        std::map<Bank::BankID, std::shared_ptr<Bank>> banks;
        Bank& addBank(Bank& bank);
        void monthlyCharge();
    public:
        void makeTransfer(TransferInfo& info);
};

BankSystem& bankSystem();

#endif /*__BANK_SYSTEM_H__*/
