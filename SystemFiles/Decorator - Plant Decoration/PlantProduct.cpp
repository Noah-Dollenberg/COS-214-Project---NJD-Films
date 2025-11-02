#include "PlantProduct.h"
#include "../Plant - Abstract Base/Plant.h"
#include <iostream>

PlantProduct::PlantProduct() : plant(nullptr) {}

PlantProduct::PlantProduct(Plant* p) : plant(p) {}

PlantProduct::~PlantProduct() {
    // Don't delete plant - it's managed by inventory
}

Plant* PlantProduct::getPlant() const {
    return plant;
}

void PlantProduct::setPlant(Plant* p) {
    plant = p;
}