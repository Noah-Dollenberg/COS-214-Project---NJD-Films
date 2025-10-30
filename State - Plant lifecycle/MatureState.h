#ifndef MATURESTATE_H
#define MATURESTATE_H

#include "PlantState.h"

class MatureState : public PlantState {
public:
    virtual ~MatureState() = default;
    void water(PlantContext* context) override;
    void fertilize(PlantContext* context) override;
    void checkHealth(PlantContext* context) override;
    std::string getStateName() const override { return "Mature"; }
};

#endif // MATURESTATE_H