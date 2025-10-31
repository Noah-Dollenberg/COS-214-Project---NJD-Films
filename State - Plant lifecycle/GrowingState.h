#ifndef GROWINGSTATE_H
#define GROWINGSTATE_H

#include "PlantState.h"

class GrowingState : public PlantState {
public:
    virtual ~GrowingState() = default;
    void water(PlantContext* context) override;
    void fertilize(PlantContext* context) override;
    void checkHealth(PlantContext* context) override;
    std::string getStateName() const override { return "Growing"; }
};

#endif // GROWINGSTATE_H