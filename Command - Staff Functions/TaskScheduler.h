#ifndef TASKSCHEDULER_H
#define TASKSCHEDULER_H
#include <vector>

class StaffCommand;
class PlantCareRoutine;

class TaskScheduler {
private:
    std::vector<StaffCommand*> commands;      // Aggregation
    PlantCareRoutine* routine;                // Instantiates
    
public:
    virtual ~TaskScheduler() = default;
};

#endif // TASKSCHEDULER_H