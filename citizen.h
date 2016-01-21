#ifndef __CITIZEN_H__
#define __CITIZEN_H__

using CitizenID = size_t;

class Citizen {
    protected:
        std::string _name;
        CitizenID _id;
        Citizen(const std::string& name, CitizenID id) : _name(name), _id(id) {}
    public:
        const std::string& getName() const { return _name; }
        const CitizenID id() const { return _id; }
};

class QonosCitizen : public Citizen {
    public:
        QonosCitizen(const std::string& name, CitizenID id) : Citizen(name, id) {}
};

class EarthCitizen : public Citizen {
    public:
        EarthCitizen(const std::string& name, CitizenID id) : Citizen(name, id) {}
};

class BynausCitizen : public Citizen {
    public:
        BynausCitizen(const std::string& name, CitizenID id) : Citizen(name, id) {}
};


#endif /*__CITIZEN_H__*/
