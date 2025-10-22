#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H
#include <vector>

class PlantCollection;
class PlantIterator;
class GreenhouseComponent;

class InventoryManager {
private:
    PlantCollection* collection;              // Relationship
    PlantIterator* iterator;                  // Relationship
    std::vector<GreenhouseComponent*> components;  // Aggregation
    
public:
    virtual ~InventoryManager() = default;
};

#endif // INVENTORYMANAGER_H