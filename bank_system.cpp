#include <memory>

#include "bank.h"
#include "bank_system.h"
#include "transfer_info.h"

Bank& BankSystem::addBank(Bank& bank) {
    auto b = std::make_shared<Bank>(bank);
    banks.emplace(b->id, b);
    return *b;
}

BankSystem& bankSystem() {
    static BankSystem system;
    return system;
}

void BankSystem::makeTransfer(TransferInfo& info) {
    banks[info.getFrom().first]->transferFrom(info);
    banks[info.getTo().first]->transferTo(info);
}

void BankSystem::monthlyCharge() {
    for (auto& bank : banks)
        bank.second->monthlyChargeOfAccounts();
}
