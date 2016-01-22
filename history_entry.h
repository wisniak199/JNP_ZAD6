#ifndef __HISOTRY_ENTRY_H__
#define __HISOTRY_ENTRY_H__

#include "account.h"
/**
 * Reprezentowana w klasach kont, jako wektor.
 */

enum class OperationType {
    TRANSFER = 1,
    CHARGE,
    INTEREST
};

class HistoryEntry {
    protected:
        size_t _day;
        double _money;
        Currency _currency;
        OperationType _operationType;

    public:
        HistoryEntry(size_t day, double money, Currency currency,
                    OperationType operationType)
            : _day(day)
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
            }
            return ot;
        }


        std::string toString() {
            return std::to_string(_day) + " " + std::to_string(_money)
                    + currencyToString(_currency) + " "
                    + operationTypeToString();
        }
};

class HistoryEntryTransfer : public HistoryEntry {
    protected:
        std::string _title;
        AccountID _sender;
        AccountID _receiver;

    public:
        HistoryEntryTransfer(size_t day, double money, Currency currency,
                             OperationType operationType,
                             std::string title,
                             AccountID sender, AccountID receiver)
            : HistoryEntry(day, money, currency, operationType)
            , _title(title)
            , _sender(sender)
            , _receiver(receiver)
        {}

        virtual std::string toString() {
            return HistoryEntry::toString() + " (" + _title + ")"
                    + " FROM: " + std::to_string(_sender)
                    + " TO: " + std::to_string(_receiver);
        }
};




#endif /*__HISOTRY_ENTRY_H__*/
