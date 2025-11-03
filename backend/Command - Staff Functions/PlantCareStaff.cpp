#include "PlantCareStaff.h"
#include <iostream>

PlantCareStaff::PlantCareStaff(const std::string& memberName)
    : StaffMember(memberName, "Plant Care") {
}

void PlantCareStaff::performDuties() {
    std::cout << name << " is performing plant care duties..." << std::endl;
}

void PlantCareStaff::waterPlants() {
    std::cout << name << " is watering the plants." << std::endl;
}

void PlantCareStaff::prunePlants() {
    std::cout << name << " is pruning the plants." << std::endl;
}

void PlantCareStaff::fertilizePlants() {
    std::cout << name << " is fertilizing the plants." << std::endl;
}
