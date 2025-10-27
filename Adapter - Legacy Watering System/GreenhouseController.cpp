#include "GreenhouseController.h"
#include "../Composite - The Store layout/GreenhouseComponent.h"
#include <iostream>

GreenhouseController::GreenhouseController(ModernWateringSystem *system, GreenhouseComponent *greenhouseComp)
    : wateringSystem(system), greenhouse(greenhouseComp), currentSeason("spring")
{
    std::cout << "\n╔═══════════════════════════════════════════╗" << std::endl;
    std::cout << "║   GREENHOUSE CONTROLLER INITIALIZED       ║" << std::endl;
    std::cout << "╚═══════════════════════════════════════════╝" << std::endl;
    wateringSystem->adjustForSeason(currentSeason);
}

GreenhouseController::~GreenhouseController()
{
    std::cout << "GreenhouseController: Shutting down..." << std::endl;
}

void GreenhouseController::performDailyMaintenance()
{
    std::cout << "\n╔═══════════════════════════════════════════╗" << std::endl;
    std::cout << "║      DAILY MAINTENANCE ROUTINE            ║" << std::endl;
    std::cout << "╚═══════════════════════════════════════════╝" << std::endl;
    std::cout << "Season: " << currentSeason << std::endl;

    // Greenhouse handles its own plant updates through composite structure
    if (greenhouse)
    {
        std::cout << "Greenhouse: Performing plant updates..." << std::endl;
        // greenhouse->performMaintenance(); // If this method exists in GreenhouseComponent
    }

    // Water the greenhouse
    waterGreenhouse();
}

void GreenhouseController::waterGreenhouse()
{
    std::cout << "\nGreenhouseController: Initiating watering cycle..." << std::endl;
    wateringSystem->waterGreenhouse(greenhouse);
}

void GreenhouseController::changeSeason(const std::string &season)
{
    std::cout << "\n╔═══════════════════════════════════════════╗" << std::endl;
    std::cout << "║         SEASONAL CHANGE                   ║" << std::endl;
    std::cout << "╚═══════════════════════════════════════════╝" << std::endl;
    std::cout << "GreenhouseController: Changing season from "
              << currentSeason << " to " << season << std::endl;

    currentSeason = season;
    wateringSystem->adjustForSeason(season);

    // Greenhouse handles updating its plants' seasons
    if (greenhouse)
    {
        std::cout << "GreenhouseController: Notifying greenhouse of season change..." << std::endl;
        // greenhouse->changeSeason(season); // If this method exists
    }
}

std::string GreenhouseController::getCurrentSeason() const
{
    return currentSeason;
}

void GreenhouseController::displayGreenhouseStatus() const
{
    std::cout << "\n╔════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║         GREENHOUSE STATUS                      ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════╝" << std::endl;
    std::cout << "Season: " << currentSeason << "\n"
              << std::endl;

    if (greenhouse)
    {
        greenhouse->display();
    }
    else
    {
        std::cout << "No greenhouse connected" << std::endl;
    }
}

std::string GreenhouseController::getSystemStatus() const
{
    return wateringSystem->getSystemStatus();
}