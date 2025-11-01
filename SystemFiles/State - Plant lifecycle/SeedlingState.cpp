#include "SeedlingState.h"
#include "PlantContext.h"
#include "GrowingState.h"
#include <iostream>

void SeedlingState::water(PlantContext* context) {
    std::cout << "Watering seedling with small amounts to avoid overwatering.\n";
    if (context->getPlant()) {
        context->getPlant()->modifyHealth(10);
    }
}

void SeedlingState::fertilize(PlantContext* context) {
    std::cout << "Applying light fertilizer to seedling for growth.\n";
    if (context->getPlant()) {
        context->getPlant()->modifyHealth(5);
    }
}

void SeedlingState::checkHealth(PlantContext* context) {
    std::cout << "Checking seedling health: Requires frequent care to progress to Growing state.\n";
    if (context->getPlant() && context->getPlant()->getHealthLevel() > 50) {
        std::cout << "Seedling is healthy enough to transition to Growing state.\n";
        context->setState(new GrowingState());
    }
}