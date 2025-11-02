#include "InventoryIterator.h"
#include "GreenhouseInventory.h"
#include "../Plant - Abstract Base/Plant.h"

InventoryIterator::InventoryIterator(GreenhouseInventory* inv) 
    : inventory(inv), currentIndex(0) {
    // Make a copy of the plants for safe iteration
    if (inventory) {
        size_t count = inventory->getCount();
        for (size_t i = 0; i < count; i++) {
            plants.push_back(inventory->getPlantAt(i));
        }
    }
}

void InventoryIterator::first() {
    currentIndex = 0;
}

void InventoryIterator::next() {
    if (!isDone()) {
        currentIndex++;
    }
}

bool InventoryIterator::isDone() const {
    return currentIndex >= plants.size();
}

Plant* InventoryIterator::currentItem() const {
    if (isDone()) {
        return nullptr;
    }
    return plants[currentIndex];
}
