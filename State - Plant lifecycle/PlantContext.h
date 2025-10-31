#ifndef PLANTCONTEXT_H
#define PLANTCONTEXT_H
#include <vector>
#include "PlantState.h"
#include "../Plant - Abstract Base/Plant.h"

class PlantContext {
private:
    PlantState* currentState;
    Plant* plant;
    std::vector<Plant*> plants;

public:
    PlantContext(Plant* p) : currentState(nullptr), plant(p) {}
    virtual ~PlantContext() { delete currentState; }
    void setState(PlantState* state) { delete currentState; currentState = state; }
    PlantState* getCurrentState() const { return currentState; }
    void water() { if (currentState) currentState->water(this); }
    void fertilize() { if (currentState) currentState->fertilize(this); }
    void checkHealth() { if (currentState) currentState->checkHealth(this); }
    Plant* getPlant() const { return plant; }
};

#endif // PLANTCONTEXT_H