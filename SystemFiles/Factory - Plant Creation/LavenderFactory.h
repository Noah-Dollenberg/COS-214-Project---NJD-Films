/**
 * @file LavenderFactory.h
 * @brief Concrete factory for creating lavender plants
 * @author NJD Films
 */

#ifndef LAVENDERFACTORY_H
#define LAVENDERFACTORY_H
#include "PlantFactory.h"
#include "../Plant - Abstract Base/Plant.h"

/**
 * @class Lavender
 * @brief Concrete plant class representing lavender
 *
 * Lavender is an aromatic herb known for its fragrant purple flowers and
 * medicinal properties. It requires moderate watering, good drainage, and
 * full sunlight. Popular for both ornamental and practical uses (essential oils,
 * aromatherapy, cooking). Thrives in Mediterranean-like conditions.
 */
class Lavender : public Plant
{
public:
    /**
     * @brief Default constructor
     *
     * Creates lavender with aromatic and Mediterranean characteristics.
     */
    Lavender();

    /**
     * @brief Copy constructor
     * @param other The Lavender to copy from
     */
    Lavender(const Lavender &other);

    /**
     * @brief Destructor
     */
    ~Lavender() override;

    /**
     * @brief Create a clone of this lavender
     * @return Pointer to a new Lavender that is a copy of this one
     *
     * Implements the Prototype pattern's clone method.
     */
    Plant *clone() const override;

    /**
     * @brief Get the plant type
     * @return String "Lavender"
     */
    std::string getType() const override;

    /**
     * @brief Initialize lavender-specific attributes
     *
     * Sets up lavender-specific characteristics like moderate watering,
     * full sun requirements, and aromatic properties.
     */
    void initialize() override;

    /**
     * @brief Display lavender information
     *
     * Outputs details about this lavender to the console.
     */
    void display() const override;
};

/**
 * @class LavenderFactory
 * @brief Concrete factory for creating Lavender plants
 *
 * This factory implements the Factory Method pattern to create Lavender objects.
 * It creates lavender plants configured with Mediterranean growing conditions
 * and aromatic herb characteristics.
 */
class LavenderFactory : public PlantFactory {
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~LavenderFactory() = default;

    /**
     * @brief Create a new Lavender plant
     * @return Pointer to a newly created Lavender object
     *
     * Implements the Factory Method to create lavender with appropriate
     * aromatic properties, moderate watering needs, and sun requirements.
     */
    Plant* createPlant() override;

    /**
     * @brief Get the plant type this factory creates
     * @return String "Lavender"
     */
    std::string getPlantType() const override;
};

#endif