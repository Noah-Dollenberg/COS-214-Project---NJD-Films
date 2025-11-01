/**
 * @file PlantCareStaff.h
 * @brief Concrete Receiver for plant care operations
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef PLANTCARESTAFF_H
#define PLANTCARESTAFF_H
#include "StaffMember.h"

// Forward declarations
class WaterPlantsCommand;
class PrunePlantsCommand;
class FertilizePlantsCommand;
class PlantCareContext;

/**
 * @class PlantCareStaff
 * @brief Concrete Receiver class for plant maintenance operations
 * 
 * PlantCareStaff is a concrete implementation of StaffMember that serves as
 * the Receiver in the Command design pattern for plant care operations. This
 * class knows how to perform the actual work when plant care commands are executed.
 * 
 * The staff member provides three primary operations:
 * - waterPlants(): Handles plant watering and irrigation
 * - prunePlants(): Manages plant trimming and maintenance
 * - fertilizePlants(): Applies nutrients and fertilizer to plants
 * 
 * These methods are invoked by corresponding command objects (WaterPlantsCommand,
 * PrunePlantsCommand, FertilizePlantsCommand), demonstrating the decoupling
 * between requesters and performers in the Command pattern.
 * 
 * @note This is a Receiver in the Command pattern
 * @see StaffMember, WaterPlantsCommand, PrunePlantsCommand, FertilizePlantsCommand
 * 
 * Example usage:
 * @code
 * PlantCareStaff* gardener = new PlantCareStaff("Alex");
 * 
 * // Create commands that delegate to this receiver
 * WaterPlantsCommand* waterCmd = new WaterPlantsCommand(gardener);
 * PrunePlantsCommand* pruneCmd = new PrunePlantsCommand(gardener);
 * FertilizePlantsCommand* fertilizeCmd = new FertilizePlantsCommand(gardener);
 * 
 * // Schedule and execute tasks
 * TaskScheduler scheduler;
 * scheduler.addCommand(waterCmd);
 * scheduler.addCommand(pruneCmd);
 * scheduler.addCommand(fertilizeCmd);
 * scheduler.executeCommands();
 * 
 * // Or perform duties directly
 * gardener->performDuties();  // Calls all three methods
 * @endcode
 */
class PlantCareStaff : public StaffMember {
public:
    /**
     * @brief Constructs a PlantCareStaff member with a name
     * @param memberName The name of the plant care staff member (default: "Plant Care Staff")
     * 
     * Creates a new plant care staff member with the specified name.
     * The role is automatically set to identify this as plant care staff.
     */
    PlantCareStaff(const std::string& memberName = "Plant Care Staff");
    
    /**
     * @brief Virtual destructor for cleanup
     * 
     * Default destructor is sufficient for this class.
     */
    virtual ~PlantCareStaff() = default;
    
    /**
     * @brief Performs all plant care duties in sequence
     * 
     * Executes a complete plant care routine by calling waterPlants(),
     * prunePlants(), and fertilizePlants() in order. This provides a
     * comprehensive maintenance cycle for all plants under care.
     * 
     * @post All plant care tasks have been completed
     * @post Plants have been watered, pruned, and fertilized
     */
    void performDuties() override;
    
    /**
     * @brief Waters all plants under care
     * 
     * Performs watering operations on plants. This method is called by
     * WaterPlantsCommand when that command is executed. The implementation
     * typically checks soil moisture, determines water needs, and applies
     * appropriate amounts of water to each plant.
     * 
     * @post All designated plants have been watered
     * @post Watering records updated
     */
    void waterPlants();
    
    /**
     * @brief Prunes plants that require trimming
     * 
     * Performs pruning operations on plants. This method is called by
     * PrunePlantsCommand when that command is executed. The implementation
     * typically removes dead or overgrown branches, shapes plants, and
     * maintains plant health through selective trimming.
     * 
     * @post Plants requiring pruning have been trimmed
     * @post Pruning records updated
     * @post Plant health and appearance improved
     */
    void prunePlants();
    
    /**
     * @brief Fertilizes plants to provide nutrients
     * 
     * Performs fertilization operations on plants. This method is called by
     * FertilizePlantsCommand when that command is executed. The implementation
     * typically assesses nutrient needs, applies appropriate fertilizers, and
     * ensures plants receive necessary nutrients for healthy growth.
     * 
     * @post Plants have been fertilized appropriately
     * @post Fertilization records updated
     * @post Plants have enhanced nutrient availability
     */
    void fertilizePlants();
};

#endif // PLANTCARESTAFF_H
