#include "bank.h"
#include "bank_system.h"

Bank& BankSystem::addBank(Bank& bank) {
    auto addedBank = banks.emplace(nextId, bank);
    addedBank.first->second.id = nextId++;
    return addedBank.first->second;
}
