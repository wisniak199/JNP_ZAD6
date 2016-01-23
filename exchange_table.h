#ifndef __EXCHANGE_TABLE_H__
#define __EXCHANGE_TABLE_H__

#include <map>

#include "currency.h"

class ExchangeTable {
    private:
        std::map<Currency, double> buyRates;
        std::map<Currency, double> sellRates;
        Currency _settingCurrency;
    public:
        ExchangeTable() {
            _settingCurrency = Currency::ENC;
            buyRates[Currency::ENC] = 1;
            buyRates[Currency::BIC] = 1;
            buyRates[Currency::DIL] = 1;
            buyRates[Currency::LIT] = 1;
            sellRates[Currency::ENC] = 1;
            sellRates[Currency::BIC] = 1;
            sellRates[Currency::DIL] = 1;
            sellRates[Currency::LIT] = 1;
        }


        double getBuyRate(Currency c) const { return buyRates.find(c)->second; }
        double getSellRate(Currency c) const { return sellRates.find(c)->second; }

        void setBuyRate(Currency c, double newRate) { buyRates[c] = newRate; }
        void setSellRate(Currency c, double newRate) { sellRates[c] = newRate; }

        ExchangeTable& exchangeRate(Currency cur) { _settingCurrency = cur; return *this; }
        ExchangeTable& buyingRate(double rate) { buyRates[_settingCurrency] = rate; return *this; }
        ExchangeTable& sellingRate(double rate) { sellRates[_settingCurrency] = rate; return *this; }


};

#endif /*__EXCHANGE_TABLE_H__*/
