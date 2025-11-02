#include "GreenhouseInventory.h"
#include "InventoryIterator.h"
#include "../Plant - Abstract Base/Plant.h"
#include <algorithm>

GreenhouseInventory::GreenhouseInventory() {
}

GreenhouseInventory::~GreenhouseInventory() {
    // Note: We don't delete plants here - ownership remains with creator
    plants.clear();
}

PlantIterator* GreenhouseInventory::createIterator() {
    return new InventoryIterator(this);
}

void GreenhouseInventory::addPlant(Plant* plant) {
    if (plant) {
        plants.push_back(plant);
    }
}

void GreenhouseInventory::removePlant(Plant* plant) {
    auto it = std::find(plants.begin(), plants.end(), plant);
    if (it != plants.end()) {
        plants.erase(it);
    }
}

bool GreenhouseInventory::isEmpty() const {
    return plants.empty();
}

size_t GreenhouseInventory::getCount() const {
    return plants.size();
}

Plant* GreenhouseInventory::getPlantAt(size_t index) const {
    if (index < plants.size()) {
        return plants[index];
    }
    return nullptr;
}
