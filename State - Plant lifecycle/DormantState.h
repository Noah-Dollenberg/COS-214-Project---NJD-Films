/**
 * @file DormantState.h
 * @brief Concrete state representing the dormant/resting stage of plant lifecycle
 * @author NJD Films
 */

#ifndef DORMANTSTATE_H
#define DORMANTSTATE_H

#include "PlantState.h"

/**
 * @class DormantState
 * @brief Represents the dormant state in a plant's lifecycle
 *
 * During dormancy, plants enter a rest period with minimal metabolic activity.
 * This is common in perennials during winter or after flowering. Plants require
 * minimal care during this state - reduced watering and no fertilization.
 * With proper rest, plants can cycle back to active growth states.
 */
class DormantState : public PlantState {
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~DormantState() = default;

    /**
     * @brief Water the dormant plant minimally
     * @param context Pointer to the PlantContext
     *
     * Dormant plants need very little water to prevent rot.
     * Minimal watering maintains viability during rest period.
     */
    void water(PlantContext* context) override;

    /**
     * @brief Skip fertilization during dormancy
     * @param context Pointer to the PlantContext
     *
     * Dormant plants should not be fertilized as they cannot process nutrients.
     */
    void fertilize(PlantContext* context) override;

    /**
     * @brief Check if plant is ready to exit dormancy
     * @param context Pointer to the PlantContext
     *
     * Monitors conditions to determine if plant should return to active growth.
     */
    void checkHealth(PlantContext* context) override;

    /**
     * @brief Get the state name
     * @return String "Dormant"
     */
    std::string getStateName() const override { return "Dormant"; }
};

#endif // DORMANTSTATE_H