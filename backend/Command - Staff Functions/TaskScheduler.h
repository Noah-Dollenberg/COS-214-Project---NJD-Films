#ifndef TASKSCHEDULER_H
#define TASKSCHEDULER_H
#include <vector>

class StaffCommand;
class PlantCareRoutine;

class TaskScheduler {
private:
    std::vector<StaffCommand*> commands;
    std::vector<StaffCommand*> commandHistory;
    PlantCareRoutine* routine;
    
public:
    TaskScheduler();
    virtual ~TaskScheduler();
    
    void addCommand(StaffCommand* command);
    void executeCommands();
    void executeCommand(StaffCommand* command);
    void clearCommands();
    int getCommandCount() const;
    void setRoutine(PlantCareRoutine* r);
};

#endif // TASKSCHEDULER_H
