/**
 * @file PlantContext.h
 * @brief Context class for the State design pattern managing plant lifecycle states
 * @author NJD Films
 */

#ifndef PLANTCONTEXT_H
#define PLANTCONTEXT_H
#include <vector>
#include "PlantState.h"
#include "../Plant - Abstract Base/Plant.h"

/**
 * @class PlantContext
 * @brief Context class that maintains the current state and delegates operations to it
 *
 * This class is part of the State design pattern implementation. It holds a reference
 * to the current PlantState object and delegates state-specific behavior to it.
 * The context allows for dynamic state transitions during the plant's lifecycle.
 */
class PlantContext {
private:
    PlantState* currentState;  ///< Pointer to the current state
    Plant* plant;              ///< Pointer to the plant being managed
    std::vector<Plant*> plants; ///< Collection of plants (for batch operations)

public:
    /**
     * @brief Constructor that initializes the context with a plant
     * @param p Pointer to the plant to be managed
     */
    PlantContext(Plant* p) : currentState(nullptr), plant(p) {}

    /**
     * @brief Destructor that cleans up the current state
     */
    virtual ~PlantContext() { delete currentState; }

    /**
     * @brief Set a new state (transitions to a new lifecycle state)
     * @param state Pointer to the new PlantState to transition to
     *
     * Deletes the current state and replaces it with the new one.
     */
    void setState(PlantState* state) { delete currentState; currentState = state; }

    /**
     * @brief Get the current state
     * @return Pointer to the current PlantState
     */
    PlantState* getCurrentState() const { return currentState; }

    /**
     * @brief Delegate watering operation to the current state
     *
     * Calls the water() method on the current state if one exists.
     */
    void water() { if (currentState) currentState->water(this); }

    /**
     * @brief Delegate fertilizing operation to the current state
     *
     * Calls the fertilize() method on the current state if one exists.
     */
    void fertilize() { if (currentState) currentState->fertilize(this); }

    /**
     * @brief Delegate health check operation to the current state
     *
     * Calls the checkHealth() method on the current state if one exists.
     */
    void checkHealth() { if (currentState) currentState->checkHealth(this); }

    /**
     * @brief Get the plant being managed
     * @return Pointer to the Plant object
     */
    Plant* getPlant() const { return plant; }
};

#endif // PLANTCONTEXT_H