#include "MatureState.h"
#include "PlantContext.h"
#include <iostream>

void MatureState::water(PlantContext* context) {
    std::cout << "Watering mature plant with regular schedule.\n";
    if (context->getPlant()) {
        context->getPlant()->modifyHealth(10);
    }
}

void MatureState::fertilize(PlantContext* context) {
    std::cout << "Applying maintenance fertilizer to mature plant.\n";
    if (context->getPlant()) {
        context->getPlant()->modifyHealth(5);
    }
}

void MatureState::checkHealth(PlantContext* context) {
    std::cout << "Checking mature plant health: Stable, can transition to Flowering or Dormant.\n";
    // Placeholder logic: Manual transition for test (e.g., season-based)
    // For this example, we'll allow manual transition in main.cpp
}