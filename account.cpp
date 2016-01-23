#include <iostream>

#include "account.h"
#include "business_error.h"
#include "bank.h"
#include "bank_system.h"

/*******************************************************************************
 * Account
 ******************************************************************************/
void Account::transfer(const double value, const AccountID to,
                       std::string title) {
    if (money < value)
        throw BusinessError();

    double valueENC = value * bank.exchangeTable().getBuyRate(currency);
    TransferInfo info(_id, to, currency, value, valueENC, title);
    bankSystem().makeTransfer(info);
}

std::string Account::balance() const {
    return std::to_string(money) + " " + currencyToString(currency);
}

std::string Account::history() const {
    std::string result;
    for (auto entry : _history)
        result += entry.toString() + "\n";
    return result;
}


std::ostream& Account::write(std::ostream& os) const {
    os << this->balance();
    return os;
}

/*******************************************************************************
 * CurrencyAccount
 ******************************************************************************/
void CurrencyAccount::deposit(std::pair<double, Currency> data) {
    if (data.second != Currency::ENC && data.second != currency)
        throw BusinessError();

    double toAdd;
    // Czy jest potrzeba konwersji waluty.
    if (data.second == Currency::ENC)
        toAdd = data.first / bank.exchangeTable().getSellRate(currency);
    else
        toAdd = data.first;

    money += toAdd;
    _history.push_back(HistoryEntry(toAdd, data.second,
                                    OperationType::DEPOSIT));
}

void CurrencyAccount::deposit(double money) {
    deposit({money, currency});
}

void CurrencyAccount::withdraw(std::pair<double, Currency> data) {
    if (data.second != Currency::ENC && data.second != currency)
        throw BusinessError();

    // Konwersja waluty.
    double toSubtract;
    if (data.second == Currency::ENC)
        toSubtract = data.first / bank.exchangeTable().getBuyRate(currency);
    else
        toSubtract = data.first;

    // Próba pobrania za dużej ilości pieniędzy.
    if (toSubtract > money)
        throw BusinessError();

    money -= toSubtract;
    _history.push_back(HistoryEntry(toSubtract, data.second,
                                    OperationType::WITHDRAWAL));
}

void CurrencyAccount::withdraw(double money) {
    deposit({money, currency});
}

/*******************************************************************************
 * CheckingAccount
 ******************************************************************************/
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

/*******************************************************************************
 * Pozostałe funkcje z headera
 ******************************************************************************/
std::string AccountIDToString(const AccountID& id) {
    return std::to_string(id.first) + "-" + std::to_string(id.second);
}
