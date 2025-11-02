/**
 * @file Lavendar.h
 * @brief Header file for the Lavender concrete plant class
 * @author NJD Films
 * @date 2024
 */

#ifndef LAVENDER_H
#define LAVENDER_H
#include "Plant.h"

/**
 * @class Lavender
 * @brief Concrete plant class representing lavender
 * @ingroup Plants
 *
 * Lavender is a concrete implementation of Plant representing lavender herbs.
 * Lavender is a fragrant herb requiring moderate watering, good sunlight,
 * and sandy soil. Popular for herb gardens and aromatherapy arrangements.
 *
 * @par Plant Characteristics:
 * - Base Price: R85.00
 * - Days to Maturity: 40 days
 * - Watering: Every 5 days (moderate)
 * - Sunlight: 7 hours/day (good sun)
 * - Fertilizing: Every 30 days
 * - Soil Type: Sandy
 *
 * @see Plant
 */
class Lavender : public Plant {
public:
    /**
     * @brief Default constructor
     * @post Lavender initialized with species "Lavender", 40 days to maturity,
     *       R85 base price, 5-day watering, 7hr sunlight, sandy soil
     */
    Lavender() : Plant("Lavender", 40) {
        setBasePrice(85.0);
        setWateringFrequency(5);  // Moderate watering
        setSunlightRequirement(7); // Needs good sun
        setFertilizingFrequency(30);
        setSoilType("sandy");
    }

    /**
     * @brief Clone method for Prototype pattern
     * @return Pointer to cloned Lavender object
     */
    Plant* clone() const override {
        return new Lavender(*this);
    }

    /**
     * @brief Get plant type
     * @return "Lavender"
     */
    std::string getType() const override {
        return "Lavender";
    }

    /** @brief Virtual destructor */
    virtual ~Lavender() = default;
};

#endif // LAVENDER_H