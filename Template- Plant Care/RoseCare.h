#ifndef ROSECARE_H
#define ROSECARE_H
#include "PlantCareRoutine.h"

class RoseCare : public PlantCareRoutine {
public:
    virtual ~RoseCare() = default;
    
protected:
    void checkSoilMoisture() override;
    void water() override;
    void fertilize() override;
    void prune() override;
    void additionalCare() override;
};

#endif
