/**
 * @file RoseFactory.h
 * @brief Concrete factory for creating rose plants
 * @author NJD Films
 */

#ifndef ROSEFACTORY_H
#define ROSEFACTORY_H

#include "PlantFactory.h"
#include "../Plant - Abstract Base/Plant.h"

/**
 * @class Rose
 * @brief Concrete plant class representing a rose
 *
 * Roses are ornamental flowering plants known for their beauty and fragrance.
 * They require frequent watering, regular fertilization, and careful pruning.
 * In the greenhouse system, roses are premium products with higher prices.
 */
class Rose : public Plant
{
public:
    /**
     * @brief Default constructor
     *
     * Creates a rose with default characteristics (species, price, care needs).
     */
    Rose();

    /**
     * @brief Copy constructor
     * @param other The Rose to copy from
     */
    Rose(const Rose &other);

    /**
     * @brief Destructor
     */
    ~Rose() override;

    /**
     * @brief Create a clone of this rose
     * @return Pointer to a new Rose that is a copy of this one
     *
     * Implements the Prototype pattern's clone method.
     */
    Plant *clone() const override;

    /**
     * @brief Get the plant type
     * @return String "Rose"
     */
    std::string getType() const override;

    /**
     * @brief Initialize rose-specific attributes
     *
     * Sets up rose-specific characteristics like watering frequency,
     * fertilization needs, and pricing.
     */
    void initialize() override;

    /**
     * @brief Display rose information
     *
     * Outputs details about this rose to the console.
     */
    void display() const override;
};

/**
 * @class RoseFactory
 * @brief Concrete factory for creating Rose plants
 *
 * This factory implements the Factory Method pattern to create Rose objects.
 * It encapsulates all the knowledge needed to instantiate and configure
 * a rose plant with appropriate default values for price, care requirements, etc.
 */
class RoseFactory : public PlantFactory
{
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~RoseFactory() = default;

    /**
     * @brief Create a new Rose plant
     * @return Pointer to a newly created Rose object
     *
     * Implements the Factory Method to create a rose with proper initialization.
     * The rose is created with appropriate species name, care requirements,
     * and pricing for the greenhouse system.
     */
    Plant *createPlant() override;

    /**
     * @brief Get the plant type this factory creates
     * @return String "Rose"
     */
    std::string getPlantType() const override;
};

#endif