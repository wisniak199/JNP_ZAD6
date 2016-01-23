#ifndef __PLANET_H__
#define __PLANET_H__

#include <memory>
#include <map>

#include "not_found_error.h"

class Planet {
    protected:
        static CitizenID nextCitizenID;
        std::map<CitizenID, std::shared_ptr<Citizen>> idToName;
        Planet() {} // protected, bo nie chcemy, aby uzytkownik stworzyl Planet

        CitizenID getNextID() { return nextCitizenID++; }

    public:
        virtual ~Planet() {
            idToName.clear();
        }

        virtual Citizen& findCitizen(CitizenID id);
        Citizen& findCitizen(std::string id) { throw NotFoundError(); }
        // pure virtual
        virtual Citizen& registerCitizen(const std::string& name) = 0;
};

// Out of line initialization.
// CitizenID Planet::nextID = 0;

class Earth : public Planet {
    public:
        EarthCitizen& registerCitizen(const std::string& name) {
            CitizenID id = getNextID();
            auto c = std::make_shared<EarthCitizen>(name, id);
            idToName.emplace(id, c);
            return *c;
        }
};

class Qonos : public Planet {
    public:
        QonosCitizen& registerCitizen(const std::string& name) {
            CitizenID id = getNextID();
            auto c = std::make_shared<QonosCitizen>(name, id);
            idToName.emplace(id, c);
            return *c;
        }
};

class Bynaus : public Planet {
    public:
        BynausCitizen& registerCitizen(const std::string& name) {
            CitizenID id = getNextID();
            auto c = std::make_shared<BynausCitizen>(name, id);
            idToName.emplace(id, c);
            return *c;
        }

        BynausCitizen& registerCitizen(const BynausCitizen& b1,
                                       const BynausCitizen& b2) {
            const std::string double_name = b1.getName() + "&" + b2.getName();
            CitizenID id = getNextID();
            auto c = std::make_shared<BynausCitizen>(double_name, id);
            idToName.emplace(id, c);
            return *c;
        }
};

#endif
