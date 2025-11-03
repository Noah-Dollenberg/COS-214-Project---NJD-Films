/**
 * @file PlantCareContext.cpp
 * @brief Implementation of the PlantCareContext class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 * 
 * This file contains the implementation of the PlantCareContext class,
 * which serves as the Context component in the Strategy design pattern.
 * It manages the delegation of plant care operations to different
 * strategy implementations.
 * 
 * @par Implementation Details:
 * The context maintains loose coupling with strategy implementations
 * by working through the abstract PlantCareStrategy interface. This
 * allows for easy extension and modification of care strategies without
 * affecting the context implementation.
 */

#include "PlantCareContext.h"
#include "PlantCareStrategy.h"

/**
 * @brief Sets the care strategy for the plant
 * @param s Pointer to the PlantCareStrategy implementation to use
 * 
 * This method implements the strategy setter functionality, allowing
 * the context to switch between different care strategies at runtime.
 * The method simply assigns the provided strategy pointer to the
 * internal strategy member variable.
 * 
 * @par Implementation Notes:
 * - No validation is performed on the input parameter
 * - Previous strategy reference is overwritten without cleanup
 * - Caller retains ownership of strategy objects
 * - Supports nullptr assignment to disable strategy execution
 * 
 * @pre None - accepts any PlantCareStrategy pointer including nullptr
 * @post Internal strategy pointer is updated to the provided value
 * @param s Strategy pointer to assign (can be nullptr)
 * @return void
 * @complexity O(1) - Simple pointer assignment
 * @threadsafe Not thread-safe - external synchronization required
 * @exception None - No exceptions thrown
 * 
 * @see executeCare()
 * @see PlantCareStrategy
 * 
 * @par Usage Example:
 * @code
 * PlantCareContext context(myPlant);
 * ModerateWatering* strategy = new ModerateWatering();
 * context.setStrategy(strategy);
 * @endcode
 */
void PlantCareContext::setStrategy(PlantCareStrategy* s) {
    strategy = s;
}

/**
 * @brief Executes the current care strategy
 * @details Delegates plant care operations to the active strategy
 * 
 * This method implements the core functionality of the Strategy pattern
 * by delegating the care operation to the currently set strategy. It
 * includes a null check to prevent crashes when no strategy is set.
 * 
 * @par Algorithm:
 * 1. Check if strategy pointer is not nullptr
 * 2. If valid, call careForPlant() on the strategy
 * 3. If nullptr, perform no operation (silent failure)
 * 
 * @par Implementation Notes:
 * - Uses defensive programming with null pointer check
 * - Silent failure when no strategy is set
 * - Delegates all care logic to strategy implementation
 * - No direct plant interaction - strategy handles plant care
 * 
 * @pre Context object must be properly initialized
 * @post Care operations are executed if strategy is available
 * @return void
 * @complexity O(1) + complexity of strategy's careForPlant() method
 * @threadsafe Depends on strategy implementation thread-safety
 * @exception None directly - depends on strategy implementation
 * 
 * @note No operation performed if strategy is nullptr
 * @warning Ensure strategy is set before calling for meaningful results
 * 
 * @see setStrategy()
 * @see PlantCareStrategy::careForPlant()
 * 
 * @par Usage Example:
 * @code
 * context.setStrategy(new FrequentWatering());
 * context.executeCare(); // Executes frequent watering strategy
 * @endcode
 * 
 * @todo Consider adding logging for when no strategy is set
 * @todo Consider throwing exception instead of silent failure
 */
void PlantCareContext::executeCare() {
    if (strategy) {
        strategy->careForPlant();
    }
}
