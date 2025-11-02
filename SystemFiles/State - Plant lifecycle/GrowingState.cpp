#include "GrowingState.h"
#include "MatureState.h"
#include "PlantContext.h"
#include <iostream>

void GrowingState::water(PlantContext* context) {
    std::cout << "Watering growing plant with moderate amounts.\n";
    if (context->getPlant()) {
        context->getPlant()->modifyHealth(15);
    }
}

void GrowingState::fertilize(PlantContext* context) {
    std::cout << "Applying balanced fertilizer to support growth.\n";
    if (context->getPlant()) {
        context->getPlant()->modifyHealth(10);
    }
}

void GrowingState::checkHealth(PlantContext* context) {
    std::cout << "Checking growing plant health: Progressing towards Mature state.\n";
    if (context->getPlant() && context->getPlant()->getHealthLevel() > 80) {
        std::cout << "Plant is healthy enough to transition to Mature state.\n";
        context->setState(new MatureState());
    }
}