#ifndef PLANTARRANGEMENTBUILDER_H
#define PLANTARRANGEMENTBUILDER_H

class PlantArrangement;

class PlantArrangementBuilder {
protected:
    PlantArrangement* arrangement;  // Instantiates
    
public:
    virtual ~PlantArrangementBuilder() = default;
};

#endif // PLANTARRANGEMENTBUILDER_H