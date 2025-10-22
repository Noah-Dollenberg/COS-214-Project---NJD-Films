#ifndef PLANT_H
#define PLANT_H

class PlantCareRoutine;
class PlantContext;

class Plant {
private:
    PlantCareRoutine* careRoutine;  // Relationship
    PlantContext* context;           // Composite relationship
    
public:
    virtual ~Plant() = default;
};

#endif // PLANT_H