#ifndef GIFTWRAPPINGDECORATOR_H
#define GIFTWRAPPINGDECORATOR_H

#include "PlantDecorator.h"
#include <string>

/**
 * @brief Adds gift wrapping to a plant product
 *
 * Available styles: classic, modern, festive, elegant
 */
class GiftWrappingDecorator : public PlantDecorator {
private:
    std::string wrappingStyle;
    std::string ribbonColor;
    bool includeBow;
    double wrappingPrice;

public:
    GiftWrappingDecorator();
    GiftWrappingDecorator(PlantProduct* product,
                          const std::string& style = "classic",
                          const std::string& ribbon = "red",
                          bool bow = true);
    virtual ~GiftWrappingDecorator();

    double getPrice() const override;
    std::string getDescription() const override;
    void display() const override;

    // Wrapping-specific methods
    std::string getWrappingStyle() const;
    void setWrappingStyle(const std::string& style);

    std::string getRibbonColor() const;
    void setRibbonColor(const std::string& color);

    bool hasBow() const;
    void setIncludeBow(bool bow);

    double getWrappingPrice() const;
};

#endif // GIFTWRAPPINGDECORATOR_H