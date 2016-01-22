#include "bank_builder.h"

class gkb {
    static BankBuilder builder;
    public:
        static BankBuilder& bankApplication() { return builder; }
};
