#include <memory>

#include "bank.h"
#include "bank_system.h"
#include "transfer_info.h"
#include "business_error.h"

// Dodwania banku do listy banków w systemie.
Bank& BankSystem::addBank(Bank& bank) {
    auto b = std::make_shared<Bank>(bank);
    banks.emplace(b->id, b);
    return *b;
}

BankSystem& bankSystem() {
    static BankSystem system;
    return system;
}

// Zarządzanie przelewami.
void BankSystem::makeTransfer(TransferInfo& info) {
    if (banks.find(info.getFrom().first) == banks.end() ||
        banks.find(info.getTo().first) == banks.end())
        throw BusinessError();

    if (!(banks[info.getFrom().first]->accountExist(info.getFrom()) &&
          banks[info.getTo().first]->accountExist(info.getTo())))
        throw BusinessError();

    banks[info.getFrom().first]->transferFrom(info);
    banks[info.getTo().first]->transferTo(info);
}

// Budzenie banków do pobrania opłat.
void BankSystem::monthlyCharge() {
    for (auto& bank : banks)
        bank.second->monthlyChargeOfAccounts();
}

// Budzenie banków do przyznania odsetek.
void BankSystem::monthlyInterestGiveAway() {
    for (auto& bank : banks)
        bank.second->monthlyInterestGiveAway();
}
