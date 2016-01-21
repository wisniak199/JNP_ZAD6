#ifndef __CITIZEN_H__
#define __CITIZEN_H__

class Citizen {
    protected:
        std::string name;
        int id;
    public:
        Citizen(std::string& name, int id) : name(name), id(id) {}
        std::string& getName() { return name; }
};

#endif /*__CITIZEN_H__*/
