#ifndef TREECARE_H
#define TREECARE_H
#include "PlantCareRoutine.h"

class TreeCare : public PlantCareRoutine {
public:
    virtual ~TreeCare() = default;
    
protected:
    void checkSoilMoisture() override;
    void water() override;
    void fertilize() override;
    void prune() override;
    void additionalCare() override;
};

#endif
