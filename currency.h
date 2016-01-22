#ifndef __CURRENCY_H__
#define __CURRENCY_H__

enum class Currency {
    ENC,
    BIC,
    DIL,
    LIT,
};

std::string currencyToString(Currency c);

#endif /*__CURRENCY_H__*/
