#ifndef DORMANTSTATE_H
#define DORMANTSTATE_H

#include "PlantState.h"

class DormantState : public PlantState {
public:
    virtual ~DormantState() = default;
    void water(PlantContext* context) override;
    void fertilize(PlantContext* context) override;
    void checkHealth(PlantContext* context) override;
    std::string getStateName() const override { return "Dormant"; }
};

#endif // DORMANTSTATE_H