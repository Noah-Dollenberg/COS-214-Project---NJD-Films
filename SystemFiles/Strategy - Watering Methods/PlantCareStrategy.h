/**
 * @file PlantCareStrategy.h
 * @brief Header file for the PlantCareStrategy abstract base class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 */

#ifndef PLANTCARESTRATEGY_H
#define PLANTCARESTRATEGY_H

/**
 * @class PlantCareStrategy
 * @brief Abstract base class for plant care strategies
 * @ingroup Strategy
 * 
 * This abstract class defines the Strategy interface for the Strategy
 * design pattern implementation in the plant care system. It provides
 * a common interface for all concrete plant care strategies, allowing
 * the PlantCareContext to work with different watering approaches
 * interchangeably.
 * 
 * The Strategy pattern enables the plant care system to:
 * - Switch between different watering strategies at runtime
 * - Add new care strategies without modifying existing code
 * - Encapsulate watering algorithms in separate classes
 * - Promote code reusability and maintainability
 * 
 * @par Design Pattern:
 * This class serves as the Strategy interface in the Strategy pattern:
 * - Strategy: PlantCareStrategy (this class)
 * - ConcreteStrategy: FrequentWatering, ModerateWatering, MinimalWatering
 * - Context: PlantCareContext
 * 
 * @see PlantCareContext
 * @see FrequentWatering
 * @see ModerateWatering
 * @see MinimalWatering
 * 
 * @since Version 1.0
 */
class PlantCareStrategy {
public:
    /**
     * @brief Virtual destructor
     * @details Ensures proper cleanup of derived class objects
     * 
     * The virtual destructor is essential for proper polymorphic
     * destruction when deleting objects through base class pointers.
     * 
     * @note Default implementation is sufficient for this abstract class
     */
    virtual ~PlantCareStrategy() = default;
    
    /**
     * @brief Pure virtual method for plant care implementation
     * @details Must be implemented by all concrete strategy classes
     * 
     * This pure virtual method defines the interface that all concrete
     * plant care strategies must implement. Each strategy provides its
     * own specific care instructions and watering approach.
     * 
     * @pre Strategy object must be properly constructed
     * @post Care instructions are provided according to strategy type
     * @note Implementation varies based on concrete strategy type
     * @warning Must be implemented by derived classes
     * 
     * @par Implementation Requirements:
     * - Provide appropriate care instructions
     * - Handle output to appropriate stream
     * - Maintain consistency with strategy type
     * 
     * @see FrequentWatering::careForPlant()
     * @see ModerateWatering::careForPlant()
     * @see MinimalWatering::careForPlant()
     */
    virtual void careForPlant() = 0;
};

#endif // PLANTCARESTRATEGY_H