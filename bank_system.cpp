#include "bank.h"
#include "bank_system.h"

size_t BankSystem::nextId = 0;
std::map<size_t, Bank> BankSystem::banks;

Bank& BankSystem::addBank(Bank& bank) {
    auto addedBank = banks.emplace(nextId, bank);
    addedBank.first->second.id = nextId++;
    return addedBank.first->second;
}
