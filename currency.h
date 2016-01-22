#ifndef __CURRENCY_H__
#define __CURRENCY_H__

enum class Currency {
    ENC,
    BIC,
    DIL,
    LIT,
};

std::string currencyToString(Currency c) {
    std::string cs;
    switch (c) {
        case Currency::ENC:
            cs = "ENC";
            break;
        case Currency::BIC:
            cs = "BIC";
            break;
        case Currency::DIL:
            cs = "DIL";
            break;
        case Currency::LIT:
            cs = "LIT";
            break;
    }
    return cs;
}

#endif /*__CURRENCY_H__*/
