#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H
#include "PlantIterator.h"

class GreenhouseInventory;

class InventoryIterator : public PlantIterator {
private:
    GreenhouseInventory* inventory;  // Relationship

public:
    virtual ~InventoryIterator() = default;
};

#endif // INVENTORYITERATOR_H
