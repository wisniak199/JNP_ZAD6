#ifndef __PLANET_H__
#define __PLANET_H__

namespace {
    CitizenID getNextID() {
        static CitizenID id = 0;
        return id++;
    }
}

class Planet {
    protected:
        std::map<CitizenID, std::shared_ptr<Citizen>> idToName;
        Planet() {} // protected, bo nie chcemy, aby uzytkownik stworzyl Planet

    public:
        virtual ~Planet() {
            idToName.clear();
        }

        virtual Citizen& findCitizen(CitizenID id) {
            return *(*(idToName.find(id))).second;
        }

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
            // const std::pair<CitizenID, Citizen> p(id, c);
            // auto x = std::make_pair<CitizenID, Citizen>(id, *c);
            // idToName.insert(x);
            DEBUG && std::cout << "Registered binarius with id = " << id <<
                " and its name is: " << name << std::endl;
            return *c;
        }

        BynausCitizen& registerCitizen(const BynausCitizen& b1,
                                       const BynausCitizen& b2) {
            const std::string double_name = b1.getName() + "&" + b2.getName();
            std::cout << b1.id() << " " << b2.id() << std::endl;
            std::cout << double_name << std::endl;
            CitizenID id = getNextID();
            auto c = std::make_shared<BynausCitizen>(double_name, id);
            // idToName.emplace(id, c);
            return *c;
        }
};

#endif
