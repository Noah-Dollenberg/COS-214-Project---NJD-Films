#ifndef SEEDLINGSTATE_H
#define SEEDLINGSTATE_H

#include "PlantState.h"

class SeedlingState : public PlantState {
public:
    virtual ~SeedlingState() = default;
    void water(PlantContext* context) override;
    void fertilize(PlantContext* context) override;
    void checkHealth(PlantContext* context) override;
    std::string getStateName() const override { return "Seedling"; }
};

#endif // SEEDLINGSTATE_H