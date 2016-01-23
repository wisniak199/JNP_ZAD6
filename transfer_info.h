#ifndef __TRANSFER_INFO_H__
#define __TRANSFER_INFO_H__

#include <iostream>
#include "account.h"

// Informacje dla transferów. Nic ciekawego. 
class TransferInfo {
    private:
        Account::AccountID _from, _to;
        Currency _currency;
        double _money;
        double _moneyENC;
        std::string _title;

    public:
        TransferInfo(Account::AccountID from, Account::AccountID to,
                    Currency currency, double money, double moneyENC,
                    std::string& title)
                : _from(from)
                , _to(to)
                , _currency(currency)
                , _money(money)
                , _moneyENC(moneyENC)
                , _title(title)
        {}
        Account::AccountID& getFrom() { return _from; }
        Account::AccountID& getTo() { return _to; }
        Currency getCurrency() { return _currency; }
        double getMoney() { return _money; }
        double getMoneyENC() { return  _moneyENC; }
        std::string& getTitle() { return _title; }
};

#endif /*__TRANSFER_INFO_H__*/
