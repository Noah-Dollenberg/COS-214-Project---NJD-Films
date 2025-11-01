#include "GiftArrangementBuilder.h"
#include "PlantArrangement.h"
#include "../Plant - Abstract Base/Plant.h"
#include <iostream>

GiftArrangementBuilder::GiftArrangementBuilder() : PlantArrangementBuilder() {}

GiftArrangementBuilder::~GiftArrangementBuilder() {}

void GiftArrangementBuilder::setAvailablePlants(const std::vector<Plant*>& plants) {
    availablePlants = plants;
}

void GiftArrangementBuilder::reset() {
    arrangement = new PlantArrangement();
    std::cout << "[GiftBuilder] Creating new gift arrangement..." << std::endl;
}

void GiftArrangementBuilder::setBasicInfo() {
    arrangement->setName("Premium Gift Arrangement");
    arrangement->setDescription("Beautiful gift arrangement perfect for any occasion");
    std::cout << "[GiftBuilder] Set gift arrangement info" << std::endl;
}

void GiftArrangementBuilder::selectContainer() {
    arrangement->setContainerType("decorative_basket");
    std::cout << "[GiftBuilder] Selected decorative basket container" << std::endl;
}

void GiftArrangementBuilder::addPlants() {
    // Gift arrangements typically have 3-5 smaller plants
    int targetCount = 3;

    std::cout << "[GiftBuilder] Adding " << targetCount << " plants for gift..." << std::endl;

    for (int i = 0; i < targetCount && i < availablePlants.size(); i++) {
        arrangement->addPlant(availablePlants[i]);
        std::cout << "  - Added plant " << (i + 1) << std::endl;
    }
}

void GiftArrangementBuilder::addDecorations() {
    // Gift arrangements include decorative elements
    std::cout << "[GiftBuilder] Adding gift decorations:" << std::endl;
    std::cout << "  - Ribbon and bow" << std::endl;
    std::cout << "  - Greeting card" << std::endl;
    std::cout << "  - Tissue paper wrapping" << std::endl;
}

void GiftArrangementBuilder::calculatePrice() {
    double basePrice = 150.0;  // Gift presentation adds value
    arrangement->setBasePrice(basePrice);
    std::cout << "[GiftBuilder] Calculated base price: R" << basePrice << std::endl;
}
