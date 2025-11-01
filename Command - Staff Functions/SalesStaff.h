/**
 * @file SalesStaff.h
 * @brief Concrete Receiver for customer service operations
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef SALESSTAFF_H
#define SALESSTAFF_H
#include "StaffMember.h"

// Forward declaration
class AssistCustomerCommand;

/**
 * @class SalesStaff
 * @brief Concrete Receiver class for customer service operations
 * 
 * SalesStaff is a concrete implementation of StaffMember that serves as the
 * Receiver in the Command design pattern for customer service operations. This
 * class knows how to perform the actual work when customer assistance commands
 * are executed.
 * 
 * The staff member provides customer service operations through the assistCustomer()
 * method, which is invoked by AssistCustomerCommand objects. This demonstrates
 * the Command pattern's decoupling between the command (request) and the receiver
 * (performer).
 * 
 * Typical responsibilities include:
 * - Greeting and welcoming customers
 * - Answering questions about plants and products
 * - Processing sales transactions
 * - Providing plant care advice
 * - Managing customer relationships
 * 
 * @note This is a Receiver in the Command pattern
 * @see StaffMember, AssistCustomerCommand, TaskScheduler
 * 
 * Example usage:
 * @code
 * SalesStaff* salesPerson = new SalesStaff("Emma");
 * 
 * // Create commands that delegate to this receiver
 * AssistCustomerCommand* assist1 = new AssistCustomerCommand(salesPerson);
 * AssistCustomerCommand* assist2 = new AssistCustomerCommand(salesPerson);
 * 
 * // Queue multiple customer assistance tasks
 * TaskScheduler scheduler;
 * scheduler.addCommand(assist1);
 * scheduler.addCommand(assist2);
 * scheduler.executeCommands();
 * 
 * // Or perform duties directly
 * salesPerson->performDuties();  // Calls assistCustomer()
 * @endcode
 */
class SalesStaff : public StaffMember {
public:
    /**
     * @brief Constructs a SalesStaff member with a name
     * @param memberName The name of the sales staff member (default: "Sales Staff")
     * 
     * Creates a new sales staff member with the specified name. The role
     * is automatically set to identify this as sales staff.
     */
    SalesStaff(const std::string& memberName = "Sales Staff");
    
    /**
     * @brief Virtual destructor for cleanup
     * 
     * Default destructor is sufficient for this class.
     */
    virtual ~SalesStaff() = default;
    
    /**
     * @brief Performs all sales staff duties
     * 
     * Executes the primary duty of sales staff by calling assistCustomer().
     * This provides the default behavior when performDuties() is invoked
     * on a sales staff member.
     * 
     * @post Customer service duties have been completed
     */
    void performDuties() override;
    
    /**
     * @brief Assists customers with their needs
     * 
     * Performs customer assistance operations. This method is called by
     * AssistCustomerCommand when that command is executed. The implementation
     * typically involves:
     * - Greeting customers warmly
     * - Answering questions about plants and products
     * - Providing plant care recommendations
     * - Processing purchases and transactions
     * - Ensuring customer satisfaction
     * 
     * This is the core operation of SalesStaff and demonstrates the Receiver
     * role in the Command pattern - the object that knows how to perform
     * the actual work requested by a command.
     * 
     * @post Customer has been assisted
     * @post Customer service records updated
     * @post Customer satisfaction maintained or improved
     */
    void assistCustomer();
};

#endif // SALESSTAFF_H
