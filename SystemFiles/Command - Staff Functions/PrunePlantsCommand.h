/**
 * @file PrunePlantsCommand.h
 * @brief Concrete Command for plant pruning operations
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef PRUNEPLANTSCOMMAND_H
#define PRUNEPLANTSCOMMAND_H
#include "StaffCommand.h"

// Forward declaration
class PlantCareStaff;

/**
 * @class PrunePlantsCommand
 * @brief Concrete Command that encapsulates plant pruning requests
 * 
 * PrunePlantsCommand is a concrete implementation of the StaffCommand interface
 * that encapsulates the action of pruning plants. This is a ConcreteCommand
 * in the Command design pattern.
 * 
 * The command object holds a reference to a PlantCareStaff receiver and delegates
 * the actual pruning work to that receiver when executed. This decouples the
 * request (prune plants) from the object that performs it (PlantCareStaff).
 * 
 * Pruning is essential for plant health, involving the removal of dead or
 * overgrown branches, stems, and roots to encourage healthy growth and
 * maintain plant shape.
 * 
 * Benefits:
 * - Pruning tasks can be scheduled at optimal times
 * - Multiple pruning operations can be queued
 * - Commands can be logged for plant health tracking
 * - Execution is independent of staff implementation details
 * 
 * Typical use cases:
 * - Seasonal pruning schedules
 * - Post-flowering maintenance
 * - Shape and size management
 * - Disease prevention and control
 * 
 * @note This command is specific to PlantCareStaff receivers
 * @see StaffCommand, PlantCareStaff, TaskScheduler
 * 
 * Example usage:
 * @code
 * PlantCareStaff* gardener = new PlantCareStaff("Sarah", "Master Gardener");
 * PrunePlantsCommand* cmd = new PrunePlantsCommand(gardener);
 * 
 * TaskScheduler scheduler;
 * scheduler.addTask(cmd);
 * scheduler.executeTasks();  // Executes: gardener->prunePlants()
 * 
 * // Typical maintenance sequence
 * scheduler.addTask(new WaterPlantsCommand(gardener));
 * scheduler.addTask(new PrunePlantsCommand(gardener));
 * scheduler.addTask(new FertilizePlantsCommand(gardener));
 * scheduler.executeTasks();  // Complete care routine
 * @endcode
 */
class PrunePlantsCommand : public StaffCommand {
private:
    /**
     * @brief Pointer to the PlantCareStaff receiver
     * 
     * Stores a reference to the PlantCareStaff member who will perform the
     * pruning when this command is executed. The command delegates the
     * actual work to this receiver's prunePlants() method.
     * 
     * @note The command does not own the receiver - caller manages lifetime
     */
    PlantCareStaff* receiver;
    
public:
    /**
     * @brief Constructs a PrunePlantsCommand for specific plant care staff
     * @param staff Pointer to the PlantCareStaff who will prune plants
     * 
     * Creates a command that will delegate plant pruning to the specified
     * plant care staff member when executed.
     * 
     * @pre staff must not be nullptr
     * @note Command does not take ownership of staff
     */
    PrunePlantsCommand(PlantCareStaff* staff);
    
    /**
     * @brief Virtual destructor for cleanup
     * 
     * Default destructor is sufficient as the command doesn't own the receiver.
     */
    virtual ~PrunePlantsCommand() = default;
    
    /**
     * @brief Executes the plant pruning command
     * 
     * Delegates to the receiver's prunePlants() method to perform the actual
     * pruning work. This is called by the TaskScheduler when it's time to
     * execute this command.
     * 
     * The receiver will typically:
     * - Identify plants that need pruning
     * - Remove dead, diseased, or overgrown parts
     * - Shape plants for aesthetic or health reasons
     * - Dispose of pruned material properly
     * - Update plant maintenance records
     * 
     * @post Designated plants have been pruned
     * @post Pruning records have been updated
     * @post Plant health and appearance are improved
     */
    void execute() override;
};

#endif // PRUNEPLANTSCOMMAND_H
