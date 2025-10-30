#include "SucculentPrototype.h"
#include "../Plant - Abstract Base/Plant.h"
#include "../Factory - Plant Creation/SucculentFactory.h"

PlantPrototype* SucculentPrototype::clone() {
    if (!plant) return nullptr;
    return new SucculentPrototype(*this);
}

SucculentPrototype::SucculentPrototype() {
    plant = new Succulent();
}

SucculentPrototype::SucculentPrototype(const SucculentPrototype& other) : PlantPrototype(other) {
    // Base class copy constructor handles cloning
}

SucculentPrototype::~SucculentPrototype() {
    // Base class destructor handles cleanup
}