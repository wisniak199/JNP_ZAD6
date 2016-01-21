#ifndef __PLANET_H__
#define __PLANET_H__

class Planet {
    protected:
        int nextId; //@FIXME
        std::map<int, std::shared_ptr<Citizen>> idToName;
        Planet() {} // protected, bo nie chcemy, aby uzytkownik stworzyl Planet

    public:
        virtual ~Planet() {
            idToName.clear();
        }

        virtual Citizen& findCitizen(int id) {
            return *(*(idToName.find(id))).second;
        }

        // pure virtual
        virtual Citizen& registerCitizen(const std::string& name) = 0;
};

// Out of line initialization.
// int Planet::nextId = 0;

class Earth : public Planet {
    public:
        EarthCitizen& registerCitizen(const std::string& name) {
            auto c = std::make_shared<EarthCitizen>(name, Planet::nextId);
            idToName.emplace(Planet::nextId, c);
            Planet::nextId++;
            return *c;
        }
};

class Qonos : public Planet {
    public:
        QonosCitizen& registerCitizen(const std::string& name) {
            auto c = std::make_shared<QonosCitizen>(name, Planet::nextId);
            idToName.emplace(Planet::nextId, c);
            Planet::nextId++;
            return *c;
        }
};

class Bynaus : public Planet {
    public:
        BynausCitizen& registerCitizen(const std::string& name) {
            auto c = std::make_shared<BynausCitizen>(name, Planet::nextId);
            std::cout << name << std::endl;
            idToName.emplace(Planet::nextId, c);
            Planet::nextId++;
            DEBUG && std::cout << "Registered binarius with id = " << nextId - 1 << std::endl;
            return *c;
        }

        BynausCitizen& registerCitizen(const BynausCitizen& b1,
                                       const BynausCitizen& b2) {
            std::string double_name = b1.getName() + "&" + b2.getName();
            std::cout << b1.id() << " " << b2.id() << std::endl;
            std::cout << double_name << std::endl;
            auto c = std::make_shared<BynausCitizen>(double_name, Planet::nextId);
            idToName.emplace(Planet::nextId, c);
            Planet::nextId++;
            return *c;
        }
};

#endif
