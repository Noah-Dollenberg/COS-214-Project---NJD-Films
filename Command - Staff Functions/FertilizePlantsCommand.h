#ifndef FERTILIZEPLANTSCOMMAND_H
#define FERTILIZEPLANTSCOMMAND_H
#include "StaffCommand.h"

class PlantCareStaff;

class FertilizePlantsCommand : public StaffCommand {
private:
    PlantCareStaff* receiver;
    
public:
    FertilizePlantsCommand(PlantCareStaff* staff);
    virtual ~FertilizePlantsCommand() = default;
    
    void execute() override;
};

#endif // FERTILIZEPLANTSCOMMAND_H
