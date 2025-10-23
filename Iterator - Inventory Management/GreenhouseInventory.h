#ifndef GREENHOUSEINVENTORY_H
#define GREENHOUSEINVENTORY_H
#include "PlantCollection.h"

class InventoryIterator;

class GreenhouseInventory : public PlantCollection {
private:
    InventoryIterator* inventoryIterator;  // Relationship & instantiates

public:
    virtual ~GreenhouseInventory() = default;
};

#endif // GREENHOUSEINVENTORY_H
