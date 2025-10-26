#include "PlantCareRoutine.h"
#include <iostream>

void PlantCareRoutine::careForPlant() {
    std::cout << "Starting plant care routine...\n";
    checkSoilMoisture();
    water();
    fertilize();
    prune();
    additionalCare();
    std::cout << "Plant care routine completed.\n";
}