#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H
#include "PlantProduct.h"

class PlantDecorator : public PlantProduct {
protected:
    PlantProduct* wrappedProduct;  // Aggregation
    
public:
    virtual ~PlantDecorator() = default;
};

#endif // PLANTDECORATOR_H