#ifndef WATERINGADAPTER_H
#define WATERINGADAPTER_H

#include "ModernWateringSystem.h"
#include "LegacyIrrigationSystem.h"
#include <map>

// Forward declaration
class GreenhouseComponent;

/**
 * @brief Adapter to make LegacyIrrigationSystem work with ModernWateringSystem interface
 *
 * This adapter translates modern watering system calls into legacy system commands,
 * allowing the GreenhouseController to use the old irrigation system seamlessly
 */
class WateringAdapter : public ModernWateringSystem
{
private:
    LegacyIrrigationSystem *legacySystem;
    int zoneCounter;
    double seasonalMultiplier;
    std::string currentSeason;

public:
    /**
     * @brief Constructor
     * @param legacy Pointer to legacy irrigation system to adapt
     */
    WateringAdapter(LegacyIrrigationSystem *legacy);

    /**
     * @brief Destructor
     */
    ~WateringAdapter() override;

    /**
     * @brief Water greenhouse using legacy system (adapted method)
     * @param greenhouse Greenhouse component to water
     */
    void waterGreenhouse(GreenhouseComponent *greenhouse) override;

    /**
     * @brief Adjust watering for current season
     * @param season Season name ("spring", "summer", "fall", "winter")
     */
    void adjustForSeason(const std::string &season) override;

    /**
     * @brief Get system status
     * @return Status message
     */
    std::string getSystemStatus() override;

    /**
     * @brief Get the wrapped legacy system (for testing)
     * @return Pointer to legacy system
     */
    LegacyIrrigationSystem *getLegacySystem() const;
};

#endif