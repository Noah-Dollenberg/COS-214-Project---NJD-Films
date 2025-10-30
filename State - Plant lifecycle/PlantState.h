#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include <string>

class PlantContext;

class PlantState {
public:
    virtual ~PlantState() = default;
    virtual void water(PlantContext* context) = 0;
    virtual void fertilize(PlantContext* context) = 0;
    virtual void checkHealth(PlantContext* context) = 0;
    virtual std::string getStateName() const = 0;
};

class SeedlingState;
class GrowingState;
class MatureState;
class FloweringState;
class DormantState;

#endif // PLANTSTATE_H