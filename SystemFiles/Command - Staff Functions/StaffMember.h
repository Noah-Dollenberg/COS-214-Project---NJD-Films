/**
 * @file StaffMember.h
 * @brief Abstract base class for staff members (Receiver in Command pattern)
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H
#include <string>

/**
 * @class StaffMember
 * @brief Abstract Receiver class in the Command design pattern
 * 
 * StaffMember is the abstract base class for all greenhouse staff members.
 * In the Command pattern, this serves as the Receiver role - the object that
 * knows how to perform the actual work when a command is executed.
 * 
 * The Command pattern decouples the invoker (TaskScheduler) from the receiver
 * (StaffMember) by introducing command objects that encapsulate the method calls.
 * This allows for flexible task scheduling, queueing, and execution without
 * tight coupling between schedulers and staff.
 * 
 * Concrete staff classes (PlantCareStaff, SalesStaff) implement specific duties
 * like watering plants, pruning, fertilizing, or assisting customers. Each
 * concrete class provides the actual implementation of performDuties() and
 * additional specialized methods.
 * 
 * @note This is an abstract class - cannot be instantiated directly
 * @see StaffCommand, PlantCareStaff, SalesStaff, TaskScheduler
 * 
 * Example usage:
 * @code
 * StaffMember* gardener = new PlantCareStaff("Alice", "Senior Gardener");
 * StaffMember* sales = new SalesStaff("Bob", "Sales Associate");
 * 
 * // Commands delegate to these receivers
 * StaffCommand* waterCmd = new WaterPlantsCommand(gardener);
 * StaffCommand* assistCmd = new AssistCustomerCommand(sales);
 * 
 * waterCmd->execute();   // Calls gardener's waterPlants() method
 * assistCmd->execute();  // Calls sales's assistCustomer() method
 * @endcode
 */
class StaffMember {
protected:
    /**
     * @brief Name of the staff member
     * 
     * Stores the staff member's name for identification and display purposes.
     */
    std::string name;
    
    /**
     * @brief Role or job title of the staff member
     * 
     * Describes the staff member's position (e.g., "Gardener", "Sales Associate",
     * "Plant Care Specialist"). This helps identify their responsibilities.
     */
    std::string role;
    
public:
    /**
     * @brief Constructs a StaffMember with a name and role
     * @param memberName The name of the staff member (default: "Staff")
     * @param memberRole The role/title of the staff member (default: "General")
     * 
     * Creates a new staff member with the specified name and role. Concrete
     * subclasses should call this constructor to initialize the base attributes.
     */
    StaffMember(const std::string& memberName = "Staff", const std::string& memberRole = "General");
    
    /**
     * @brief Virtual destructor for proper cleanup
     * 
     * Ensures derived staff classes are properly destroyed when deleted
     * through a base class pointer.
     */
    virtual ~StaffMember() = default;
    
    /**
     * @brief Pure virtual method to perform staff member's duties
     * 
     * This method must be implemented by all concrete staff classes.
     * It defines the general work routine for this type of staff member.
     * Concrete implementations typically call multiple specialized methods
     * in sequence to complete their duties.
     * 
     * @post The staff member's duties have been performed
     * 
     * Example implementations:
     * @code
     * // In PlantCareStaff:
     * void performDuties() override {
     *     waterPlants();
     *     prunePlants();
     *     fertilizePlants();
     * }
     * 
     * // In SalesStaff:
     * void performDuties() override {
     *     greetCustomers();
     *     processOrders();
     *     assistCustomers();
     * }
     * @endcode
     */
    virtual void performDuties() = 0;
    
    /**
     * @brief Gets the staff member's name
     * @return The name of the staff member
     */
    std::string getName() const;
    
    /**
     * @brief Gets the staff member's role
     * @return The role/title of the staff member
     */
    std::string getRole() const;
};

#endif // STAFFMEMBER_H
