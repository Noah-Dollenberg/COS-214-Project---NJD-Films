/**
 * @file FloweringState.h
 * @brief Concrete state representing the flowering stage of plant lifecycle
 * @author NJD Films
 */

#ifndef FLOWERINGSTATE_H
#define FLOWERINGSTATE_H

#include "PlantState.h"

/**
 * @class FloweringState
 * @brief Represents the flowering state in a plant's lifecycle
 *
 * The flowering state is when plants produce blooms. This is often the peak
 * of the plant's visual appeal and requires careful maintenance to prolong
 * the flowering period. After flowering completes, plants may enter DormantState
 * or cycle back depending on the species.
 */
class FloweringState : public PlantState {
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~FloweringState() = default;

    /**
     * @brief Water the flowering plant carefully
     * @param context Pointer to the PlantContext
     *
     * Flowering plants need consistent watering to maintain blooms.
     * Proper watering extends the flowering period.
     */
    void water(PlantContext* context) override;

    /**
     * @brief Apply bloom-supporting fertilizer
     * @param context Pointer to the PlantContext
     *
     * Flowering plants benefit from specialized fertilization to support blooms.
     */
    void fertilize(PlantContext* context) override;

    /**
     * @brief Check plant health and bloom condition
     * @param context Pointer to the PlantContext
     *
     * Monitors bloom health and determines when flowering period ends.
     */
    void checkHealth(PlantContext* context) override;

    /**
     * @brief Get the state name
     * @return String "Flowering"
     */
    std::string getStateName() const override { return "Flowering"; }
};

#endif // FLOWERINGSTATE_H