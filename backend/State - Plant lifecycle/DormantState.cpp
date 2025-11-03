#include "DormantState.h"
#include "PlantContext.h"
#include <iostream>

void DormantState::water(PlantContext* context) {
    std::cout << "Minimizing water for dormant plant to prevent rot.\n";
    if (context->getPlant()) {
        context->getPlant()->modifyHealth(5);
    }
}

void DormantState::fertilize(PlantContext* context) {
    std::cout << "No fertilizing needed for dormant plant.\n";
}

void DormantState::checkHealth(PlantContext* context) {
    std::cout << "Checking dormant plant health: Awaiting active growth season.\n";
    // Placeholder logic: Transition to GrowingState when conditions improve
    // if (/* season changes */) context->setState(new GrowingState());
}