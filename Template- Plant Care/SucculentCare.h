#ifndef SUCCULENTCARE_H
#define SUCCULENTCARE_H
#include "PlantCareRoutine.h"

class SucculentCare : public PlantCareRoutine {
public:
    virtual ~SucculentCare() = default;
    
protected:
    void checkSoilMoisture() override;
    void water() override;
    void fertilize() override;
    void prune() override;
};

#endif