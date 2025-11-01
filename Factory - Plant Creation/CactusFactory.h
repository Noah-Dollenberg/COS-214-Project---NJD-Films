/**
 * @file CactusFactory.h
 * @brief Concrete factory for creating cactus plants
 * @author NJD Films
 */

#ifndef CACTUSFACTORY_H
#define CACTUSFACTORY_H
#include "PlantFactory.h"
#include "../Plant - Abstract Base/Plant.h"

/**
 * @class Cactus
 * @brief Concrete plant class representing a cactus
 *
 * Cacti are desert plants known for their drought tolerance and unique appearance.
 * They require minimal watering (only when soil is completely dry), well-draining soil,
 * and lots of sunlight. Cacti are low-maintenance plants ideal for beginners.
 */
class Cactus : public Plant
{
public:
    /**
     * @brief Default constructor
     *
     * Creates a cactus with default characteristics optimized for desert conditions.
     */
    Cactus();

    /**
     * @brief Copy constructor
     * @param other The Cactus to copy from
     */
    Cactus(const Cactus &other);

    /**
     * @brief Destructor
     */
    ~Cactus() override;

    /**
     * @brief Create a clone of this cactus
     * @return Pointer to a new Cactus that is a copy of this one
     *
     * Implements the Prototype pattern's clone method.
     */
    Plant *clone() const override;

    /**
     * @brief Get the plant type
     * @return String "Cactus"
     */
    std::string getType() const override;

    /**
     * @brief Initialize cactus-specific attributes
     *
     * Sets up cactus-specific characteristics like minimal watering needs,
     * high sunlight requirements, and drought tolerance.
     */
    void initialize() override;

    /**
     * @brief Display cactus information
     *
     * Outputs details about this cactus to the console.
     */
    void display() const override;
};

/**
 * @class CactusFactory
 * @brief Concrete factory for creating Cactus plants
 *
 * This factory implements the Factory Method pattern to create Cactus objects.
 * It encapsulates the creation logic for cacti with minimal watering requirements
 * and desert-adapted characteristics.
 */
class CactusFactory : public PlantFactory {
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~CactusFactory() = default;

    /**
     * @brief Create a new Cactus plant
     * @return Pointer to a newly created Cactus object
     *
     * Implements the Factory Method to create a cactus configured for
     * desert conditions with minimal water and high sunlight needs.
     */
    Plant* createPlant() override;

    /**
     * @brief Get the plant type this factory creates
     * @return String "Cactus"
     */
    std::string getPlantType() const override;
};

#endif
