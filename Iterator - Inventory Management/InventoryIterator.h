#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H
#include "PlantIterator.h"
#include <vector>

class GreenhouseInventory;
class Plant;

class InventoryIterator : public PlantIterator {
private:
    GreenhouseInventory* inventory;  // Relationship
    size_t currentIndex;
    std::vector<Plant*> plants;

public:
    InventoryIterator(GreenhouseInventory* inv);
    virtual ~InventoryIterator() = default;
    
    void first() override;
    void next() override;
    bool isDone() const override;
    Plant* currentItem() const override;
};

#endif // INVENTORYITERATOR_H
