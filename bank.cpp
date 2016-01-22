#include <memory>

#include "account.h"
#include "currency.h"
#include "bank.h"

void Bank::registerAccountID(std::shared_ptr<Account> account) {

}
CheckingAccount& Bank::openCheckingAccount(Citizen c) {
    auto account = std::make_shared<CheckingAccount>(checkingAccountInfo, c, Currency::ENC);
    size_t id = nextAccountId++;
    account->id.first = this->id;
    account->id.second = id;
    accounts.emplace(id, account);
    return *account;
}
SavingAccount& Bank::openSavingAccount(Citizen c) {
    auto account = std::make_shared<SavingAccount>(checkingAccountInfo, c, Currency::ENC);
    size_t id = nextAccountId++;
    account->id.first = this->id;
    account->id.second = id;
    accounts.emplace(id, account);
    return *account;
}
CurrencyAccount& Bank::openCurrencyAccount(Citizen c, Currency cur) {
    auto account = std::make_shared<CurrencyAccount>(checkingAccountInfo, c, cur);
    size_t id = nextAccountId++;
    account->id.first = this->id;
    account->id.second = id;
    accounts.emplace(id, account);
    return *account;
}
