#ifndef PLANTCARESTAFF_H
#define PLANTCARESTAFF_H
#include "StaffMember.h"

class WaterPlantsCommand;
class PrunePlantsCommand;
class FertilizePlantsCommand;
class PlantCareContext;

class PlantCareStaff : public StaffMember {
private:
    WaterPlantsCommand* waterCommand;          // Aggregation
    PrunePlantsCommand* pruneCommand;          // Aggregation
    FertilizePlantsCommand* fertilizeCommand;  // Aggregation
    PlantCareContext* careContext;             // Instantiates
    
public:
    virtual ~PlantCareStaff() = default;
};

#endif // PLANTCARESTAFF_H