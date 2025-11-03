#include "PlantDecorator.h"

#include <iomanip>
#include <iostream>

PlantDecorator::PlantDecorator() : PlantProduct(), wrappedProduct(nullptr) {}

PlantDecorator::PlantDecorator(PlantProduct* product) 
    : PlantProduct(product ? product->getPlant() : nullptr), 
      wrappedProduct(product) {}

PlantDecorator::~PlantDecorator() {
    // Don't delete wrappedProduct - managed by client
}

PlantProduct* PlantDecorator::getWrappedProduct() const {
    return wrappedProduct;
}

void PlantDecorator::setWrappedProduct(PlantProduct* product) {
    wrappedProduct = product;
    if (product) {
        plant = product->getPlant();
    }
}

void PlantDecorator::display() const {
    if (wrappedProduct) {
        std::cout << "DECORATED PLANT PRODUCT" << std::endl;
        std::cout << "Description: " << getDescription() << std::endl;
        std::cout << "Total Price: R" << std::fixed << std::setprecision(2) << getPrice() << std::endl;
    }
}