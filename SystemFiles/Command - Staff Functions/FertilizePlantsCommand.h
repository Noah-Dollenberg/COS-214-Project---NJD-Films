/**
 * @file FertilizePlantsCommand.h
 * @brief Concrete Command for plant fertilization operations
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef FERTILIZEPLANTSCOMMAND_H
#define FERTILIZEPLANTSCOMMAND_H
#include "StaffCommand.h"

// Forward declaration
class PlantCareStaff;

/**
 * @class FertilizePlantsCommand
 * @brief Concrete Command that encapsulates plant fertilization requests
 * 
 * FertilizePlantsCommand is a concrete implementation of the StaffCommand interface
 * that encapsulates the action of fertilizing plants. This is a ConcreteCommand
 * in the Command design pattern.
 * 
 * The command object holds a reference to a PlantCareStaff receiver and delegates
 * the actual fertilization work to that receiver when executed. This decouples
 * the request (fertilize plants) from the object that performs it (PlantCareStaff).
 * 
 * Benefits:
 * - Fertilization tasks can be scheduled and queued
 * - Multiple fertilization operations can be batched
 * - Commands can be logged for maintenance records
 * - Task execution is independent of plant care implementation details
 * 
 * Typical use cases:
 * - Scheduled fertilization routines
 * - Batch processing of plant care tasks
 * - Automated greenhouse maintenance systems
 * 
 * @note This command is specific to PlantCareStaff receivers
 * @see StaffCommand, PlantCareStaff, TaskScheduler
 * 
 * Example usage:
 * @code
 * PlantCareStaff* gardener = new PlantCareStaff("John", "Head Gardener");
 * FertilizePlantsCommand* cmd = new FertilizePlantsCommand(gardener);
 * 
 * TaskScheduler scheduler;
 * scheduler.addTask(cmd);
 * scheduler.executeTasks();  // Executes: gardener->fertilizePlants()
 * 
 * // Can be combined with other plant care commands
 * scheduler.addTask(new WaterPlantsCommand(gardener));
 * scheduler.addTask(new FertilizePlantsCommand(gardener));
 * scheduler.addTask(new PrunePlantsCommand(gardener));
 * scheduler.executeTasks();  // Complete plant care routine
 * @endcode
 */
class FertilizePlantsCommand : public StaffCommand {
private:
    /**
     * @brief Pointer to the PlantCareStaff receiver
     * 
     * Stores a reference to the PlantCareStaff member who will perform the
     * fertilization when this command is executed. The command delegates
     * the actual work to this receiver's fertilizePlants() method.
     * 
     * @note The command does not own the receiver - caller manages lifetime
     */
    PlantCareStaff* receiver;
    
public:
    /**
     * @brief Constructs a FertilizePlantsCommand for specific plant care staff
     * @param staff Pointer to the PlantCareStaff who will fertilize plants
     * 
     * Creates a command that will delegate plant fertilization to the
     * specified plant care staff member when executed.
     * 
     * @pre staff must not be nullptr
     * @note Command does not take ownership of staff
     */
    FertilizePlantsCommand(PlantCareStaff* staff);
    
    /**
     * @brief Virtual destructor for cleanup
     * 
     * Default destructor is sufficient as the command doesn't own the receiver.
     */
    virtual ~FertilizePlantsCommand() = default;
    
    /**
     * @brief Executes the plant fertilization command
     * 
     * Delegates to the receiver's fertilizePlants() method to perform the
     * actual fertilization work. This is called by the TaskScheduler when
     * it's time to execute this command.
     * 
     * The receiver will typically:
     * - Check which plants need fertilization
     * - Apply appropriate fertilizer types and amounts
     * - Update plant care records
     * - Log the fertilization activity
     * 
     * @post All designated plants have been fertilized
     * @post Fertilization records have been updated
     */
    void execute() override;
};

#endif // FERTILIZEPLANTSCOMMAND_H
