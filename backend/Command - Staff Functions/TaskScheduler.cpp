#include "TaskScheduler.h"
#include "StaffCommand.h"
#include <iostream>

TaskScheduler::TaskScheduler() : routine(nullptr) {
}

TaskScheduler::~TaskScheduler() {
    // Clear commands but don't delete them - caller manages their lifecycle
    commands.clear();
    commandHistory.clear();
}

void TaskScheduler::addCommand(StaffCommand* command) {
    if (command) {
        commands.push_back(command);
        std::cout << "Task added to scheduler." << std::endl;
    }
}

void TaskScheduler::executeCommands() {
    std::cout << "\n=== Executing Scheduled Tasks ===" << std::endl;
    for (auto command : commands) {
        if (command) {
            command->execute();
            commandHistory.push_back(command);
        }
    }
    commands.clear();
    std::cout << "=== All Tasks Complete ===\n" << std::endl;
}

void TaskScheduler::executeCommand(StaffCommand* command) {
    if (command) {
        std::cout << "Executing immediate task..." << std::endl;
        command->execute();
        commandHistory.push_back(command);
    }
}

void TaskScheduler::clearCommands() {
    commands.clear();
    std::cout << "All scheduled tasks cleared." << std::endl;
}

int TaskScheduler::getCommandCount() const {
    return static_cast<int>(commands.size());
}

void TaskScheduler::setRoutine(PlantCareRoutine* r) {
    routine = r;
}
