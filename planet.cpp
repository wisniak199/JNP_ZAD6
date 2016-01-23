#include <iostream>

#include "citizen.h"
#include "planet.h"

CitizenID Planet::nextCitizenID = 0;

Citizen& Planet::findCitizen(CitizenID id) {
    return *(*(idToName.find(id))).second;
}
