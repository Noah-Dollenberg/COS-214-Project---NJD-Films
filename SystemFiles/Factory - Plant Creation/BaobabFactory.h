/**
 * @file BaobabFactory.h
 * @brief Concrete factory for creating baobab trees
 * @author NJD Films
 */

#ifndef BAOBABFACTORY_H
#define BAOBABFACTORY_H
#include "PlantFactory.h"
#include "../Plant - Abstract Base/Plant.h"

/**
 * @class BaobabFactory
 * @brief Concrete factory for creating Baobab trees
 *
 * This factory implements the Factory Method pattern to create Baobab objects.
 * Baobabs are iconic African trees known as "trees of life" with massive trunks
 * that store water. They require special care with well-draining soil, full sun,
 * and careful watering to avoid root rot. As large trees, they are premium,
 * high-value specimens in the greenhouse system.
 *
 * Baobab characteristics:
 * - Very slow-growing but extremely long-lived
 * - Drought-tolerant with water-storing trunk
 * - Requires minimal but careful watering
 * - High-value ornamental specimen
 * - Needs ample space and full sunlight
 */
class BaobabFactory : public PlantFactory
{
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~BaobabFactory() = default;

    /**
     * @brief Create a new Baobab tree
     * @return Pointer to a newly created Baobab (Plant) object
     *
     * Implements the Factory Method to create a baobab tree configured
     * with water-storing characteristics, minimal watering needs, and
     * premium pricing appropriate for this iconic specimen.
     */
    Plant *createPlant() override;

    /**
     * @brief Get the plant type this factory creates
     * @return String "Baobab"
     */
    std::string getPlantType() const override;
};

#endif