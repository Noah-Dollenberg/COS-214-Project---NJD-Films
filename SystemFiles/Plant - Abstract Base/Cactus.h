/**
 * @file Cactus.h
 * @brief Header file for the Cactus concrete plant class
 * @author NJD Films
 * @date 2024
 */

#ifndef CACTUS_H
#define CACTUS_H
#include "Plant.h"

/**
 * @class Cactus
 * @brief Concrete plant class representing a cactus
 * @ingroup Plants
 *
 * Cactus is a concrete implementation of Plant representing desert cacti.
 * Cacti are low-maintenance plants requiring infrequent watering, high
 * sunlight, and sandy soil. They are ideal for desert-themed arrangements.
 *
 * @par Plant Characteristics:
 * - Base Price: R75.00
 * - Days to Maturity: 30 days
 * - Watering: Every 14 days (very infrequent)
 * - Sunlight: 8 hours/day (high)
 * - Fertilizing: Every 60 days (rare)
 * - Soil Type: Sandy
 *
 * @see Plant
 */
class Cactus : public Plant {
public:
    /**
     * @brief Default constructor
     * @post Cactus initialized with species "Cactus", 30 days to maturity,
     *       R75 base price, 14-day watering, 8hr sunlight, sandy soil
     */
    Cactus() : Plant("Cactus", 30) {
        setBasePrice(75.0);
        setWateringFrequency(14);  // Needs very infrequent water
        setSunlightRequirement(8);  // High sun requirement
        setFertilizingFrequency(60); // Rarely needs fertilizer
        setSoilType("sandy");
    }

    /**
     * @brief Clone method for Prototype pattern
     * @return Pointer to cloned Cactus object
     */
    Plant* clone() const override {
        return new Cactus(*this);
    }

    /**
     * @brief Get plant type
     * @return "Cactus"
     */
    std::string getType() const override {
        return "Cactus";
    }

    /** @brief Virtual destructor */
    virtual ~Cactus() = default;
};

#endif // CACTUS_H