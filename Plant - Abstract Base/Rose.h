/**
 * @file Rose.h
 * @brief Header file for the Rose concrete plant class
 * @author NJD Films
 * @date 2024
 */

#ifndef ROSE_H
#define ROSE_H
#include "Plant.h"

/**
 * @class Rose
 * @brief Concrete plant class representing a rose
 * @ingroup Plants
 *
 * Rose is a concrete implementation of Plant representing rose plants.
 * Roses are premium flowering plants requiring frequent watering and
 * loamy soil. They are popular for gift arrangements.
 *
 * @par Plant Characteristics:
 * - Base Price: R150.00
 * - Days to Maturity: 45 days
 * - Watering: Every 3 days (frequent)
 * - Soil Type: Loamy
 *
 * @see Plant
 */
class Rose : public Plant {
public:
    /**
     * @brief Default constructor
     * @post Rose initialized with species "Rose", 45 days to maturity,
     *       R150 base price, 3-day watering frequency, loamy soil
     */
    Rose() : Plant("Rose", 45) {
        setBasePrice(150.0);
        setWateringFrequency(3);  // Needs frequent water
        setSoilType("loamy");
    }

    /**
     * @brief Clone method for Prototype pattern
     * @return Pointer to cloned Rose object
     */
    Plant* clone() const override {
        return new Rose(*this);
    }

    /**
     * @brief Get plant type
     * @return "Rose"
     */
    std::string getType() const override {
        return "Rose";
    }
};
#endif // ROSE_H