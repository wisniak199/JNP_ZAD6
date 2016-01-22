#ifndef __BANK_SYSTEM_H__
#define __BANK_SYSTEM_H__

#include <memory>

#include "bank.h"

class BankSystem {
    protected:
        friend class BankBuilder;
        std::map<Bank::BankID, std::shared_ptr<Bank>> banks;
        Bank& addBank(Bank& bank);
};

BankSystem& bankSystem();

#endif /*__BANK_SYSTEM_H__*/
