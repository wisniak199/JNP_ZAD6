#ifndef __HISOTRY_ENTRY_H__
#define __HISOTRY_ENTRY_H__

#include "currency.h"
#include "interstellarclock.h"

using AccountID = std::pair<size_t, size_t>;
std::string AccountIDToString(const AccountID& id);

enum class OperationType {
    TRANSFER = 1,
    CHARGE,
    INTEREST,
    DEPOSIT,
    WITHDRAWAL
};

class HistoryEntry {
    protected:
        Date _day;
        double _money;
        Currency _currency;
        OperationType _operationType;

    public:
        HistoryEntry(double money, Currency currency,
                     OperationType operationType)
            : _day(interstellarClock().date())
            , _money(money)
            , _currency(currency)
            , _operationType(operationType)
        {}

        inline std::string operationTypeToString() {
            std::string ot;
            switch(_operationType) {
                case OperationType::TRANSFER:
                    ot = "TRANSFER";
                    break;
                case OperationType::CHARGE:
                    ot = "CHARGE";
                    break;
                case OperationType::INTEREST:
                    ot = "INTEREST";
                    break;
                case OperationType::WITHDRAWAL:
                    ot = "WITHDRAWAL";
                    break;
                case OperationType::DEPOSIT:
                    ot = "DEPOSIT";
                    break;
            }
            return ot;
        }

        std::string toString() {
            return std::to_string(_day) + " " + std::to_string(_money)
                    + currencyToString(_currency) + " "
                    + operationTypeToString();
        }
};

// Rozszerzona wersji HistoryEntry. Transfer zawiera wiecej informacji.
class HistoryEntryTransfer : public HistoryEntry {
    protected:
        std::string _title;
        AccountID _sender;
        AccountID _receiver;

    public:
        HistoryEntryTransfer(double money, Currency currency,
                             OperationType operationType,
                             std::string title,
                             AccountID sender, AccountID receiver)
            : HistoryEntry(money, currency, operationType)
            , _title(title)
            , _sender(sender)
            , _receiver(receiver)
        {}

        virtual std::string toString() {
            return HistoryEntry::toString() + " (" + _title + ")"
                    + " FROM: " + AccountIDToString(_sender)
                    + " TO: " + AccountIDToString(_receiver);
        }
};


#endif /*__HISOTRY_ENTRY_H__*/
