#include "WateringAdapter.h"
#include "../Composite - The Store layout/GreenhouseComponent.h"
#include <iostream>
#include <sstream>
#include <iomanip>

WateringAdapter::WateringAdapter(LegacyIrrigationSystem *legacy)
    : legacySystem(legacy), zoneCounter(1), seasonalMultiplier(1.0), currentSeason("spring")
{
    std::cout << "\n=== ADAPTER INITIALIZED ===" << std::endl;
    std::cout << "WateringAdapter: Wrapping legacy irrigation system" << std::endl;
    std::cout << "WateringAdapter: Ready to translate modern commands to legacy format" << std::endl;
    legacySystem->setMode("manual");
}

WateringAdapter::~WateringAdapter()
{
    std::cout << "WateringAdapter: Shutting down adapter" << std::endl;
}

void WateringAdapter::waterGreenhouse(GreenhouseComponent *greenhouse)
{
    std::cout << "\n╔════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║     ADAPTER: AUTO-WATERING CYCLE STARTED      ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════╝" << std::endl;
    std::cout << "ADAPTER: Translating modern watering requests..." << std::endl;
    std::cout << "ADAPTER: Current season: " << currentSeason << std::endl;
    std::cout << "ADAPTER: Seasonal multiplier: " << seasonalMultiplier << "x" << std::endl;

    if (greenhouse == nullptr)
    {
        std::cout << "ADAPTER: ERROR - No greenhouse provided" << std::endl;
        return;
    }

    // The greenhouse component will handle its own watering through its structure
    // The adapter just activates zones based on the greenhouse's needs

    // Calculate base duration based on season
    int baseDuration = static_cast<int>(10 * seasonalMultiplier);

    std::cout << "\nADAPTER: Activating irrigation zones..." << std::endl;
    std::cout << "ADAPTER: Base duration: " << baseDuration << " minutes" << std::endl;

    // Activate zones - the greenhouse component decides what needs watering
    for (int zone = 1; zone <= zoneCounter; zone++)
    {
        legacySystem->activateZone(zone, baseDuration);
    }

    std::cout << "\n╔════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║       ADAPTER: WATERING CYCLE COMPLETE        ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════╝" << std::endl;
}

void WateringAdapter::adjustForSeason(const std::string &season)
{
    std::cout << "\n=== ADAPTER: SEASONAL ADJUSTMENT ===" << std::endl;
    std::cout << "ADAPTER: Adjusting from '" << currentSeason
              << "' to '" << season << "'" << std::endl;

    currentSeason = season;

    // Adjust multiplier and pressure based on season
    if (season == "summer")
    {
        seasonalMultiplier = 1.5;
        legacySystem->setPressure(7);
        std::cout << "ADAPTER: Summer mode - Increased watering (1.5x)" << std::endl;
    }
    else if (season == "winter")
    {
        seasonalMultiplier = 0.6;
        legacySystem->setPressure(4);
        std::cout << "ADAPTER: Winter mode - Reduced watering (0.6x)" << std::endl;
    }
    else if (season == "spring")
    {
        seasonalMultiplier = 1.0;
        legacySystem->setPressure(5);
        std::cout << "ADAPTER: Spring mode - Normal watering (1.0x)" << std::endl;
    }
    else if (season == "fall" || season == "autumn")
    {
        seasonalMultiplier = 0.8;
        legacySystem->setPressure(5);
        std::cout << "ADAPTER: Fall mode - Slightly reduced watering (0.8x)" << std::endl;
    }
    else
    {
        seasonalMultiplier = 1.0;
        std::cout << "ADAPTER: Unknown season - Using default settings" << std::endl;
    }

    std::cout << "ADAPTER: Seasonal multiplier set to " << seasonalMultiplier << "x" << std::endl;
}

std::string WateringAdapter::getSystemStatus()
{
    std::ostringstream oss;
    oss << "\n╔═══════════════════════════════════╗\n";
    oss << "║      WATERING SYSTEM STATUS       ║\n";
    oss << "╠═══════════════════════════════════╣\n";
    oss << "║ Adapter Layer: ACTIVE             ║\n";
    oss << "║ Season: " << std::left << std::setw(27) << currentSeason << "║\n";
    oss << "║ Multiplier: " << std::left << std::setw(23) << seasonalMultiplier << "║\n";
    oss << "║ Active Zones: " << std::left << std::setw(21) << zoneCounter << "║\n";
    oss << "╠═══════════════════════════════════╣\n";
    oss << "║        LEGACY SYSTEM STATUS       ║\n";
    oss << "╠═══════════════════════════════════╣\n";

    std::string legacyStatus = legacySystem->getStatus();
    oss << legacyStatus << "\n";
    oss << "╚═══════════════════════════════════╝";

    return oss.str();
}

LegacyIrrigationSystem *WateringAdapter::getLegacySystem() const
{
    return legacySystem;
}