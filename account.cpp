#include "account.h"
#include "business_error.h"

//CurrencyAccount

void CurrencyAccount::deposit(std::pair<double, Currency> data) {
    if (data.second != Currency::ENC && data.second != currency)
        throw BusinessError();

    if (data.second == Currency::ENC)
        money += data.first;// / bank.getExchangeTable().getExchange(currency);
    else
        money += data.first;
    //to do - dodac do historii
}

void CurrencyAccount::deposit(double money) {
    deposit({money, currency});
}

void CurrencyAccount::withdraw(std::pair<double, Currency> data) {
    if (data.second != Currency::ENC && data.second != currency)
        throw BusinessError();

    if (data.second == Currency::ENC)
        money -= data.first;// / bank.getExchangeTable().getExchange(currency);
    else
        money -= data.first;
    //to do - dodac do historii
}

void CurrencyAccount::withdraw(double money) {
    deposit({money, currency});
}


//SavingAccount

void SavingAccount::deposit(std::pair<double, Currency> data) {
    if (data.second != Currency::ENC)
        throw BusinessError();

    money += data.first;
    //to do - dodac do historii
}

void SavingAccount::deposit(double money) {
    deposit({money, Currency::ENC});
}

void SavingAccount::withdraw(std::pair<double, Currency> data) {
    if (data.first > money || data.second != Currency::ENC)
        throw BusinessError();

    money -= data.first;
    //to do - dodac do historii
}

void SavingAccount::withdraw(double money) {
    withdraw({money, Currency::ENC});
}

//virtual void transfer(const double money, const AccountID id, const std::string& title) override;
