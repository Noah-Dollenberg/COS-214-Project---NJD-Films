#ifndef PLANTPROTOTYPE_H
#define PLANTPROTOTYPE_H

#include <string> 

class Plant;

class PlantPrototype {
protected:
    Plant* plant; 
    
public:
    PlantPrototype();
    PlantPrototype(const PlantPrototype& other);
    virtual ~PlantPrototype();
    virtual PlantPrototype* clone() = 0;
    
    std::string getPlantType() const;
    int getPlantHealth() const;
    void setPlantHealth(int h);
};

#endif // PLANTPROTOTYPE_H