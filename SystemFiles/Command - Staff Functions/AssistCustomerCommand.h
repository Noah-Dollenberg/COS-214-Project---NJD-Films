/**
 * @file AssistCustomerCommand.h
 * @brief Concrete Command for customer assistance operations
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef ASSISTCUSTOMERCOMMAND_H
#define ASSISTCUSTOMERCOMMAND_H
#include "StaffCommand.h"

// Forward declaration
class SalesStaff;

/**
 * @class AssistCustomerCommand
 * @brief Concrete Command that encapsulates customer assistance requests
 * 
 * AssistCustomerCommand is a concrete implementation of the StaffCommand interface
 * that encapsulates the action of assisting customers. This is a ConcreteCommand
 * in the Command design pattern.
 * 
 * The command object holds a reference to a SalesStaff receiver and delegates
 * the actual work to that receiver when executed. This decouples the request
 * (assist customer) from the object that performs it (SalesStaff).
 * 
 * Benefits:
 * - Customer assistance can be queued and scheduled
 * - Multiple assistance requests can be batched
 * - The command can be logged or undone (if implemented)
 * - Task scheduling is independent of sales staff implementation
 * 
 * @note This command is specific to SalesStaff receivers
 * @see StaffCommand, SalesStaff, TaskScheduler
 * 
 * Example usage:
 * @code
 * SalesStaff* salesPerson = new SalesStaff("Alice", "Sales Associate");
 * AssistCustomerCommand* cmd = new AssistCustomerCommand(salesPerson);
 * 
 * TaskScheduler scheduler;
 * scheduler.addTask(cmd);
 * scheduler.executeTasks();  // Executes: salesPerson->assistCustomer()
 * @endcode
 */
class AssistCustomerCommand : public StaffCommand {
private:
    /**
     * @brief Pointer to the SalesStaff receiver
     * 
     * Stores a reference to the SalesStaff member who will perform the
     * customer assistance when this command is executed. The command
     * delegates the actual work to this receiver.
     * 
     * @note The command does not own the receiver - caller manages lifetime
     */
    SalesStaff* receiver;
    
public:
    /**
     * @brief Constructs an AssistCustomerCommand for a specific sales staff
     * @param staff Pointer to the SalesStaff who will assist customers
     * 
     * Creates a command that will delegate customer assistance to the
     * specified sales staff member when executed.
     * 
     * @pre staff must not be nullptr
     * @note Command does not take ownership of staff
     */
    AssistCustomerCommand(SalesStaff* staff);
    
    /**
     * @brief Virtual destructor for cleanup
     * 
     * Default destructor is sufficient as the command doesn't own the receiver.
     */
    virtual ~AssistCustomerCommand() = default;
    
    /**
     * @brief Executes the customer assistance command
     * 
     * Delegates to the receiver's assistCustomer() method to perform the
     * actual work. This is called by the TaskScheduler when it's time to
     * execute this command.
     * 
     * @post The receiver has assisted a customer
     * @post Appropriate messages or logs have been generated
     */
    void execute() override;
};

#endif // ASSISTCUSTOMERCOMMAND_H
