#ifndef __gsb__interstellar_clock__
#define __gsb__interstellar_clock__

#include "bank_system.h"

using Date = unsigned long long;
using Time = unsigned short;

// Czas międzyplanetarny liczymy z dokładnością do godziny.
// Nowoutworzony zegar międzyplanetarny będzie wskazywał czas 0 i dzień 0.
class InterstellarClock {
public:
    // Doba międzyplanetarna ma 20 godzin (0-19).
    static const unsigned HOURS_IN_DAY = 20;

    // Miesiąc międzyplanetarny ma 30 dni.
    static const unsigned DAYS_IN_MONTH = 30;

    // Liczba godzin w miesiącu.
    static const unsigned HOURS_IN_MONTH = HOURS_IN_DAY * DAYS_IN_MONTH;

    virtual ~InterstellarClock() {}

    // Zwraca liczbę godzin od początku założenia ZFP.
    unsigned long long hours() const;

    // Zwraca bieżącą godzinę (0-19).
    Time time() const;

    // Zwraca bieżący datę, tj. dzień od początku założenia ZFP.
    Date date() const;

    // Przesuwa zegar o godzinę.
    virtual InterstellarClock& nextHour();

    // Przesuwa zegar o dobę.
    virtual InterstellarClock& nextDay();

    // Przesuwa zegar o miesiąc (miesiąc ma 30 dni).
    virtual InterstellarClock& nextMonth();

private:
    friend class BankSystem;
    // liczba godzin od początku założenia ZFP
    unsigned long long _hours;

    // Liczba godzina, jaka była przy ostatnim pobraniu opłat.
    unsigned long long _last_charge_time = 0;

    void checkIfMonthPassed();
};

InterstellarClock& interstellarClock();

#endif /* defined(__gsb__interstellar_clock__) */
