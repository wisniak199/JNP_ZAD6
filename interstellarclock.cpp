#include "interstellarclock.h"
#include "bank_system.h"
#include "bank.h"

unsigned long long InterstellarClock::hours() const {
    return _hours;
}

Time InterstellarClock::time() const {
    return _hours % HOURS_IN_DAY;
}

Date InterstellarClock::date() const {
    return _hours / HOURS_IN_DAY;
}

InterstellarClock& InterstellarClock::nextHour() {
    _hours++;
    checkIfMonthPassed();
    return *this;
}

InterstellarClock& InterstellarClock::nextDay() {
    for (Time i = 0; i < HOURS_IN_DAY; i++)
        nextHour();
    return *this;
}

InterstellarClock& InterstellarClock::nextMonth() {
    for (Date i = 0; i < DAYS_IN_MONTH; i++)
        nextDay();
    return *this;
}

InterstellarClock& interstellarClock() {
    static InterstellarClock clock;
    return clock;
}

void InterstellarClock::checkIfMonthPassed() {
    if (_hours - _last_charge_time >= HOURS_IN_MONTH) {
        _last_charge_time += HOURS_IN_MONTH;
        bankSystem().monthlyCharging();
    }
}
