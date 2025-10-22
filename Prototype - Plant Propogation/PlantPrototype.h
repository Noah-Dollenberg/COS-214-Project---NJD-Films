#ifndef PLANTPROTOTYPE_H
#define PLANTPROTOTYPE_H

class Plant;

class PlantPrototype {
protected:
    Plant* plant;  // Relationship
    
public:
    virtual ~PlantPrototype() = default;
    virtual PlantPrototype* clone() = 0;
};

#endif // PLANTPROTOTYPE_H