#ifndef PLANTPRODUCT_H
#define PLANTPRODUCT_H

class Plant;
class PlantDecorator;

class PlantProduct {
protected:
    Plant* plant;                    // Relationship
    PlantDecorator* decorator;       // Aggregation (0..1)
    
public:
    virtual ~PlantProduct() = default;
};

#endif // PLANTPRODUCT_H