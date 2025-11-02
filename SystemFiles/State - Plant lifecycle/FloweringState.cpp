#include "FloweringState.h"
#include "PlantContext.h"
#include <iostream>

void FloweringState::water(PlantContext* context) {
    std::cout << "Watering flowering plant with extra care to support blooms.\n";
    if (context->getPlant()) {
        context->getPlant()->modifyHealth(15);
    }
}

void FloweringState::fertilize(PlantContext* context) {
    std::cout << "Applying bloom-boosting fertilizer.\n";
    if (context->getPlant()) {
        context->getPlant()->modifyHealth(10);
    }
}

void FloweringState::checkHealth(PlantContext* context) {
    std::cout << "Checking flowering plant health: Blooms indicate peak health.\n";
    //you go to the flower state manually by using the setState() function (PlantsContext class)
}