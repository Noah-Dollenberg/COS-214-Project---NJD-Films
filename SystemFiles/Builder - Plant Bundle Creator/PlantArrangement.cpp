#include "PlantArrangement.h"
#include "../Plant - Abstract Base/Plant.h"
#include <iostream>
#include <iomanip>

PlantArrangement::PlantArrangement()
    : name(""), description(""), basePrice(0.0), containerType("standard") {}

PlantArrangement::~PlantArrangement() {
    plants.clear();
}

void PlantArrangement::setName(const std::string& n) {
    name = n;
}

void PlantArrangement::setDescription(const std::string& desc) {
    description = desc;
}

void PlantArrangement::setBasePrice(double price) {
    basePrice = price;
}

void PlantArrangement::setContainerType(const std::string& container) {
    containerType = container;
}

void PlantArrangement::addPlant(Plant* plant) {
    if (plant != nullptr) {
        plants.push_back(plant);
    }
}

std::string PlantArrangement::getName() const {
    return name;
}

std::string PlantArrangement::getDescription() const {
    return description;
}

double PlantArrangement::getBasePrice() const {
    return basePrice;
}

double PlantArrangement::getTotalPrice() const {
    // In a real system, you'd get plant prices too
    return basePrice + (plants.size() * 50.0); // Simplified
}

std::string PlantArrangement::getContainerType() const {
    return containerType;
}

const std::vector<Plant*>& PlantArrangement::getPlants() const {
    return plants;
}

int PlantArrangement::getPlantCount() const {
    return plants.size();
}

void PlantArrangement::display() const {
    std::cout << "\nPlant Arrangement" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Container: " << containerType << std::endl;
    std::cout << "Number of Plants: " << plants.size() << std::endl;
    std::cout << "Base Price: R" << std::fixed << std::setprecision(2) << basePrice << std::endl;
    std::cout << "Total Price: R" << std::fixed << std::setprecision(2) << getTotalPrice() << std::endl;
}
