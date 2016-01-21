#include "citizen.h"
#include "planet.h"

virtual Citizen& Planet::findCitizen(CitizenID id) {
    return (*(idToName.find(id))).second;
}

virtual Citizen Planet::registerCitizen(const std::string& name) {
    Citizen c = Citizen(name, nextID);
    idToName.emplace(nextID, std::move(c));
    nextID++;
    return findCitizen(nextID - 1);
}




