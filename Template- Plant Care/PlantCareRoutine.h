#ifndef PLANTCAREROUTINE_H
#define PLANTCAREROUTINE_H

class PlantCareRoutine {
public:
    virtual ~PlantCareRoutine() = default;
    void careForPlant();
    
protected:
    virtual void checkSoilMoisture() = 0;
    virtual void water() = 0;
    virtual void fertilize() = 0;
    virtual void prune() = 0;
    virtual void additionalCare() {}
};

#endif
