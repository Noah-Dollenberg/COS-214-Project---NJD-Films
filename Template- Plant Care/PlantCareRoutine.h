/**
 * @file PlantCareRoutine.h
 * @brief Header file for the PlantCareRoutine abstract base class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 */

#ifndef PLANTCAREROUTINE_H
#define PLANTCAREROUTINE_H

/**
 * @class PlantCareRoutine
 * @brief Abstract base class implementing the Template Method pattern for plant care
 * @ingroup Template
 * 
 * This abstract class defines the skeleton of a plant care algorithm using the
 * Template Method design pattern. It provides a fixed sequence of care steps
 * while allowing subclasses to customize specific operations for different
 * plant types.
 * 
 * The template method defines the overall care routine structure:
 * 1. Check soil moisture
 * 2. Water the plant
 * 3. Apply fertilizer
 * 4. Prune if necessary
 * 5. Perform additional care (optional)
 * 
 * @par Design Pattern:
 * This class serves as the AbstractClass in the Template Method pattern:
 * - AbstractClass: PlantCareRoutine (this class)
 * - ConcreteClass: RoseCare, SucculentCare, TreeCare
 * - Template Method: careForPlant()
 * - Primitive Operations: checkSoilMoisture(), water(), fertilize(), prune()
 * - Hook Operation: additionalCare()
 * 
 * @see RoseCare
 * @see SucculentCare
 * @see TreeCare
 * 
 * @since Version 1.0
 */
class PlantCareRoutine {
public:
    /**
     * @brief Virtual destructor
     * @details Ensures proper cleanup of derived class objects
     * 
     * The virtual destructor is essential for proper polymorphic
     * destruction when deleting objects through base class pointers.
     */
    virtual ~PlantCareRoutine() = default;
    
    /**
     * @brief Template method defining the plant care algorithm
     * @details Executes the complete care routine in a fixed sequence
     * 
     * This is the template method that defines the skeleton of the
     * plant care algorithm. It calls the primitive operations in a
     * specific order to ensure consistent care across all plant types.
     * 
     * @par Algorithm Steps:
     * 1. Start care routine (logging)
     * 2. Check soil moisture level
     * 3. Water the plant based on moisture
     * 4. Apply appropriate fertilizer
     * 5. Prune dead or overgrown parts
     * 6. Perform additional plant-specific care
     * 7. Complete care routine (logging)
     * 
     * @pre Plant care routine object must be properly constructed
     * @post Complete care routine is executed for the plant
     * @note This method should not be overridden by subclasses
     * @final This method defines the invariant algorithm structure
     */
    void careForPlant();
    
protected:
    /**
     * @brief Pure virtual method to check soil moisture
     * @details Must be implemented by concrete plant care classes
     * 
     * Each plant type requires different moisture level checking
     * approaches. This method allows subclasses to implement
     * plant-specific moisture assessment techniques.
     * 
     * @pre Plant and soil conditions are accessible
     * @post Soil moisture level is determined
     * @note Implementation varies based on plant type requirements
     * @warning Must be implemented by all derived classes
     */
    virtual void checkSoilMoisture() = 0;
    
    /**
     * @brief Pure virtual method to water the plant
     * @details Must be implemented by concrete plant care classes
     * 
     * Different plants require different watering techniques and
     * amounts. This method allows customization of watering
     * approaches for specific plant types.
     * 
     * @pre Soil moisture has been checked
     * @post Plant receives appropriate amount of water
     * @note Watering amount and frequency vary by plant type
     * @warning Must be implemented by all derived classes
     */
    virtual void water() = 0;
    
    /**
     * @brief Pure virtual method to fertilize the plant
     * @details Must be implemented by concrete plant care classes
     * 
     * Each plant type has specific nutritional requirements that
     * determine the type and amount of fertilizer needed. This
     * method enables plant-specific fertilization strategies.
     * 
     * @pre Plant has been watered
     * @post Appropriate fertilizer is applied
     * @note Fertilizer type and schedule vary by plant species
     * @warning Must be implemented by all derived classes
     */
    virtual void fertilize() = 0;
    
    /**
     * @brief Pure virtual method to prune the plant
     * @details Must be implemented by concrete plant care classes
     * 
     * Pruning requirements differ significantly between plant types.
     * This method allows implementation of species-specific pruning
     * techniques and schedules.
     * 
     * @pre Plant has been fertilized
     * @post Dead or overgrown parts are removed
     * @note Pruning techniques vary greatly by plant type
     * @warning Must be implemented by all derived classes
     */
    virtual void prune() = 0;
    
    /**
     * @brief Hook method for additional plant-specific care
     * @details Optional method that can be overridden by subclasses
     * 
     * This hook method provides an extension point for plant types
     * that require additional care steps beyond the standard routine.
     * The default implementation does nothing.
     * 
     * @pre Standard care routine steps have been completed
     * @post Additional care is performed if overridden
     * @note Default implementation is empty (no operation)
     * @hook This is a hook method - override is optional
     */
    virtual void additionalCare() {}
};

#endif
