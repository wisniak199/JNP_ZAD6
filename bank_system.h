#ifndef __BANK_SYSTEM_H__
#define __BANK_SYSTEM_H__

class BankSystem {
    protected:
        friend class BankBuilder;
        static size_t nextId;
        static std::map<size_t, Bank> banks;
        static Bank& addBank(Bank& bank);
};

#endif /*__BANK_SYSTEM_H__*/
