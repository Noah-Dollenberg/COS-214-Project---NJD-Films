#ifndef STAFFCOMMAND_H
#define STAFFCOMMAND_H

class StaffCommand {
public:
    virtual ~StaffCommand() = default;
    
    virtual void execute() = 0;
};

#endif // STAFFCOMMAND_H
