#ifndef ASSISTCUSTOMERCOMMAND_H
#define ASSISTCUSTOMERCOMMAND_H
#include "StaffCommand.h"

class SalesStaff;

class AssistCustomerCommand : public StaffCommand {
private:
    SalesStaff* receiver;
    
public:
    AssistCustomerCommand(SalesStaff* staff);
    virtual ~AssistCustomerCommand() = default;
    
    void execute() override;
};

#endif // ASSISTCUSTOMERCOMMAND_H
