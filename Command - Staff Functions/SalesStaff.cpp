#include "SalesStaff.h"
#include <iostream>

SalesStaff::SalesStaff(const std::string& memberName)
    : StaffMember(memberName, "Sales") {
}

void SalesStaff::performDuties() {
    std::cout << name << " is performing sales duties..." << std::endl;
}

void SalesStaff::assistCustomer() {
    std::cout << name << " is assisting a customer." << std::endl;
}
