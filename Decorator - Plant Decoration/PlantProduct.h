#ifndef PLANTPRODUCT_H
#define PLANTPRODUCT_H

#include <string>

class Plant;

/**
 * @brief Base component class for plant products
 *
 * This is the base class that both BasicPlant and PlantDecorator inherit from.
 * It defines the common interface for all plant products.
 */
class PlantProduct {
protected:
    Plant* plant;  // The actual plant being sold

public:
    PlantProduct();
    explicit PlantProduct(Plant* p);
    virtual ~PlantProduct();

    // Core interface that all products must implement
    virtual double getPrice() const = 0;
    virtual std::string getDescription() const = 0;
    virtual void display() const = 0;

    // Plant access
    Plant* getPlant() const;
    void setPlant(Plant* p);
};

#endif // PLANTPRODUCT_H