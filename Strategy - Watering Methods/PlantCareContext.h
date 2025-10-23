#ifndef PLANTCARECONTEXT_H
#define PLANTCARECONTEXT_H

class PlantCareStrategy;
class Plant;

class PlantCareContext {
private:
    PlantCareStrategy* strategy;  // Aggregation
    Plant* plant;                 // Relationship
    
public:
    virtual ~PlantCareContext() = default;
};

#endif // PLANTCARECONTEXT_H