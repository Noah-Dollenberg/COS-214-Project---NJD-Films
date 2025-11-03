#include "WaterPlantsCommand.h"
#include "PlantCareStaff.h"

WaterPlantsCommand::WaterPlantsCommand(PlantCareStaff* staff)
    : receiver(staff) {
}

void WaterPlantsCommand::execute() {
    if (receiver) {
        receiver->waterPlants();
    }
}
