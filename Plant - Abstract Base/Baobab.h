/**
 * @file Baobab.h
 * @brief Header file for the Baobab concrete plant class
 * @author NJD Films
 * @date 2024
 */

#ifndef BAOBAB_H
#define BAOBAB_H
#include "Plant.h"

/**
 * @class Baobab
 * @brief Concrete plant class representing a baobab tree
 * @ingroup Plants
 *
 * Baobab is a concrete implementation of Plant representing baobab trees.
 * Baobabs are premium trees requiring very high sunlight and moderate watering.
 * They start taller than other plants and take longer to reach maturity.
 *
 * @par Plant Characteristics:
 * - Base Price: R250.00 (premium)
 * - Days to Maturity: 90 days (slow)
 * - Starting Height: 15.0 cm
 * - Watering: Every 7 days (moderate)
 * - Sunlight: 10 hours/day (very high)
 * - Fertilizing: Every 30 days
 * - Soil Type: Loamy
 *
 * @see Plant
 */
class Baobab : public Plant {
public:
    /**
     * @brief Default constructor
     * @post Baobab initialized with species "Baobab", 90 days to maturity,
     *       R250 base price, 7-day watering, 10hr sunlight, 15cm height, loamy soil
     */
    Baobab() : Plant("Baobab", 90) {
        setBasePrice(250.0);
        setWateringFrequency(7);  // Moderate watering
        setSunlightRequirement(10); // Very high sun requirement
        setFertilizingFrequency(30);
        setSoilType("loamy");
        setHeight(15.0); // Starts taller as a tree
    }

    /**
     * @brief Clone method for Prototype pattern
     * @return Pointer to cloned Baobab object
     */
    Plant* clone() const override {
        return new Baobab(*this);
    }

    /**
     * @brief Get plant type
     * @return "Baobab Tree"
     */
    std::string getType() const override {
        return "Baobab Tree";
    }

    /** @brief Virtual destructor */
    virtual ~Baobab() = default;
};

#endif // BAOBAB_H