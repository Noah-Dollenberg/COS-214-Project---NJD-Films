#ifndef FLOWERINGSTATE_H
#define FLOWERINGSTATE_H

#include "PlantState.h"

class FloweringState : public PlantState {
public:
    virtual ~FloweringState() = default;
    void water(PlantContext* context) override;
    void fertilize(PlantContext* context) override;
    void checkHealth(PlantContext* context) override;
    std::string getStateName() const override { return "Flowering"; }
};

#endif // FLOWERINGSTATE_H