#ifndef PLANTARRANGEMENTBUILDER_H
#define PLANTARRANGEMENTBUILDER_H

class PlantArrangement;
class Plant;

class PlantArrangementBuilder {
protected:
    PlantArrangement* arrangement;

public:
    PlantArrangementBuilder();
    virtual ~PlantArrangementBuilder();

    // Abstract methods that concrete builders must implement
    virtual void reset() = 0;
    virtual void setBasicInfo() = 0;
    virtual void selectContainer() = 0;
    virtual void addPlants() = 0;
    virtual void addDecorations() = 0;
    virtual void calculatePrice() = 0;

    // Get the final product
    PlantArrangement* getArrangement();
};

#endif // PLANTARRANGEMENTBUILDER_H