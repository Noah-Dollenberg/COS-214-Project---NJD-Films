/**
 * @file WaterPlantsCommand.h
 * @brief Concrete Command for plant watering operations
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef WATERPLANTSCOMMAND_H
#define WATERPLANTSCOMMAND_H
#include "StaffCommand.h"

// Forward declaration
class PlantCareStaff;

/**
 * @class WaterPlantsCommand
 * @brief Concrete Command that encapsulates plant watering requests
 * 
 * WaterPlantsCommand is a concrete implementation of the StaffCommand interface
 * that encapsulates the action of watering plants. This is a ConcreteCommand
 * in the Command design pattern.
 * 
 * The command object holds a reference to a PlantCareStaff receiver and delegates
 * the actual watering work to that receiver when executed. This decouples the
 * request (water plants) from the object that performs it (PlantCareStaff).
 * 
 * Watering is the most fundamental plant care task, ensuring plants receive
 * adequate hydration for survival and growth. Different plants require different
 * watering frequencies and amounts.
 * 
 * Benefits:
 * - Watering schedules can be automated and queued
 * - Multiple watering tasks can be batched efficiently
 * - Commands can be logged for irrigation tracking
 * - Task execution is independent of staff implementation
 * 
 * Typical use cases:
 * - Daily/weekly watering routines
 * - Automated irrigation schedules
 * - Emergency watering during heat waves
 * - Integration with greenhouse automation systems
 * 
 * @note This command is specific to PlantCareStaff receivers
 * @see StaffCommand, PlantCareStaff, TaskScheduler
 * 
 * Example usage:
 * @code
 * PlantCareStaff* gardener = new PlantCareStaff("Mike", "Irrigation Specialist");
 * WaterPlantsCommand* morningWatering = new WaterPlantsCommand(gardener);
 * WaterPlantsCommand* eveningWatering = new WaterPlantsCommand(gardener);
 * 
 * TaskScheduler morningSchedule;
 * morningSchedule.addTask(morningWatering);
 * morningSchedule.executeTasks();  // Morning watering
 * 
 * TaskScheduler eveningSchedule;
 * eveningSchedule.addTask(eveningWatering);
 * eveningSchedule.executeTasks();  // Evening watering
 * 
 * // Combined with other care tasks
 * TaskScheduler dailyRoutine;
 * dailyRoutine.addTask(new WaterPlantsCommand(gardener));
 * dailyRoutine.addTask(new PrunePlantsCommand(gardener));
 * dailyRoutine.addTask(new FertilizePlantsCommand(gardener));
 * dailyRoutine.executeTasks();  // Complete daily routine
 * @endcode
 */
class WaterPlantsCommand : public StaffCommand {
private:
    /**
     * @brief Pointer to the PlantCareStaff receiver
     * 
     * Stores a reference to the PlantCareStaff member who will perform the
     * watering when this command is executed. The command delegates the
     * actual work to this receiver's waterPlants() method.
     * 
     * @note The command does not own the receiver - caller manages lifetime
     */
    PlantCareStaff* receiver;
    
public:
    /**
     * @brief Constructs a WaterPlantsCommand for specific plant care staff
     * @param staff Pointer to the PlantCareStaff who will water plants
     * 
     * Creates a command that will delegate plant watering to the specified
     * plant care staff member when executed.
     * 
     * @pre staff must not be nullptr
     * @note Command does not take ownership of staff
     */
    WaterPlantsCommand(PlantCareStaff* staff);
    
    /**
     * @brief Virtual destructor for cleanup
     * 
     * Default destructor is sufficient as the command doesn't own the receiver.
     */
    virtual ~WaterPlantsCommand() = default;
    
    /**
     * @brief Executes the plant watering command
     * 
     * Delegates to the receiver's waterPlants() method to perform the actual
     * watering work. This is called by the TaskScheduler when it's time to
     * execute this command.
     * 
     * The receiver will typically:
     * - Check soil moisture levels
     * - Determine which plants need water
     * - Apply appropriate water amounts per plant type
     * - Ensure proper drainage
     * - Update watering logs and schedules
     * 
     * @post All designated plants have been watered appropriately
     * @post Watering records have been updated
     * @post Plants have adequate hydration for their needs
     */
    void execute() override;
};

#endif // WATERPLANTSCOMMAND_H
