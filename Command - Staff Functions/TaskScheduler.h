/**
 * @file TaskScheduler.h
 * @brief Invoker class for the Command design pattern
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef TASKSCHEDULER_H
#define TASKSCHEDULER_H
#include <vector>

// Forward declarations
class StaffCommand;
class PlantCareRoutine;

/**
 * @class TaskScheduler
 * @brief Invoker class that manages and executes command objects
 * 
 * TaskScheduler is the Invoker in the Command design pattern. It is responsible
 * for storing, managing, and executing command objects without knowing the
 * specific details of what those commands do or which receivers perform the work.
 * 
 * This class demonstrates the key benefit of the Command pattern: complete
 * decoupling between the requester (scheduler) and the performer (staff members).
 * The scheduler simply calls execute() on command objects, and the commands
 * handle delegating to the appropriate receivers.
 * 
 * Key features:
 * - Command queue management (add, clear, count)
 * - Batch command execution
 * - Command history tracking
 * - Integration with plant care routines
 * 
 * Benefits:
 * - Commands can be queued and executed later
 * - Easy to add new command types without changing the scheduler
 * - Commands can be logged, undone, or replayed (history support)
 * - Supports macro commands and complex task sequences
 * 
 * @note This is the Invoker in the Command pattern
 * @see StaffCommand, PlantCareStaff, SalesStaff
 * 
 * Example usage:
 * @code
 * TaskScheduler scheduler;
 * 
 * PlantCareStaff* gardener = new PlantCareStaff("John");
 * SalesStaff* sales = new SalesStaff("Mary");
 * 
 * // Queue up various tasks
 * scheduler.addCommand(new WaterPlantsCommand(gardener));
 * scheduler.addCommand(new AssistCustomerCommand(sales));
 * scheduler.addCommand(new PrunePlantsCommand(gardener));
 * scheduler.addCommand(new FertilizePlantsCommand(gardener));
 * 
 * std::cout << "Tasks queued: " << scheduler.getCommandCount() << std::endl;
 * 
 * // Execute all tasks in order
 * scheduler.executeCommands();
 * 
 * // Commands are now in history, queue is cleared
 * scheduler.clearCommands();  // Clear history if needed
 * @endcode
 */
class TaskScheduler {
private:
    /**
     * @brief Queue of commands waiting to be executed
     * 
     * Stores pointers to StaffCommand objects that have been added but not
     * yet executed. Commands are executed in the order they were added (FIFO).
     * After execution, commands are moved to commandHistory.
     */
    std::vector<StaffCommand*> commands;
    
    /**
     * @brief History of executed commands
     * 
     * Stores pointers to commands that have already been executed. This
     * supports command logging, auditing, and potential undo functionality.
     * Commands are moved here from the commands queue after execution.
     */
    std::vector<StaffCommand*> commandHistory;
    
    /**
     * @brief Optional plant care routine for integration
     * 
     * Pointer to a PlantCareRoutine that can be coordinated with the
     * command execution. Allows integration between command-based tasks
     * and template-based care routines.
     * 
     * @note Scheduler does not own the routine - caller manages lifetime
     */
    PlantCareRoutine* routine;
    
public:
    /**
     * @brief Constructs an empty TaskScheduler
     * 
     * Creates a new task scheduler with empty command queue and history.
     * The routine pointer is initialized to nullptr.
     * 
     * @post Command queue and history are empty
     * @post routine == nullptr
     */
    TaskScheduler();
    
    /**
     * @brief Virtual destructor for cleanup
     * 
     * Cleans up the scheduler. Note that this does not delete command objects
     * or the routine - caller is responsible for command object lifetime.
     */
    virtual ~TaskScheduler();
    
    /**
     * @brief Adds a command to the execution queue
     * @param command Pointer to the StaffCommand to queue
     * 
     * Appends the command to the end of the commands queue. The command
     * will be executed when executeCommands() is called, in FIFO order.
     * 
     * @note Scheduler does not take ownership - caller manages command lifetime
     * @warning Adding nullptr may cause issues during execution
     * @post Command count increases by 1
     */
    void addCommand(StaffCommand* command);
    
    /**
     * @brief Executes all queued commands in order
     * 
     * Iterates through the commands queue and calls execute() on each
     * command object. After execution, commands are moved to the history.
     * The command queue is cleared after all executions complete.
     * 
     * This demonstrates the Invoker's role: it calls execute() without
     * knowing what the command does or which receiver performs the work.
     * 
     * @post All commands have been executed
     * @post Command queue is empty
     * @post Executed commands are in commandHistory
     */
    void executeCommands();
    
    /**
     * @brief Executes a single command immediately
     * @param command Pointer to the StaffCommand to execute
     * 
     * Executes the specified command immediately without adding it to
     * the queue. Useful for one-off command execution. The command is
     * added to history after execution.
     * 
     * @note Does not add to queue - executes immediately
     * @post Command has been executed and added to history
     */
    void executeCommand(StaffCommand* command);
    
    /**
     * @brief Clears all commands from queue and history
     * 
     * Removes all command pointers from both the queue and history vectors.
     * Does not delete the command objects themselves.
     * 
     * @note Does not delete command objects - caller must handle cleanup
     * @post Command queue and history are empty
     * @post getCommandCount() returns 0
     */
    void clearCommands();
    
    /**
     * @brief Gets the number of queued commands
     * @return The count of commands waiting to be executed
     * 
     * Returns the size of the commands queue (not including history).
     * Useful for checking if there are pending tasks.
     */
    int getCommandCount() const;
    
    /**
     * @brief Sets the plant care routine for integration
     * @param r Pointer to a PlantCareRoutine to coordinate with
     * 
     * Associates a plant care routine with this scheduler. Allows
     * coordination between command-based tasks and template method
     * routines.
     * 
     * @note Scheduler does not take ownership of the routine
     */
    void setRoutine(PlantCareRoutine* r);
};

#endif // TASKSCHEDULER_H
