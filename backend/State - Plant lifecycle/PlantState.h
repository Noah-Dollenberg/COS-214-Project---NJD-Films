/**
 * @file PlantState.h
 * @brief Abstract base class for the State design pattern representing plant lifecycle states
 * @author NJD Films
 */

#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include <string>

class PlantContext;

/**
 * @class PlantState
 * @brief Abstract state interface for plant lifecycle management
 *
 * This class implements the State design pattern, allowing plants to change
 * behavior based on their current lifecycle state (seedling, growing, mature, etc.).
 * Each concrete state provides specific implementations for watering, fertilizing,
 * and health monitoring.
 */
class PlantState {
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~PlantState() = default;

    /**
     * @brief Water the plant based on current state
     * @param context Pointer to the PlantContext managing this state
     *
     * Different states may require different watering approaches.
     * This method may trigger a state transition.
     */
    virtual void water(PlantContext* context) = 0;

    /**
     * @brief Fertilize the plant based on current state
     * @param context Pointer to the PlantContext managing this state
     *
     * Different states have different fertilization needs.
     * This method may trigger a state transition.
     */
    virtual void fertilize(PlantContext* context) = 0;

    /**
     * @brief Check the health of the plant in current state
     * @param context Pointer to the PlantContext managing this state
     *
     * Performs state-specific health checks and may trigger state transitions.
     */
    virtual void checkHealth(PlantContext* context) = 0;

    /**
     * @brief Get the name of the current state
     * @return String representation of the state name
     */
    virtual std::string getStateName() const = 0;
};

class SeedlingState;
class GrowingState;
class MatureState;
class FloweringState;
class DormantState;

#endif // PLANTSTATE_H