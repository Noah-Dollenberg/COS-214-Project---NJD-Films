#ifndef BASICPLANT_H
#define BASICPLANT_H

#include "PlantProduct.h"

/**
 * @brief Concrete component - a plant without any decorations
 *
 * This represents a plain plant product with no additional features.
 */
class BasicPlant : public PlantProduct {
public:
    BasicPlant();
    explicit BasicPlant(Plant* p);
    virtual ~BasicPlant();

    double getPrice() const override;
    std::string getDescription() const override;
    void display() const override;
};

#endif // BASICPLANT_H