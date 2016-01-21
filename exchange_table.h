#ifndef __EXCHANGE_TABLE_H__
#define __EXCHANGE_TABLE_H__

#include <map>

#include "currency.h"

class ExchangeTable {
    private:
        std::map<Currency, double> rates;
    public:
        ExchangeTable() {
            rates[Currency::ENC] = 1;
            rates[Currency::BIC] = 1;
            rates[Currency::DIL] = 1;
            rates[Currency::LIT] = 1;
        }
        double getExchange(Currency c) const { return rates.find(c)->second; }
        void setExchange(Currency c, double newRate) { rates[c] = newRate; }
};

#endif /*__EXCHANGE_TABLE_H__*/
