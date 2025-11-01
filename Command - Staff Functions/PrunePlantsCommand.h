#ifndef PRUNEPLANTSCOMMAND_H
#define PRUNEPLANTSCOMMAND_H
#include "StaffCommand.h"

class PlantCareStaff;

class PrunePlantsCommand : public StaffCommand {
private:
    PlantCareStaff* receiver;
    
public:
    PrunePlantsCommand(PlantCareStaff* staff);
    virtual ~PrunePlantsCommand() = default;
    
    void execute() override;
};

#endif // PRUNEPLANTSCOMMAND_H
