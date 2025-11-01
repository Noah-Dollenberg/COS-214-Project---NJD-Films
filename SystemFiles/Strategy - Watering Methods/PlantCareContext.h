/**
 * @file PlantCareContext.h
 * @brief Header file for the PlantCareContext class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 */

#ifndef PLANTCARECONTEXT_H
#define PLANTCARECONTEXT_H

// Forward declarations
class PlantCareStrategy;
class Plant;

/**
 * @class PlantCareContext
 * @brief Context class for the Strategy pattern in plant care system
 * @ingroup Strategy
 * 
 * This class serves as the Context in the Strategy design pattern,
 * managing the relationship between a Plant and its care strategy.
 * It allows dynamic switching between different plant care strategies
 * at runtime, providing flexibility in how plants are cared for.
 * 
 * The PlantCareContext maintains references to both a Plant object
 * and a PlantCareStrategy, delegating care operations to the current
 * strategy while maintaining the plant's state and information.
 * 
 * @par Design Pattern Role:
 * - Context: PlantCareContext (this class)
 * - Strategy: PlantCareStrategy
 * - ConcreteStrategy: FrequentWatering, ModerateWatering, MinimalWatering
 * 
 * @par Usage Example:
 * @code
 * Plant* myPlant = new Rose();
 * PlantCareContext context(myPlant);
 * context.setStrategy(new ModerateWatering());
 * context.executeCare();
 * @endcode
 * 
 * @see PlantCareStrategy
 * @see Plant
 * @see FrequentWatering
 * @see ModerateWatering
 * @see MinimalWatering
 */
class PlantCareContext {
private:
    /**
     * @brief Pointer to the current care strategy
     * @details Holds reference to the active PlantCareStrategy implementation
     */
    PlantCareStrategy* strategy;
    
    /**
     * @brief Pointer to the plant being cared for
     * @details Maintains reference to the Plant object receiving care
     */
    Plant* plant;
    
public:
    /**
     * @brief Constructor with plant parameter
     * @param p Pointer to the Plant object to be cared for
     * 
     * Initializes the context with a plant reference and sets the
     * strategy to nullptr. The strategy must be set separately using
     * setStrategy() before calling executeCare().
     * 
     * @pre p must be a valid Plant pointer (not nullptr)
     * @post Context is initialized with plant reference, strategy is nullptr
     * @note Strategy must be set before executing care operations
     */
    PlantCareContext(Plant* p) : plant(p), strategy(nullptr) {}
    
    /**
     * @brief Virtual destructor
     * @details Ensures proper cleanup of context objects
     * 
     * @note Does not delete plant or strategy objects - ownership
     *       remains with the caller
     */
    virtual ~PlantCareContext() = default;
    
    /**
     * @brief Sets the care strategy for the plant
     * @param s Pointer to the PlantCareStrategy to use
     * 
     * Changes the current care strategy to the provided strategy.
     * This allows runtime switching between different care approaches
     * based on plant needs or environmental conditions.
     * 
     * @pre s should be a valid PlantCareStrategy pointer
     * @post strategy member is updated to point to s
     * @note Previous strategy is not deleted - caller retains ownership
     * @warning Passing nullptr will disable care execution
     */
    void setStrategy(PlantCareStrategy* s);
    
    /**
     * @brief Executes the current care strategy
     * @details Delegates care operations to the current strategy
     * 
     * Calls the careForPlant() method on the current strategy if one
     * is set. If no strategy is set (strategy is nullptr), no action
     * is taken.
     * 
     * @pre Context should have a valid strategy set
     * @post Care instructions are executed according to current strategy
     * @note No operation performed if strategy is nullptr
     * @warning Ensure strategy is set before calling this method
     */
    void executeCare();
};

#endif // PLANTCARECONTEXT_H