#include "currency.h"

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
