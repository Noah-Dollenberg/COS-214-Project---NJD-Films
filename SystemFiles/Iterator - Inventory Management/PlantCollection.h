#ifndef PLANTCOLLECTION_H
#define PLANTCOLLECTION_H

class PlantIterator;
class Plant;

class PlantCollection {
public:
    virtual ~PlantCollection() = default;
    
    virtual PlantIterator* createIterator() = 0;
    virtual void addPlant(Plant* plant) = 0;
    virtual void removePlant(Plant* plant) = 0;
    virtual bool isEmpty() const = 0;
};

#endif // PLANTCOLLECTION_H
