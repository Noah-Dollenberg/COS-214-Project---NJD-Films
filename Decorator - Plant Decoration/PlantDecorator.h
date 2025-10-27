#ifndef PLANTDECORATOR_H
#define PLANTDECORATOR_H

#include "PlantProduct.h"

/**
 * @brief Abstract decorator base class
 *
 * This class wraps a PlantProduct and adds additional features.
 * All concrete decorators inherit from this.
 */
class PlantDecorator : public PlantProduct {
protected:
    PlantProduct* wrappedProduct;  // The product being decorated

public:
    PlantDecorator();
    explicit PlantDecorator(PlantProduct* product);
    virtual ~PlantDecorator();

    // Must implement these from PlantProduct
    virtual double getPrice() const override = 0;
    virtual std::string getDescription() const override = 0;
    virtual void display() const override;

    // Decorator-specific
    PlantProduct* getWrappedProduct() const;
    void setWrappedProduct(PlantProduct* product);
};

#endif // PLANTDECORATOR_H