#include "PlantState.h"
#include "PlantContext.h"
#include <iostream>

void PlantState::water(PlantContext* context) {
    std::cout << "Default watering behavior for unspecified state.\n";
}

void PlantState::fertilize(PlantContext* context) {
    std::cout << "Default fertilizing behavior for unspecified state.\n";
}

void PlantState::checkHealth(PlantContext* context) {
    std::cout << "Default health check for unspecified state.\n";
}