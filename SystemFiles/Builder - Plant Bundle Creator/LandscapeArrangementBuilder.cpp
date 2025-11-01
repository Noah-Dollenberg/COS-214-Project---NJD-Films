#include "LandscapeArrangementBuilder.h"
#include "PlantArrangement.h"
#include "../Plant - Abstract Base/Plant.h"
#include <iostream>

LandscapeArrangementBuilder::LandscapeArrangementBuilder()
    : PlantArrangementBuilder(), landscapeTheme("mixed") {}

LandscapeArrangementBuilder::~LandscapeArrangementBuilder() {}

void LandscapeArrangementBuilder::setAvailablePlants(const std::vector<Plant*>& plants) {
    availablePlants = plants;
}

void LandscapeArrangementBuilder::setTheme(const std::string& theme) {
    landscapeTheme = theme;
}

void LandscapeArrangementBuilder::reset() {
    arrangement = new PlantArrangement();
    std::cout << "[LandscapeBuilder] Creating new landscape arrangement..." << std::endl;
}

void LandscapeArrangementBuilder::setBasicInfo() {
    arrangement->setName("Landscape Collection - " + landscapeTheme);
    arrangement->setDescription("Professional landscape arrangement for outdoor spaces");
    std::cout << "[LandscapeBuilder] Set landscape info with theme: " << landscapeTheme << std::endl;
}

void LandscapeArrangementBuilder::selectContainer() {
    arrangement->setContainerType("large_planter_box");
    std::cout << "[LandscapeBuilder] Selected large planter box" << std::endl;
}

void LandscapeArrangementBuilder::addPlants() {
    // Landscape arrangements have more plants (7-10)
    int targetCount = 7;

    std::cout << "[LandscapeBuilder] Adding " << targetCount << " plants for landscaping..." << std::endl;

    for (int i = 0; i < targetCount && i < availablePlants.size(); i++) {
        arrangement->addPlant(availablePlants[i]);
        std::cout << "  - Added plant " << (i + 1) << std::endl;
    }
}

void LandscapeArrangementBuilder::addDecorations() {
    // Landscape arrangements have functional decorations
    std::cout << "[LandscapeBuilder] Adding landscape elements:" << std::endl;
    std::cout << "  - Decorative stones" << std::endl;
    std::cout << "  - Mulch layer" << std::endl;
    std::cout << "  - Plant markers" << std::endl;
}

void LandscapeArrangementBuilder::calculatePrice() {
    double basePrice = 500.0;  // Landscape arrangements are more expensive
    arrangement->setBasePrice(basePrice);
    std::cout << "[LandscapeBuilder] Calculated base price: R" << basePrice << std::endl;
}
