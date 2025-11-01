/**
 * @file GrowingState.h
 * @brief Concrete state representing the active growth stage of plant lifecycle
 * @author NJD Films
 */

#ifndef GROWINGSTATE_H
#define GROWINGSTATE_H

#include "PlantState.h"

/**
 * @class GrowingState
 * @brief Represents the active growing state in a plant's lifecycle
 *
 * During the growing state, plants are actively developing and expanding.
 * They require regular watering and moderate fertilization to support
 * rapid growth. After reaching sufficient size, they transition to MatureState.
 */
class GrowingState : public PlantState {
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~GrowingState() = default;

    /**
     * @brief Water the growing plant regularly
     * @param context Pointer to the PlantContext
     *
     * Growing plants need consistent watering to support active development.
     * Regular watering helps transition to mature state.
     */
    void water(PlantContext* context) override;

    /**
     * @brief Apply moderate fertilizer for active growth
     * @param context Pointer to the PlantContext
     *
     * Growing plants benefit from regular fertilization to support development.
     */
    void fertilize(PlantContext* context) override;

    /**
     * @brief Check plant health and growth progress
     * @param context Pointer to the PlantContext
     *
     * Monitors if the plant has grown sufficiently to transition to mature state.
     */
    void checkHealth(PlantContext* context) override;

    /**
     * @brief Get the state name
     * @return String "Growing"
     */
    std::string getStateName() const override { return "Growing"; }
};

#endif // GROWINGSTATE_H