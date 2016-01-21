#include "citizen.h"
#include "planet.h"

virtual Citizen& Planet::findCitizen(int id) {
    return (*(idToName.find(id))).second;
}

 virtual Citizen Planet::registerCitizen(const std::string& name) {
    Citizen c = Citizen(name, nextId);
    idToName.emplace(nextId, std::move(c));
    nextId++;
    return findCitizen(nextId - 1);
}
