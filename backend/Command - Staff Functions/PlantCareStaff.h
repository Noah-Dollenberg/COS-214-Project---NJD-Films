#ifndef PLANTCARESTAFF_H
#define PLANTCARESTAFF_H
#include "StaffMember.h"

class WaterPlantsCommand;
class PrunePlantsCommand;
class FertilizePlantsCommand;
class PlantCareContext;

class PlantCareStaff : public StaffMember {
public:
    PlantCareStaff(const std::string& memberName = "Plant Care Staff");
    virtual ~PlantCareStaff() = default;
    
    void performDuties() override;
    void waterPlants();
    void prunePlants();
    void fertilizePlants();
};

#endif // PLANTCARESTAFF_H
