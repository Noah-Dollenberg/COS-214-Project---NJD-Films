/**
 * @file StaffCommand.h
 * @brief Abstract Command interface for the Command design pattern
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef STAFFCOMMAND_H
#define STAFFCOMMAND_H

/**
 * @class StaffCommand
 * @brief Abstract Command interface in the Command design pattern
 * 
 * StaffCommand defines the interface for all command objects in the Command pattern.
 * It encapsulates staff actions as objects, allowing for parameterization of clients
 * with different requests, queueing of requests, and logging of operations.
 * 
 * The Command pattern decouples the object that invokes the operation (TaskScheduler)
 * from the object that knows how to perform it (concrete StaffMember classes).
 * 
 * Key benefits:
 * - Encapsulates a request as an object
 * - Allows parameterization of methods with different requests
 * - Supports queuing and logging of operations
 * - Enables undo/redo functionality (if implemented)
 * 
 * Concrete command classes (WaterPlantsCommand, PrunePlantsCommand, etc.) implement
 * the execute() method to perform specific staff tasks.
 * 
 * @note This is an abstract interface - cannot be instantiated directly
 * @see WaterPlantsCommand, PrunePlantsCommand, FertilizePlantsCommand, AssistCustomerCommand
 * @see TaskScheduler, StaffMember
 * 
 * Example usage:
 * @code
 * StaffMember* gardener = new PlantCareStaff("John", "Gardener");
 * StaffCommand* waterCmd = new WaterPlantsCommand(gardener);
 * StaffCommand* pruneCmd = new PrunePlantsCommand(gardener);
 * 
 * TaskScheduler scheduler;
 * scheduler.addTask(waterCmd);
 * scheduler.addTask(pruneCmd);
 * scheduler.executeTasks();  // Executes all commands in order
 * @endcode
 */
class StaffCommand {
public:
    /**
     * @brief Virtual destructor for proper cleanup of derived classes
     * 
     * Ensures that derived command classes are properly destroyed when
     * deleted through a base class pointer, preventing memory leaks.
     */
    virtual ~StaffCommand() = default;
    
    /**
     * @brief Pure virtual method to execute the command
     * 
     * This method must be implemented by all concrete command classes.
     * It encapsulates the action to be performed, typically delegating
     * to a receiver object (StaffMember) to carry out the actual work.
     * 
     * The execute() method is called by the invoker (TaskScheduler) when
     * it's time to perform the command. The command object knows which
     * receiver to call and which method to invoke.
     * 
     * @post The command's action has been performed
     * 
     * Example implementations:
     * @code
     * // In WaterPlantsCommand:
     * void execute() override {
     *     receiver->waterPlants();  // Delegate to receiver
     * }
     * 
     * // In PrunePlantsCommand:
     * void execute() override {
     *     receiver->prunePlants();  // Delegate to receiver
     * }
     * @endcode
     */
    virtual void execute() = 0;
};

#endif // STAFFCOMMAND_H
