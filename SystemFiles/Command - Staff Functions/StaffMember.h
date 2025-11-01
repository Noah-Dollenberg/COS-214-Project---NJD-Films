#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H
#include <string>

class StaffMember {
protected:
    std::string name;
    std::string role;
    
public:
    StaffMember(const std::string& memberName = "Staff", const std::string& memberRole = "General");
    virtual ~StaffMember() = default;
    
    virtual void performDuties() = 0;
    std::string getName() const;
    std::string getRole() const;
};

#endif // STAFFMEMBER_H
