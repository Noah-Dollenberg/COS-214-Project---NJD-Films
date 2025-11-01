#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include <string>

// Forward declaration
class Plant;

/**
 * @brief Abstract Factory class for creating Plant objects
 *
 * This class defines the factory method interface for creating plants.
 * Concrete factories will implement createPlant() to instantiate specific plant types.
 */
class PlantFactory
{
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~PlantFactory() {}

    /**
     * @brief Factory method to create a plant
     * @return Pointer to newly created Plant object
     */
    virtual Plant *createPlant() = 0;

    /**
     * @brief Get the plant type this factory creates
     * @return String representing the plant type
     */
    virtual std::string getPlantType() const = 0;
};

#endif