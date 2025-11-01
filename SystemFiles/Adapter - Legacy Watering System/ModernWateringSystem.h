#ifndef MODERNWATERINGSYSTEM_H
#define MODERNWATERINGSYSTEM_H

#include <string>

// Forward declaration - no direct Plant dependency
class GreenhouseComponent;

/**
 * @brief Modern watering system interface (Target)
 *
 * This is the interface that GreenhouseController expects to use
 */
class ModernWateringSystem
{
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~ModernWateringSystem() {}

    /**
     * @brief Water greenhouse components automatically
     * @param greenhouse Pointer to greenhouse component to water
     */
    virtual void waterGreenhouse(GreenhouseComponent *greenhouse) = 0;

    /**
     * @brief Adjust watering based on season
     * @param season Current season
     */
    virtual void adjustForSeason(const std::string &season) = 0;

    /**
     * @brief Check system status
     * @return Status message
     */
    virtual std::string getSystemStatus() = 0;
};

#endif