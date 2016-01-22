#include <memory>

#include "bank.h"
#include "bank_system.h"

Bank& BankSystem::addBank(Bank& bank) {
    auto b = std::make_shared<Bank>(bank);
    banks.emplace(b->id, b);
    return *b;
}

BankSystem& bankSystem() {
    static BankSystem system;
    return system;
}
