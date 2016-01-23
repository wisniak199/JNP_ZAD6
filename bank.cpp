#include <memory>

#include "account.h"
#include "currency.h"
#include "bank.h"

void Bank::registerAccountID(std::shared_ptr<Account> account) {

}

CheckingAccount& Bank::openCheckingAccount(Citizen c) {
    auto account = std::make_shared<CheckingAccount>(checkingAccountInfo, c, Currency::ENC, *this);
    size_t id = nextAccountId++;
    account->_id.first = this->id;
    account->_id.second = id;
    accounts.emplace(id, account);
    return *account;
}
SavingAccount& Bank::openSavingAccount(Citizen c) {
    auto account = std::make_shared<SavingAccount>(checkingAccountInfo, c, Currency::ENC, *this);
    size_t id = nextAccountId++;
    account->_id.first = this->id;
    account->_id.second = id;
    accounts.emplace(id, account);
    return *account;
}
CurrencyAccount& Bank::openCurrencyAccount(Citizen c, Currency cur) {
    auto account = std::make_shared<CurrencyAccount>(checkingAccountInfo, c, cur, *this);
    size_t id = nextAccountId++;
    account->_id.first = this->id;
    account->_id.second = id;
    accounts.emplace(id, account);
    return *account;
}

void Bank::transferTo(TransferInfo& info) {
    auto account = accounts[info.getTo().second];
    if (account->currency == info.getCurrency()) {
        account->money += info.getMoney();
        account->_history.push_back(HistoryEntryTransfer(info.getMoney(), info.getCurrency(),
                                OperationType::TRANSFER, info.getTitle(), info.getFrom(), info.getTo()));
    } else {
        double toAdd = info.getMoneyENC() / exchangeTable.getBuyRate(account->currency);
        account->money += toAdd;
        account->_history.push_back(HistoryEntryTransfer(toAdd, Currency::ENC, OperationType::TRANSFER,
                                    info.getTitle(), info.getFrom(), info.getTo()));

    }
}

void Bank::transferFrom(TransferInfo& info) {
    auto account = accounts[info.getFrom().second];
    account->money -= info.getMoney();
    account->_history.push_back(HistoryEntryTransfer(info.getMoney(), info.getCurrency(),
                                OperationType::TRANSFER, info.getTitle(), info.getFrom(), info.getTo()));
    double charge = account->info.getTransferCharge();
    if (charge != 0) {
        account->money -= charge / exchangeTable.getBuyRate(account->currency);
        account->_history.push_back(HistoryEntry(charge, Currency::ENC, OperationType::CHARGE));
    }
}

void Bank::monhtlyChargeOfAccounts(){}
