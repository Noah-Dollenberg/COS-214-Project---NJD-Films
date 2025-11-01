/**
 * @file PlantCareRoutine.cpp
 * @brief Implementation of the PlantCareRoutine abstract base class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 * 
 * This file contains the implementation of the PlantCareRoutine class,
 * which serves as the AbstractClass in the Template Method design pattern.
 * It defines the skeleton algorithm for plant care while allowing
 * subclasses to customize specific steps.
 * 
 * @par Implementation Details:
 * The template method implementation ensures a consistent care routine
 * across all plant types while maintaining flexibility for plant-specific
 * requirements through virtual method overrides.
 */

#include "PlantCareRoutine.h"
#include <iostream>

/**
 * @brief Template method implementing the plant care algorithm
 * @details Executes the complete care routine in a predefined sequence
 * 
 * This method implements the Template Method pattern by defining the
 * skeleton of the plant care algorithm. It calls primitive operations
 * in a specific order, ensuring consistent care delivery while allowing
 * customization through virtual method implementations in derived classes.
 * 
 * @par Algorithm Implementation:
 * The method follows a strict sequence:
 * 1. Log routine start
 * 2. Delegate soil moisture checking to subclass
 * 3. Delegate watering to subclass
 * 4. Delegate fertilization to subclass
 * 5. Delegate pruning to subclass
 * 6. Call optional additional care hook
 * 7. Log routine completion
 * 
 * @par Design Pattern Benefits:
 * - Ensures consistent care routine structure
 * - Prevents subclasses from altering the algorithm sequence
 * - Promotes code reuse through common algorithm skeleton
 * - Enables customization through virtual method overrides
 * - Maintains invariant behavior across plant types
 * 
 * @pre All pure virtual methods must be implemented by concrete subclass
 * @post Complete plant care routine is executed with logging
 * @return void
 * @complexity O(1) + sum of complexities of all virtual method calls
 * @threadsafe Depends on thread-safety of virtual method implementations
 * @exception Depends on virtual method implementations
 * 
 * @note This method should never be overridden by subclasses
 * @warning Ensure all pure virtual methods are properly implemented
 * 
 * @see checkSoilMoisture()
 * @see water()
 * @see fertilize()
 * @see prune()
 * @see additionalCare()
 * 
 * @par Usage Example:
 * @code
 * RoseCare* roseCare = new RoseCare();
 * roseCare->careForPlant(); // Executes rose-specific care routine
 * @endcode
 * 
 * @par Template Method Pattern:
 * This implementation demonstrates the Template Method pattern where:
 * - The algorithm structure is fixed and defined here
 * - Individual steps are customizable through virtual methods
 * - Subclasses cannot change the overall algorithm flow
 * - Common behavior is centralized in the base class
 */
void PlantCareRoutine::careForPlant() {
    std::cout << "Starting plant care routine...\n";
    checkSoilMoisture();
    water();
    fertilize();
    prune();
    additionalCare();
    std::cout << "Plant care routine completed.\n";
}