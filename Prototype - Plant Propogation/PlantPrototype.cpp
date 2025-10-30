#include "PlantPrototype.h"
#include "../Plant - Abstract Base/Plant.h"

PlantPrototype::PlantPrototype() : plant(nullptr) {}

PlantPrototype::PlantPrototype(const PlantPrototype& other) {
    if (other.plant)
    {
        plant = other.plant->clone();
    }
    else
    {
        plant = nullptr;
    }
}

PlantPrototype::~PlantPrototype()
{
    delete plant;
    plant = nullptr;
}

std::string PlantPrototype::getPlantType() const {
    return plant ? plant->getType() : "";
}

int PlantPrototype::getPlantHealth() const {
    return plant ? plant->getHealthLevel() : 0;
}

void PlantPrototype::setPlantHealth(int h) {
    if (plant) {
        plant->setHealthLevel(h);
    }
}