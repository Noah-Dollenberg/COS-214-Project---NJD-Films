#ifndef DECORATIVEPOTDECORATOR_H
#define DECORATIVEPOTDECORATOR_H

#include "PlantDecorator.h"
#include <string>

/**
 * @brief Adds a decorative pot to a plant product
 *
 * Available pot types: ceramic, terracotta, modern, vintage
 */
class DecorativePotDecorator : public PlantDecorator {
private:
    std::string potType;
    std::string potColor;
    double potPrice;

public:
    DecorativePotDecorator();
    DecorativePotDecorator(PlantProduct* product,
                           const std::string& type = "ceramic",
                           const std::string& color = "white");
    virtual ~DecorativePotDecorator();

    double getPrice() const override;
    std::string getDescription() const override;
    void display() const override;

    // Pot-specific methods
    std::string getPotType() const;
    void setPotType(const std::string& type);

    std::string getPotColor() const;
    void setPotColor(const std::string& color);

    double getPotPrice() const;
};

#endif // DECORATIVEPOTDECORATOR_H