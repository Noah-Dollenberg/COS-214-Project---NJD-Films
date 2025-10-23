#ifndef PLANTARRANGEMENT_H
#define PLANTARRANGEMENT_H
#include <vector>

class Plant;

class PlantArrangement {
private:
    std::vector<Plant*> plants;  // Aggregation
    
public:
    virtual ~PlantArrangement() = default;
};

#endif // PLANTARRANGEMENT_H