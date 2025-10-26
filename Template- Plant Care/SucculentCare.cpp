#include "SucculentCare.h"
#include <iostream>

void SucculentCare::checkSoilMoisture() {
    std::cout << "Checking succulent soil - should be completely dry before watering\n";
}

void SucculentCare::water() {
    std::cout << "Watering succulent sparingly, ensuring good drainage\n";
}

void SucculentCare::fertilize() {
    std::cout << "Applying diluted cactus fertilizer monthly\n";
}

void SucculentCare::prune() {
    std::cout << "Removing dead or damaged succulent leaves\n";
}