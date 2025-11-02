#include "BasicPlant.h"
#include "../Plant - Abstract Base/Plant.h"
#include <iostream>
#include <iomanip>

BasicPlant::BasicPlant() : PlantProduct() {}

BasicPlant::BasicPlant(Plant* p) : PlantProduct(p) {}

BasicPlant::~BasicPlant() {}

double BasicPlant::getPrice() const {
    if (plant) {
        return plant->getBasePrice();
    }
    return 0.0;
}

std::string BasicPlant::getDescription() const {
    if (plant) {
        return plant->getSpecies() + " (Basic)";
    }
    return "Unknown Plant";
}

void BasicPlant::display() const {
    std::cout << "PLANT PRODUCT" << std::endl;
    std::cout << "Description: " << getDescription() << std::endl;
    std::cout << "Price: R" << std::fixed << std::setprecision(2) << getPrice() << std::endl;
}
