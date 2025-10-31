/**
 * @file Succulent.h
 * @brief Header file for the Succulent concrete plant class
 * @author NJD Films
 * @date 2024
 */

#ifndef SUCCULENT_H
#define SUCCULENT_H
#include "Plant.h"

/**
 * @class Succulent
 * @brief Concrete plant class representing a succulent
 * @ingroup Plants
 *
 * Succulent is a concrete implementation of Plant representing succulent plants.
 * Succulents are affordable, low-maintenance plants requiring infrequent watering
 * and sandy soil. They mature quickly and are popular for decorative arrangements.
 *
 * @par Plant Characteristics:
 * - Base Price: R50.00
 * - Days to Maturity: 25 days
 * - Watering: Every 10 days (infrequent)
 * - Sunlight: 6 hours/day (moderate)
 * - Fertilizing: Every 45 days
 * - Soil Type: Sandy
 *
 * @see Plant
 */
class Succulent : public Plant {
public:
    /**
     * @brief Default constructor
     * @post Succulent initialized with species "Succulent", 25 days to maturity,
     *       R50 base price, 10-day watering, 6hr sunlight, sandy soil
     */
    Succulent() : Plant("Succulent", 25) {
        setBasePrice(50.0);
        setWateringFrequency(10);  // Infrequent watering
        setSunlightRequirement(6);  // Moderate sun
        setFertilizingFrequency(45);
        setSoilType("sandy");
    }

    /**
     * @brief Clone method for Prototype pattern
     * @return Pointer to cloned Succulent object
     */
    Plant* clone() const override {
        return new Succulent(*this);
    }

    /**
     * @brief Get plant type
     * @return "Succulent"
     */
    std::string getType() const override {
        return "Succulent";
    }

    /** @brief Virtual destructor */
    virtual ~Succulent() = default;
};

#endif // SUCCULENT_H