#include "GiftWrappingDecorator.h"
#include <iostream>
#include <iomanip>

GiftWrappingDecorator::GiftWrappingDecorator()
    : PlantDecorator(), wrappingStyle("classic"), ribbonColor("red"), 
      includeBow(true), wrappingPrice(30.0) {}

GiftWrappingDecorator::GiftWrappingDecorator(PlantProduct* product,
                                             const std::string& style,
                                             const std::string& ribbon,
                                             bool bow)
    : PlantDecorator(product), wrappingStyle(style), ribbonColor(ribbon),
      includeBow(bow) {
    
    // Set price based on style
    if (style == "classic") wrappingPrice = 30.0;
    else if (style == "modern") wrappingPrice = 45.0;
    else if (style == "festive") wrappingPrice = 40.0;
    else if (style == "elegant") wrappingPrice = 65.0;
    else wrappingPrice = 25.0;
    
    if (includeBow) wrappingPrice += 10.0;
}

GiftWrappingDecorator::~GiftWrappingDecorator() {}

double GiftWrappingDecorator::getPrice() const {
    double basePrice = wrappedProduct ? wrappedProduct->getPrice() : 0.0;
    return basePrice + wrappingPrice;
}

std::string GiftWrappingDecorator::getDescription() const {
    std::string baseDesc = wrappedProduct ? wrappedProduct->getDescription() : "Unknown";
    std::string bowText = includeBow ? " with bow" : "";
    return baseDesc + " + " + wrappingStyle + " gift wrap" + bowText;
}

void GiftWrappingDecorator::display() const {
    if (wrappedProduct) {
        std::cout << "\n========================================" << std::endl;
        std::cout << "GIFT-WRAPPED PLANT" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Base Product: " << wrappedProduct->getDescription() << std::endl;
        std::cout << "Base Price: R" << std::fixed << std::setprecision(2) 
                  << wrappedProduct->getPrice() << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Wrapping Style: " << wrappingStyle << std::endl;
        std::cout << "Ribbon Color: " << ribbonColor << std::endl;
        std::cout << "Includes Bow: " << (includeBow ? "Yes" : "No") << std::endl;
        std::cout << "Wrapping Price: R" << std::fixed << std::setprecision(2) 
                  << wrappingPrice << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "TOTAL PRICE: R" << std::fixed << std::setprecision(2) 
                  << getPrice() << std::endl;
        std::cout << "========================================\n" << std::endl;
    }
}

std::string GiftWrappingDecorator::getWrappingStyle() const { return wrappingStyle; }
void GiftWrappingDecorator::setWrappingStyle(const std::string& style) { wrappingStyle = style; }

std::string GiftWrappingDecorator::getRibbonColor() const { return ribbonColor; }
void GiftWrappingDecorator::setRibbonColor(const std::string& color) { ribbonColor = color; }

bool GiftWrappingDecorator::hasBow() const { return includeBow; }
void GiftWrappingDecorator::setIncludeBow(bool bow) { includeBow = bow; }

double GiftWrappingDecorator::getWrappingPrice() const { return wrappingPrice; }