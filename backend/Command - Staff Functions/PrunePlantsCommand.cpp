#include "PrunePlantsCommand.h"
#include "PlantCareStaff.h"

PrunePlantsCommand::PrunePlantsCommand(PlantCareStaff* staff)
    : receiver(staff) {
}

void PrunePlantsCommand::execute() {
    if (receiver) {
        receiver->prunePlants();
    }
}
