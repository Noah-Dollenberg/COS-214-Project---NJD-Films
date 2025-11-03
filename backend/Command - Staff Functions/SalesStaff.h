#ifndef SALESSTAFF_H
#define SALESSTAFF_H
#include "StaffMember.h"

class AssistCustomerCommand;

class SalesStaff : public StaffMember {
public:
    SalesStaff(const std::string& memberName = "Sales Staff");
    virtual ~SalesStaff() = default;
    
    void performDuties() override;
    void assistCustomer();
};

#endif // SALESSTAFF_H
