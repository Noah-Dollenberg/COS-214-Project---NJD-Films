/**
 * @file SeedlingState.h
 * @brief Concrete state representing the seedling stage of plant lifecycle
 * @author NJD Films
 */

#ifndef SEEDLINGSTATE_H
#define SEEDLINGSTATE_H

#include "PlantState.h"

/**
 * @class SeedlingState
 * @brief Represents the seedling state in a plant's lifecycle
 *
 * This is the initial growth stage where plants are fragile and require
 * gentle care. Seedlings need careful watering and minimal fertilization.
 * After sufficient growth, they transition to the GrowingState.
 */
class SeedlingState : public PlantState {
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~SeedlingState() = default;

    /**
     * @brief Water the seedling gently
     * @param context Pointer to the PlantContext
     *
     * Seedlings require gentle watering to avoid drowning.
     * Proper watering contributes to transition to growing state.
     */
    void water(PlantContext* context) override;

    /**
     * @brief Apply minimal fertilizer appropriate for seedlings
     * @param context Pointer to the PlantContext
     *
     * Seedlings need very light fertilization as they are sensitive.
     */
    void fertilize(PlantContext* context) override;

    /**
     * @brief Check seedling health and growth progress
     * @param context Pointer to the PlantContext
     *
     * Monitors if the seedling is ready to transition to growing state.
     */
    void checkHealth(PlantContext* context) override;

    /**
     * @brief Get the state name
     * @return String "Seedling"
     */
    std::string getStateName() const override { return "Seedling"; }
};

#endif // SEEDLINGSTATE_H