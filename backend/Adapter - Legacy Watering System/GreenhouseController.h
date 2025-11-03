#ifndef GREENHOUSECONTROLLER_H
#define GREENHOUSECONTROLLER_H

#include "ModernWateringSystem.h"
#include <string>

// Forward declarations
class GreenhouseComponent;

/**
 * @brief Controller for greenhouse operations
 *
 * Uses ModernWateringSystem interface (doesn't know about legacy system)
 * This demonstrates how the adapter allows old and new systems to work together
 */
class GreenhouseController
{
private:
    ModernWateringSystem *wateringSystem;
    GreenhouseComponent *greenhouse;
    std::string currentSeason;

public:
    /**
     * @brief Constructor
     * @param system Pointer to watering system (could be adapter or modern system)
     * @param greenhouseComp Pointer to greenhouse component
     */
    GreenhouseController(ModernWateringSystem *system, GreenhouseComponent *greenhouseComp);

    /**
     * @brief Destructor
     */
    ~GreenhouseController();

    /**
     * @brief Perform daily maintenance routine
     */
    void performDailyMaintenance();

    /**
     * @brief Water all plants in the greenhouse
     */
    void waterGreenhouse();

    /**
     * @brief Change the current season
     * @param season New season
     */
    void changeSeason(const std::string &season);

    /**
     * @brief Get current season
     * @return Current season
     */
    std::string getCurrentSeason() const;

    /**
     * @brief Display greenhouse status
     */
    void displayGreenhouseStatus() const;

    /**
     * @brief Get system status
     * @return Status string
     */
    std::string getSystemStatus() const;
};

#endif // GREENHOUSECONTROLLER_H