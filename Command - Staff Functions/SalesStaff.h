#ifndef SALESSTAFF_H
#define SALESSTAFF_H
#include "StaffMember.h"

class AssistCustomerCommand;

class SalesStaff : public StaffMember {
private:
    AssistCustomerCommand* assistCommand;  // Aggregation
    
public:
    virtual ~SalesStaff() = default;
};

#endif // SALESSTAFF_H