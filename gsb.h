#ifndef __GSB_H__
#define __GSB_H__

#include <iostream>
#include <map>
#include <vector>

#define DEBUG 1

#include "bank.h"
#include "bank_system.h"
#include "bank_builder.h"
#include "bank_account_info.h"
#include "currency.h"
#include "exchange_table.h"
#include "account.h"
#include "planet.h"
#include "citizen.h"
#include "gkb.h"

Earth& earth() {
    static Earth earth;
    return earth;
}

Qonos& qonos() {
    static Qonos qonos;
    return qonos;
}

Bynaus& bynaus() {
    static Bynaus bynaus;
    return bynaus;
}



#endif /*__GSB_H__*/
