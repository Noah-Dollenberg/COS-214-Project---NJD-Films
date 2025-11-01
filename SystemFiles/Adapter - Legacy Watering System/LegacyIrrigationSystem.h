#ifndef LEGACYIRRIGATIONSYSTEM_H
#define LEGACYIRRIGATIONSYSTEM_H

#include <string>

/**
 * @brief Legacy irrigation system with incompatible interface (Adaptee)
 *
 * This represents an old watering system that uses different method names
 * and parameters than the modern system expects
 */
class LegacyIrrigationSystem
{
private:
    int waterPressure;
    std::string systemMode;
    bool systemActive;

public:
    /**
     * @brief Constructor
     */
    LegacyIrrigationSystem();

    /**
     * @brief Destructor
     */
    ~LegacyIrrigationSystem();

    /**
     * @brief Activate watering for a specific zone
     * @param zoneId Zone identifier (1-100)
     * @param durationMinutes How long to water (in minutes)
     */
    void activateZone(int zoneId, int durationMinutes);

    /**
     * @brief Deactivate a zone
     * @param zoneId Zone to deactivate
     */
    void deactivateZone(int zoneId);

    /**
     * @brief Set water pressure level
     * @param pressure Pressure level (1-10)
     */
    void setPressure(int pressure);

    /**
     * @brief Get current water pressure
     * @return Current pressure level
     */
    int getPressure() const;

    /**
     * @brief Check if zone needs watering (legacy moisture check)
     * @param zoneId Zone to check
     * @param daysSinceLastWater Days since last watered
     * @return true if zone needs water
     */
    bool checkMoisture(int zoneId, int daysSinceLastWater);

    /**
     * @brief Set system operating mode
     * @param mode "manual", "timer", or "sensor"
     */
    void setMode(const std::string &mode);

    /**
     * @brief Get current operating mode
     * @return Current mode
     */
    std::string getMode() const;

    /**
     * @brief Get system status (legacy format)
     * @return Status string in legacy format
     */
    std::string getStatus() const;

    /**
     * @brief Perform system diagnostic
     * @return true if system is functioning
     */
    bool runDiagnostic();
};

#endif