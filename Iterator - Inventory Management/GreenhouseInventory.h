#ifndef GREENHOUSEINVENTORY_H
#define GREENHOUSEINVENTORY_H
#include "PlantCollection.h"
#include <vector>

class InventoryIterator;
class Plant;
class PlantIterator;

class GreenhouseInventory : public PlantCollection {
private:
    std::vector<Plant*> plants;
    friend class InventoryIterator;

public:
    GreenhouseInventory();
    virtual ~GreenhouseInventory();
    
    PlantIterator* createIterator() override;
    void addPlant(Plant* plant) override;
    void removePlant(Plant* plant) override;
    bool isEmpty() const override;
    size_t getCount() const;
    Plant* getPlantAt(size_t index) const;
};

#endif // GREENHOUSEINVENTORY_H
