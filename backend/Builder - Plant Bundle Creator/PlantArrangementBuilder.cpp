#include "PlantArrangementBuilder.h"
#include "PlantArrangement.h"

PlantArrangementBuilder::PlantArrangementBuilder() : arrangement(nullptr) {}

PlantArrangementBuilder::~PlantArrangementBuilder() {
    // Don't delete arrangement here - it's returned to client
}

PlantArrangement* PlantArrangementBuilder::getArrangement() {
    PlantArrangement* result = arrangement;
    arrangement = nullptr;  // Transfer ownership
    return result;
}
