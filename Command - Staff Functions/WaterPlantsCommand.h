#ifndef WATERPLANTSCOMMAND_H
#define WATERPLANTSCOMMAND_H
#include "StaffCommand.h"

class PlantCareStaff;

class WaterPlantsCommand : public StaffCommand {
private:
    PlantCareStaff* receiver;
    
public:
    WaterPlantsCommand(PlantCareStaff* staff);
    virtual ~WaterPlantsCommand() = default;
    
    void execute() override;
};

#endif // WATERPLANTSCOMMAND_H
