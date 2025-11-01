/**
 * @file MatureState.h
 * @brief Concrete state representing the mature stage of plant lifecycle
 * @author NJD Films
 */

#ifndef MATURESTATE_H
#define MATURESTATE_H

#include "PlantState.h"

/**
 * @class MatureState
 * @brief Represents the mature state in a plant's lifecycle
 *
 * In the mature state, plants have reached their full size and are stable.
 * They require maintenance-level care with moderate watering and occasional
 * fertilization. Under proper conditions, they may transition to FloweringState.
 */
class MatureState : public PlantState {
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~MatureState() = default;

    /**
     * @brief Water the mature plant with maintenance amounts
     * @param context Pointer to the PlantContext
     *
     * Mature plants need consistent but not excessive watering.
     * Proper care may trigger flowering in appropriate species.
     */
    void water(PlantContext* context) override;

    /**
     * @brief Apply maintenance fertilizer
     * @param context Pointer to the PlantContext
     *
     * Mature plants need less frequent fertilization to maintain health.
     */
    void fertilize(PlantContext* context) override;

    /**
     * @brief Check plant health and readiness for flowering
     * @param context Pointer to the PlantContext
     *
     * Monitors plant condition and determines if ready to flower.
     */
    void checkHealth(PlantContext* context) override;

    /**
     * @brief Get the state name
     * @return String "Mature"
     */
    std::string getStateName() const override { return "Mature"; }
};

#endif // MATURESTATE_H