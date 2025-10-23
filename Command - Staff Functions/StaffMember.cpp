#include "StaffMember.h"

StaffMember::StaffMember(const std::string& memberName, const std::string& memberRole)
    : name(memberName), role(memberRole) {
}

std::string StaffMember::getName() const {
    return name;
}

std::string StaffMember::getRole() const {
    return role;
}
