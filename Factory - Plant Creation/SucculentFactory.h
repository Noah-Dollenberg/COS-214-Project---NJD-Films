/**
 * @file SucculentFactory.h
 * @brief Concrete factory for creating succulent plants
 * @author NJD Films
 */

#ifndef SUCCULENTFACTORY_H
#define SUCCULENTFACTORY_H
#include "PlantFactory.h"
#include "../Plant - Abstract Base/Plant.h"

/**
 * @class Succulent
 * @brief Concrete plant class representing a succulent
 *
 * Succulents are water-retaining plants adapted to arid climates. They store
 * water in their leaves, stems, or roots, making them extremely drought-tolerant.
 * Popular for their diverse shapes, colors, and low-maintenance requirements.
 * They need infrequent watering and are very easy to propagate.
 */
class Succulent : public Plant
{
public:
    /**
     * @brief Default constructor
     *
     * Creates a succulent with default water-storing characteristics.
     */
    Succulent();

    /**
     * @brief Copy constructor
     * @param other The Succulent to copy from
     */
    Succulent(const Succulent &other);

    /**
     * @brief Destructor
     */
    ~Succulent() override;

    /**
     * @brief Create a clone of this succulent
     * @return Pointer to a new Succulent that is a copy of this one
     *
     * Implements the Prototype pattern's clone method.
     * Succulents are particularly easy to propagate.
     */
    Plant *clone() const override;

    /**
     * @brief Get the plant type
     * @return String "Succulent"
     */
    std::string getType() const override;

    /**
     * @brief Initialize succulent-specific attributes
     *
     * Sets up succulent-specific characteristics like water storage capacity,
     * minimal watering needs, and tolerance to neglect.
     */
    void initialize() override;

    /**
     * @brief Display succulent information
     *
     * Outputs details about this succulent to the console.
     */
    void display() const override;
};

/**
 * @class SucculentFactory
 * @brief Concrete factory for creating Succulent plants
 *
 * This factory implements the Factory Method pattern to create Succulent objects.
 * It creates succulents configured for low-maintenance care with minimal watering
 * and high resilience.
 */
class SucculentFactory : public PlantFactory
{
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~SucculentFactory() = default;

    /**
     * @brief Create a new Succulent plant
     * @return Pointer to a newly created Succulent object
     *
     * Implements the Factory Method to create a succulent with appropriate
     * water-retention characteristics and low-maintenance care requirements.
     */
    Plant *createPlant() override;

    /**
     * @brief Get the plant type this factory creates
     * @return String "Succulent"
     */
    std::string getPlantType() const override;
};

#endif