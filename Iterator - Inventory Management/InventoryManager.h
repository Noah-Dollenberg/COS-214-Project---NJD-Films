#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H
#include <vector>

class PlantCollection;
class PlantIterator;
class GreenhouseComponent;
class Plant;

class InventoryManager {
private:
    PlantCollection* collection;
    std::vector<GreenhouseComponent*> components;
    
public:
    InventoryManager();
    virtual ~InventoryManager();
    
    void setCollection(PlantCollection* coll);
    PlantIterator* getIterator();
    void addPlant(Plant* plant);
    void displayInventory();
};

#endif // INVENTORYMANAGER_H
