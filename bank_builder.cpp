#include "bank_builder.h"
#include "bank.h"

BankBuilder& bankBuilder() {
    static BankBuilder builder;
    return builder;
}
