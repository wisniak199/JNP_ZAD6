#include <iostream>

#include "account.h"
#include "business_error.h"
#include "bank.h"
#include "bank_system.h"

void Account::transfer(const double value, const AccountID to, std::string title) {
    if (money < value)
        throw BusinessError();
    double valueENC = value * bank.getExchangeTable().getBuyRate(currency);
    TransferInfo info(_id, to, currency, value, valueENC, title);
    bankSystem().makeTransfer(info);
}

std::string Account::balance() {
    return std::to_string(money) + " " + currencyToString(currency);
}

std::string Account::history() {
    std::string result;
    for (auto entry : _history)
        result += entry.toString() + "\n";
    return result;
}

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
    _history.push_back(HistoryEntry(toAdd, data.second, OperationType::DEPOSIT));
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
    _history.push_back(HistoryEntry(toSubtract, data.second, OperationType::WITHDRAWAL));
}

void CurrencyAccount::withdraw(double money) {
    deposit({money, currency});
}


// CHecking

void CheckingAccount::deposit(std::pair<double, Currency> data) {
    if (data.second != Currency::ENC)
        throw BusinessError();

    money += data.first;
    _history.push_back(HistoryEntry(data.first, data.second, OperationType::DEPOSIT));
}

void CheckingAccount::deposit(double money) {
    deposit({money, Currency::ENC});
}

void CheckingAccount::withdraw(std::pair<double, Currency> data) {
    if (data.first > money || data.second != Currency::ENC)
        throw BusinessError();

    money -= data.first;
    _history.push_back(HistoryEntry(data.first, data.second, OperationType::WITHDRAWAL));
}

void CheckingAccount::withdraw(double money) {
    withdraw({money, Currency::ENC});
}

std::string AccountIDToString(const AccountID& id) {
    return std::to_string(id.first) + "-" + std::to_string(id.second);
}

