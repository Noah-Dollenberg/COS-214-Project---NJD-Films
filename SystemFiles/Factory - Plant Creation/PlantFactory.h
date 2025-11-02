/**
 * @file PlantFactory.h
 * @brief Abstract base class for the Factory Method design pattern for plant creation
 * @author NJD Films
 */

#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include <string>

// Forward declaration
class Plant;

/**
 * @class PlantFactory
 * @brief Abstract factory interface for creating Plant objects
 *
 * This class implements the Factory Method design pattern, providing an interface
 * for creating plants without specifying their exact concrete classes. Each concrete
 * factory (RoseFactory, CactusFactory, etc.) knows how to create a specific type
 * of plant with the appropriate characteristics.
 *
 * Benefits of this pattern:
 * - Decouples plant creation from plant usage
 * - Makes it easy to add new plant types without modifying existing code
 * - Encapsulates plant-specific initialization logic in the factories
 * - Promotes the Open/Closed Principle (open for extension, closed for modification)
 *
 * @see RoseFactory
 * @see CactusFactory
 * @see SucculentFactory
 * @see LavenderFactory
 * @see BaobabFactory
 */
class PlantFactory
{
public:
    /**
     * @brief Virtual destructor
     *
     * Ensures proper cleanup of derived factory classes.
     */
    virtual ~PlantFactory() {}

    /**
     * @brief Factory method to create a plant (pure virtual)
     * @return Pointer to newly created Plant object
     *
     * This is the core Factory Method that concrete factories must implement.
     * Each factory creates a specific plant type with appropriate default values
     * for species, care requirements, price, etc.
     */
    virtual Plant *createPlant() = 0;

    /**
     * @brief Get the plant type this factory creates
     * @return String representing the plant type (e.g., "Rose", "Cactus")
     *
     * Allows clients to query what type of plant a factory produces
     * without actually creating one.
     */
    virtual std::string getPlantType() const = 0;
};

#endif