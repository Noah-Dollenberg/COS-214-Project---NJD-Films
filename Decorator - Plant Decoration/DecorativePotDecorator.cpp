#include "DecorativePotDecorator.h"
#include <iostream>
#include <iomanip>

DecorativePotDecorator::DecorativePotDecorator()
    : PlantDecorator(), potType("ceramic"), potColor("white"), potPrice(50.0) {}

DecorativePotDecorator::DecorativePotDecorator(PlantProduct* product,
                                                 const std::string& type,
                                                 const std::string& color)
    : PlantDecorator(product), potType(type), potColor(color) {

    // Set price based on pot type
    if (type == "ceramic") potPrice = 50.0;
    else if (type == "terracotta") potPrice = 35.0;
    else if (type == "modern") potPrice = 85.0;
    else if (type == "vintage") potPrice = 120.0;
    else potPrice = 40.0;
}

DecorativePotDecorator::~DecorativePotDecorator() {}

double DecorativePotDecorator::getPrice() const {
    double basePrice = wrappedProduct ? wrappedProduct->getPrice() : 0.0;
    return basePrice + potPrice;
}

std::string DecorativePotDecorator::getDescription() const {
    std::string baseDesc = wrappedProduct ? wrappedProduct->getDescription() : "Unknown";
    return baseDesc + " + " + potColor + " " + potType + " pot";
}

void DecorativePotDecorator::display() const {
    if (wrappedProduct) {
        std::cout << "\n========================================" << std::endl;
        std::cout << "PLANT WITH DECORATIVE POT" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Base Product: " << wrappedProduct->getDescription() << std::endl;
        std::cout << "Base Price: R" << std::fixed << std::setprecision(2)
                  << wrappedProduct->getPrice() << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Pot Type: " << potColor << " " << potType << std::endl;
        std::cout << "Pot Price: R" << std::fixed << std::setprecision(2)
                  << potPrice << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "TOTAL PRICE: R" << std::fixed << std::setprecision(2)
                  << getPrice() << std::endl;
        std::cout << "========================================\n" << std::endl;
    }
}

std::string DecorativePotDecorator::getPotType() const { return potType; }
void DecorativePotDecorator::setPotType(const std::string& type) { potType = type; }

std::string DecorativePotDecorator::getPotColor() const { return potColor; }
void DecorativePotDecorator::setPotColor(const std::string& color) { potColor = color; }

double DecorativePotDecorator::getPotPrice() const { return potPrice; }
