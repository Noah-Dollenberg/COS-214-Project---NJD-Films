#include "RosePrototype.h"
#include "../Plant - Abstract Base/Plant.h"
#include "../Factory - Plant Creation/RoseFactory.h"

PlantPrototype* RosePrototype::clone() {
    if (!plant) return nullptr;
    return new RosePrototype(*this);
}

RosePrototype::RosePrototype() {
    plant = new Rose();
}

RosePrototype::RosePrototype(const RosePrototype& other) : PlantPrototype(other) {
    // Base class copy constructor handles cloning
}

RosePrototype::~RosePrototype() {
    // Base class destructor handles cleanup
}