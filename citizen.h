#ifndef __CITIZEN_H__
#define __CITIZEN_H__

class Citizen {
    protected:
        std::string _name;
        int _id;
        Citizen(const std::string& name, int id) : _name(name), _id(id) {}
    public:
        const std::string& getName() const { return _name; }
        const int id() const { return _id; }
};

class QonosCitizen : public Citizen {
    public:
        QonosCitizen(const std::string& name, int id) : Citizen(name, id) {}
};

class EarthCitizen : public Citizen {
    public:
        EarthCitizen(const std::string& name, int id) : Citizen(name, id) {}
};

class BynausCitizen : public Citizen {
    public:
        BynausCitizen(const std::string& name, int id) : Citizen(name, id) {}
};


#endif /*__CITIZEN_H__*/
