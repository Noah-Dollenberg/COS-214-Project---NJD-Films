#ifndef PLANTCONTEXT_H
#define PLANTCONTEXT_H
#include <vector>

class PlantState;
class Plant;

class PlantContext {
private:
    PlantState* currentState;        // Aggregation
    std::vector<Plant*> plants;      // Composite composition
    
public:
    virtual ~PlantContext() = default;
};

#endif // PLANTCONTEXT_H