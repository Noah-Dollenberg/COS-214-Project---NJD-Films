#ifndef NURSERYMANAGER_H
#define NURSERYMANAGER_H
#include <vector>

class PlantPrototype;

class NurseryManager {
private:
    std::vector<PlantPrototype*> prototypes;  // Aggregation
    
public:
    virtual ~NurseryManager() = default;
};

#endif // NURSERYMANAGER_H