#include "InventoryManager.h"
#include "PlantCollection.h"
#include "PlantIterator.h"
#include "../Plant - Abstract Base/Plant.h"
#include <iostream>

InventoryManager::InventoryManager() : collection(nullptr) {
}

InventoryManager::~InventoryManager() {
    // We don't own the collection, just reference it
}

void InventoryManager::setCollection(PlantCollection* coll) {
    collection = coll;
}

PlantIterator* InventoryManager::getIterator() {
    if (collection) {
        return collection->createIterator();
    }
    return nullptr;
}

void InventoryManager::addPlant(Plant* plant) {
    if (collection && plant) {
        collection->addPlant(plant);
    }
}

void InventoryManager::displayInventory() {
    if (!collection) {
        std::cout << "No collection set." << std::endl;
        return;
    }
    
    PlantIterator* iterator = getIterator();
    if (!iterator) {
        std::cout << "Could not create iterator." << std::endl;
        return;
    }
    
    std::cout << "=== Greenhouse Inventory ===" << std::endl;
    int count = 0;
    for (iterator->first(); !iterator->isDone(); iterator->next()) {
        Plant* plant = iterator->currentItem();
        if (plant) {
            std::cout << "Plant " << ++count << std::endl;
        }
    }
    std::cout << "Total plants: " << count << std::endl;
    
    delete iterator;
}
