#include "LegacyIrrigationSystem.h"
#include <iostream>
#include <iomanip>

LegacyIrrigationSystem::LegacyIrrigationSystem()
    : waterPressure(5), systemMode("manual"), systemActive(true)
{
    std::cout << "[LEGACY SYSTEM] Irrigation System v1.2 initialized" << std::endl;
    std::cout << "[LEGACY SYSTEM] Default pressure: 5, Mode: manual" << std::endl;
}

LegacyIrrigationSystem::~LegacyIrrigationSystem()
{
    std::cout << "[LEGACY SYSTEM] Shutting down irrigation system" << std::endl;
}

void LegacyIrrigationSystem::activateZone(int zoneId, int durationMinutes)
{
    if (!systemActive)
    {
        std::cout << "[LEGACY SYSTEM] ERROR: System is not active!" << std::endl;
        return;
    }

    std::cout << "[LEGACY SYSTEM] >> ACTIVATING Zone " << zoneId << std::endl;
    std::cout << "[LEGACY SYSTEM]    Duration: " << durationMinutes << " minutes" << std::endl;
    std::cout << "[LEGACY SYSTEM]    Pressure: " << waterPressure << "/10" << std::endl;
    std::cout << "[LEGACY SYSTEM]    Mode: " << systemMode << std::endl;
}

void LegacyIrrigationSystem::deactivateZone(int zoneId)
{
    std::cout << "[LEGACY SYSTEM] >> DEACTIVATING Zone " << zoneId << std::endl;
}

void LegacyIrrigationSystem::setPressure(int pressure)
{
    if (pressure < 1 || pressure > 10)
    {
        std::cout << "[LEGACY SYSTEM] ERROR: Pressure must be between 1-10" << std::endl;
        return;
    }

    waterPressure = pressure;
    std::cout << "[LEGACY SYSTEM] Pressure adjusted to " << pressure << "/10" << std::endl;
}

int LegacyIrrigationSystem::getPressure() const
{
    return waterPressure;
}

bool LegacyIrrigationSystem::checkMoisture(int zoneId, int daysSinceLastWater)
{
    // Simple moisture logic based on days since last watering
    bool needsWater = daysSinceLastWater > 5;

    std::cout << "[LEGACY SYSTEM] Moisture check - Zone " << zoneId << ": ";
    if (needsWater)
    {
        std::cout << "DRY (last watered " << daysSinceLastWater << " days ago)" << std::endl;
    }
    else
    {
        std::cout << "OK (last watered " << daysSinceLastWater << " days ago)" << std::endl;
    }

    return needsWater;
}

void LegacyIrrigationSystem::setMode(const std::string &mode)
{
    if (mode != "manual" && mode != "timer" && mode != "sensor")
    {
        std::cout << "[LEGACY SYSTEM] ERROR: Invalid mode. Use 'manual', 'timer', or 'sensor'" << std::endl;
        return;
    }

    systemMode = mode;
    std::cout << "[LEGACY SYSTEM] Operating mode set to: " << mode << std::endl;
}

std::string LegacyIrrigationSystem::getMode() const
{
    return systemMode;
}

std::string LegacyIrrigationSystem::getStatus() const
{
    std::string status = "[LEGACY SYSTEM STATUS]\n";
    status += "  Active: " + std::string(systemActive ? "YES" : "NO") + "\n";
    status += "  Mode: " + systemMode + "\n";
    status += "  Pressure: " + std::to_string(waterPressure) + "/10\n";
    status += "  System Version: 1.2";
    return status;
}

bool LegacyIrrigationSystem::runDiagnostic()
{
    std::cout << "[LEGACY SYSTEM] Running diagnostic..." << std::endl;
    std::cout << "[LEGACY SYSTEM] Checking valves... OK" << std::endl;
    std::cout << "[LEGACY SYSTEM] Checking pressure... OK" << std::endl;
    std::cout << "[LEGACY SYSTEM] Checking zones... OK" << std::endl;
    std::cout << "[LEGACY SYSTEM] Diagnostic complete - All systems operational" << std::endl;
    return true;
}