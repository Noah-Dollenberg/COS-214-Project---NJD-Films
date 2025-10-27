#include "PlantCareContext.h"
#include "PlantCareStrategy.h"

void PlantCareContext::setStrategy(PlantCareStrategy* s) {
    strategy = s;
}

void PlantCareContext::executeCare() {
    if (strategy) {
        strategy->careForPlant();
    }
}
