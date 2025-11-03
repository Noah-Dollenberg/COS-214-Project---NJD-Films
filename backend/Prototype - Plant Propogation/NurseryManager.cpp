#include "NurseryManager.h"
#include "PlantPrototype.h"
#include "SucculentPrototype.h"
#include "RosePrototype.h"
#include <algorithm>

void NurseryManager::addPrototype(PlantPrototype* proto) {
    if (proto) {
        prototypes.push_back(proto);
    }
}

PlantPrototype* NurseryManager::clonePrototype(const std::string& type) {
    auto it = std::find_if(prototypes.begin(), prototypes.end(),
                           [&type](PlantPrototype* p) {
                               return p->getPlantType() == type;
                           });
    if (it != prototypes.end()) {
        return (*it)->clone();
    }
    return nullptr; // Return nullptr if type not found
}