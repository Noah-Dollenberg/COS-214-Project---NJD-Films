#include "RoseCare.h"
#include <iostream>

void RoseCare::checkSoilMoisture() {
    std::cout << "Checking rose soil moisture - should be consistently moist\n";
}

void RoseCare::water() {
    std::cout << "Watering rose deeply at base, avoiding leaves\n";
}

void RoseCare::fertilize() {
    std::cout << "Applying balanced fertilizer for roses\n";
}

void RoseCare::prune() {
    std::cout << "Pruning dead roses and shaping bush\n";
}

void RoseCare::additionalCare() {
    std::cout << "Checking for pests and diseases on rose leaves\n";
}