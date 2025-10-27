#include "ArrangementDirector.h"
#include "PlantArrangementBuilder.h"
#include "PlantArrangement.h"
#include <iostream>

ArrangementDirector::ArrangementDirector() : builder(nullptr) {}

ArrangementDirector::~ArrangementDirector() {
    // Don't delete builder - not owned by director
}

void ArrangementDirector::setBuilder(PlantArrangementBuilder* b) {
    builder = b;
    std::cout << "[Director] Builder set successfully" << std::endl;
}

PlantArrangement* ArrangementDirector::constructSimpleArrangement() {
    if (builder == nullptr) {
        std::cerr << "[Director] Error: No builder set!" << std::endl;
        return nullptr;
    }

    std::cout << "\n[Director] Constructing SIMPLE arrangement..." << std::endl;

    builder->reset();
    builder->setBasicInfo();
    builder->selectContainer();
    builder->addPlants();
    builder->calculatePrice();

    std::cout << "[Director] Simple arrangement complete!\n" << std::endl;
    return builder->getArrangement();
}

PlantArrangement* ArrangementDirector::constructDeluxeArrangement() {
    if (builder == nullptr) {
        std::cerr << "[Director] Error: No builder set!" << std::endl;
        return nullptr;
    }

    std::cout << "\n[Director] Constructing DELUXE arrangement..." << std::endl;

    builder->reset();
    builder->setBasicInfo();
    builder->selectContainer();
    builder->addPlants();
    builder->addDecorations();  // Deluxe includes decorations
    builder->calculatePrice();

    std::cout << "[Director] Deluxe arrangement complete!\n" << std::endl;
    return builder->getArrangement();
}

PlantArrangement* ArrangementDirector::constructCustomArrangement(bool includeDecorations) {
    if (builder == nullptr) {
        std::cerr << "[Director] Error: No builder set!" << std::endl;
        return nullptr;
    }

    std::cout << "\n[Director] Constructing CUSTOM arrangement..." << std::endl;

    builder->reset();
    builder->setBasicInfo();
    builder->selectContainer();
    builder->addPlants();

    if (includeDecorations) {
        builder->addDecorations();
    }

    builder->calculatePrice();

    std::cout << "[Director] Custom arrangement complete!\n" << std::endl;
    return builder->getArrangement();
}
