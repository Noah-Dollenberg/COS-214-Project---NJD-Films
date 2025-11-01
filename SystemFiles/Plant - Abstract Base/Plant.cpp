#include "../Plant - Abstract Base/Plant.h"
#include "../Template- Plant Care/PlantCareRoutine.h"
#include "../State - Plant lifecycle/PlantContext.h"
#include "../State - Plant lifecycle/PlantState.h"
#include "../Strategy - Watering Methods/PlantCareStrategy.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>

// ========== CONSTRUCTORS & DESTRUCTOR ==========

Plant::Plant() 
    : plantId(0), species("Unknown"), scientificName(""), age(0),
      height(0.0), basePrice(0.0), readyForSale(false), healthLevel(100),
      wateringFrequency(7), sunlightRequirement(6), fertilizingFrequency(30),
      soilType("loamy"), daysToMaturity(60), currentGrowthDays(0),
      currentSeason("spring"), careRoutine(nullptr), context(nullptr),
      currentState(nullptr), careStrategy(nullptr), shelfNumber(0),
      timesWatered(0), timesFertilized(0), timesPruned(0) {}

Plant::Plant(int id, const std::string& spec) 
    : Plant() {
    plantId = id;
    species = spec;
}

Plant::Plant(const std::string& spec, int daysToMat) 
    : Plant() {
    species = spec;
    daysToMaturity = daysToMat;
}

Plant::~Plant() {
    // Note: Don't delete careRoutine, context, state, strategy
    // They may be shared or managed elsewhere
}

Plant::Plant(const Plant& other) 
    : plantId(other.plantId), species(other.species),
      scientificName(other.scientificName), age(other.age),
      height(other.height), basePrice(other.basePrice),
      readyForSale(other.readyForSale), healthLevel(other.healthLevel),
      wateringFrequency(other.wateringFrequency),
      sunlightRequirement(other.sunlightRequirement),
      fertilizingFrequency(other.fertilizingFrequency),
      soilType(other.soilType), daysToMaturity(other.daysToMaturity),
      currentGrowthDays(other.currentGrowthDays),
      currentSeason(other.currentSeason),
      careRoutine(other.careRoutine), context(other.context),
      currentState(other.currentState), careStrategy(other.careStrategy),
      location(other.location), shelfNumber(other.shelfNumber),
      timesWatered(0), timesFertilized(0), timesPruned(0) {}

// ========== IDENTITY METHODS ==========

int Plant::getPlantId() const { return plantId; }
void Plant::setPlantId(int id) { plantId = id; }

std::string Plant::getSpecies() const { return species; }
void Plant::setSpecies(const std::string& spec) { species = spec; }

std::string Plant::getScientificName() const { return scientificName; }
void Plant::setScientificName(const std::string& name) { scientificName = name; }

int Plant::getAge() const { return age; }
void Plant::incrementAge() { age++; }

// ========== PHYSICAL METHODS ==========

double Plant::getHeight() const { return height; }
void Plant::setHeight(double h) { height = h; }
void Plant::grow(double amount) { height += amount; }

double Plant::getBasePrice() const { return basePrice; }
void Plant::setBasePrice(double price) { basePrice = price; }

bool Plant::isReadyForSale() const { return readyForSale; }
void Plant::setReadyForSale(bool ready) { readyForSale = ready; }

int Plant::getHealthLevel() const { return healthLevel; }
void Plant::setHealthLevel(int health) { 
    healthLevel = health;
    if (healthLevel > 100) healthLevel = 100;
    if (healthLevel < 0) healthLevel = 0;
}
void Plant::modifyHealth(int delta) { 
    setHealthLevel(healthLevel + delta); 
}

// ========== CARE REQUIREMENTS ==========

int Plant::getWateringFrequency() const { return wateringFrequency; }
void Plant::setWateringFrequency(int days) { wateringFrequency = days; }

int Plant::getSunlightRequirement() const { return sunlightRequirement; }
void Plant::setSunlightRequirement(int hours) { sunlightRequirement = hours; }

int Plant::getFertilizingFrequency() const { return fertilizingFrequency; }
void Plant::setFertilizingFrequency(int days) { fertilizingFrequency = days; }

std::string Plant::getSoilType() const { return soilType; }
void Plant::setSoilType(const std::string& soil) { soilType = soil; }

// ========== LIFECYCLE METHODS ==========

int Plant::getDaysToMaturity() const { return daysToMaturity; }
void Plant::setDaysToMaturity(int days) { daysToMaturity = days; }

int Plant::getCurrentGrowthDays() const { return currentGrowthDays; }
void Plant::incrementGrowthDays() { 
    currentGrowthDays++; 
    if (currentGrowthDays >= daysToMaturity && !readyForSale) {
        readyForSale = true;
        std::cout << species << " #" << plantId << " is now mature and ready for sale!" << std::endl;
    }
}

std::string Plant::getCurrentSeason() const { return currentSeason; }
void Plant::setCurrentSeason(const std::string& season) { currentSeason = season; }

bool Plant::isMature() const { return currentGrowthDays >= daysToMaturity; }

// ========== PATTERN RELATIONSHIPS ==========

PlantCareRoutine* Plant::getCareRoutine() const { return careRoutine; }
void Plant::setCareRoutine(PlantCareRoutine* routine) { careRoutine = routine; }
void Plant::executeCareRoutine() {
    if (careRoutine) {
        // Template pattern - call the template method
        // careRoutine->performCare(this);
    }
}

PlantContext* Plant::getContext() const { return context; }
void Plant::setContext(PlantContext* ctx) { context = ctx; }

PlantState* Plant::getCurrentState() const { return currentState; }
void Plant::setState(PlantState* state) { currentState = state; }
void Plant::transitionState() {
    if (context) {
        // State pattern - trigger transition
        // context->nextState();
    }
}

PlantCareStrategy* Plant::getCareStrategy() const { return careStrategy; }
void Plant::setCareStrategy(PlantCareStrategy* strategy) { careStrategy = strategy; }
void Plant::applyCareStrategy() {
    if (careStrategy) {
        // Strategy pattern - apply care strategy
        // careStrategy->applyCare(this);
    }
}

// ========== CARE ACTIONS ==========

void Plant::water() {
    timesWatered++;
    modifyHealth(5);
    time_t now = time(0);
    lastWatered = ctime(&now);
    std::cout << species << " #" << plantId << " was watered. Health: " 
              << healthLevel << "%" << std::endl;
}

void Plant::fertilize() {
    timesFertilized++;
    modifyHealth(10);
    grow(2.0);
    time_t now = time(0);
    lastFertilized = ctime(&now);
    std::cout << species << " #" << plantId << " was fertilized. Health: " 
              << healthLevel << "%, Height: " << height << "cm" << std::endl;
}

void Plant::prune() {
    timesPruned++;
    modifyHealth(3);
    time_t now = time(0);
    lastPruned = ctime(&now);
    std::cout << species << " #" << plantId << " was pruned." << std::endl;
}

void Plant::inspect() {
    std::cout << "\n=== Inspecting Plant ===" << std::endl;
    display();
}

// ========== HISTORY TRACKING ==========

std::string Plant::getLastWatered() const { return lastWatered; }
void Plant::updateLastWatered(const std::string& timestamp) { lastWatered = timestamp; }

std::string Plant::getLastFertilized() const { return lastFertilized; }
void Plant::updateLastFertilized(const std::string& timestamp) { lastFertilized = timestamp; }

std::string Plant::getLastPruned() const { return lastPruned; }
void Plant::updateLastPruned(const std::string& timestamp) { lastPruned = timestamp; }

int Plant::getTimesWatered() const { return timesWatered; }
int Plant::getTimesFertilized() const { return timesFertilized; }
int Plant::getTimesPruned() const { return timesPruned; }

// ========== LOCATION METHODS ==========

std::string Plant::getLocation() const { return location; }
void Plant::setLocation(const std::string& loc) { location = loc; }

int Plant::getShelfNumber() const { return shelfNumber; }
void Plant::setShelfNumber(int shelf) { shelfNumber = shelf; }

// ========== DISPLAY & INFO ==========

void Plant::display() const {
    std::cout << "Plant ID: " << plantId << std::endl;
    std::cout << "Species: " << species << std::endl;
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Age: " << age << " days" << std::endl;
    std::cout << "Height: " << height << " cm" << std::endl;
    std::cout << "Health: " << healthLevel << "%" << std::endl;
    std::cout << "Growth: " << currentGrowthDays << "/" << daysToMaturity << " days" << std::endl;
    std::cout << "Ready for Sale: " << (readyForSale ? "Yes" : "No") << std::endl;
    std::cout << "Price: R" << std::fixed << std::setprecision(2) << basePrice << std::endl;
    std::cout << "Location: " << location << std::endl;
}

std::string Plant::getStateDescription() const {
    if (currentState) {
        // return currentState->getStateName();
        return "State managed by PlantState";
    }
    return "No state";
}

std::string Plant::getCareDescription() const {
    std::ostringstream oss;
    oss << "Water every " << wateringFrequency << " days, "
        << "Fertilize every " << fertilizingFrequency << " days";
    return oss.str();
}

// ========== VALIDATION & CHECKS ==========

bool Plant::needsWater() const {
    // Simple check - in real system compare timestamp
    return timesWatered < (age / wateringFrequency);
}

bool Plant::needsFertilizer() const {
    return timesFertilized < (age / fertilizingFrequency);
}

bool Plant::needsPruning() const {
    return height > 50.0 && timesPruned < 3;
}

bool Plant::isHealthy() const {
    return healthLevel > 70;
}

bool Plant::needsAttention() const {
    return needsWater() || needsFertilizer() || needsPruning() || !isHealthy();
}

// ========== UTILITY METHODS ==========

void Plant::update() {
    incrementAge();
    incrementGrowthDays();
    
    // Slowly decrease health if not cared for
    if (needsWater()) modifyHealth(-2);
    if (needsFertilizer()) modifyHealth(-1);
    
    // Natural growth
    if (isHealthy()) grow(0.5);
}

void Plant::initialize() {
    // Override in derived classes for specific initialization
}

// ========== SERIALIZATION ==========

std::string Plant::serialize() const {
    std::ostringstream oss;
    oss << plantId << "," << species << "," << age << "," 
        << height << "," << healthLevel << "," << readyForSale;
    return oss.str();
}

void Plant::deserialize(const std::string& data) {
    // Parse CSV string and restore plant state
    // Implementation depends on your needs
}