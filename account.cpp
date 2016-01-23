#include "account.h"
#include "business_error.h"
#include "bank.h"

//CurrencyAccount

void CurrencyAccount::deposit(std::pair<double, Currency> data) {
    if (data.second != Currency::ENC && data.second != currency)
        throw BusinessError();

    double toAdd;
    if (data.second == Currency::ENC)
        toAdd = data.first / bank.getExchangeTable().getSellRate(currency);
    else
        toAdd = data.first;
    money += toAdd;
    history.push_back(HistoryEntry(toAdd, data.second, OperationType::DEPOSIT));
}

void CurrencyAccount::deposit(double money) {
    deposit({money, currency});
}

void CurrencyAccount::withdraw(std::pair<double, Currency> data) {
    if (data.second != Currency::ENC && data.second != currency)
        throw BusinessError();

    double toSubtract;
    if (data.second == Currency::ENC)
        toSubtract = data.first / bank.getExchangeTable().getBuyRate(currency);
    else
        toSubtract = data.first;
    if (toSubtract > money)
        throw BusinessError();
    money -= toSubtract;
    history.push_back(HistoryEntry(toSubtract, data.second, OperationType::WITHDRAWAL));
}

void CurrencyAccount::withdraw(double money) {
    deposit({money, currency});
}


// CHecking

void CheckingAccount::deposit(std::pair<double, Currency> data) {
    if (data.second != Currency::ENC)
        throw BusinessError();

    money += data.first;
    history.push_back(HistoryEntry(data.first, data.second, OperationType::DEPOSIT));
}

void CheckingAccount::deposit(double money) {
    deposit({money, Currency::ENC});
}

void CheckingAccount::withdraw(std::pair<double, Currency> data) {
    if (data.first > money || data.second != Currency::ENC)
        throw BusinessError();

    money -= data.first;
    history.push_back(HistoryEntry(data.first, data.second, OperationType::WITHDRAWAL));
}

void CheckingAccount::withdraw(double money) {
    withdraw({money, Currency::ENC});
}

//virtual void transfer(const double money, const AccountID id, const std::string& title) override;
