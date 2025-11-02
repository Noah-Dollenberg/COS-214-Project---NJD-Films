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
    //you go to the flower state manually by using the setState() function (PlantsContext class)
}