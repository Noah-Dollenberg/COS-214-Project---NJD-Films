#include "FertilizePlantsCommand.h"
#include "PlantCareStaff.h"

FertilizePlantsCommand::FertilizePlantsCommand(PlantCareStaff* staff)
    : receiver(staff) {
}

void FertilizePlantsCommand::execute() {
    if (receiver) {
        receiver->fertilizePlants();
    }
}
