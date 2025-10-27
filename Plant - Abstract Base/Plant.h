#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <vector>

// Forward declarations
class PlantCareRoutine;
class PlantContext;
class PlantCareStrategy;
class PlantState;

class Plant {
private:
    // ========== IDENTITY ATTRIBUTES ==========
    int plantId;                          // Unique identifier
    std::string species;                  // "Rose", "Cactus", "Lavender", etc.
    std::string scientificName;           // e.g., "Rosa rubiginosa"
    int age;                              // Age in days

    // ========== PHYSICAL ATTRIBUTES ==========
    double height;                        // Height in cm
    double basePrice;                     // Base selling price
    bool readyForSale;                    // Is it mature enough to sell?
    int healthLevel;                      // 0-100 health percentage

    // ========== CARE REQUIREMENTS ==========
    int wateringFrequency;                // Days between watering
    int sunlightRequirement;              // Hours per day (1-12)
    int fertilizingFrequency;             // Days between fertilizing
    std::string soilType;                 // "sandy", "loamy", "clay", etc.

    // ========== LIFECYCLE TRACKING ==========
    int daysToMaturity;                   // Days until ready for sale
    int currentGrowthDays;                // Days since planting
    std::string currentSeason;            // "spring", "summer", "fall", "winter"

    // ========== PATTERN RELATIONSHIPS ==========
    // Template Pattern - care routine
    PlantCareRoutine* careRoutine;        // Assigned care routine

    // State Pattern - lifecycle state
    PlantContext* context;                // For state management
    PlantState* currentState;             // Current lifecycle state

    // Strategy Pattern - watering strategy
    PlantCareStrategy* careStrategy;      // Current care strategy

    // ========== HISTORY & METADATA ==========
    std::string lastWatered;              // Timestamp of last watering
    std::string lastFertilized;           // Timestamp of last fertilizing
    std::string lastPruned;               // Timestamp of last pruning
    int timesWatered;                     // Total watering count
    int timesFertilized;                  // Total fertilizing count
    int timesPruned;                      // Total pruning count

    // ========== COMPOSITE/INVENTORY ==========
    std::string location;                 // "Greenhouse Section A", "Shelf 3", etc.
    int shelfNumber;                      // Which shelf it's on

protected:
    // Protected constructor for derived classes
    Plant(const std::string& species, int daysToMaturity);

public:
    // ========== CONSTRUCTORS & DESTRUCTOR ==========
    Plant();
    Plant(int id, const std::string& species);
    virtual ~Plant();

    // Copy constructor for Prototype pattern
    Plant(const Plant& other);

    // Virtual clone for Prototype pattern
    virtual Plant* clone() const = 0;

    // ========== IDENTITY GETTERS/SETTERS ==========
    int getPlantId() const;
    void setPlantId(int id);

    std::string getSpecies() const;
    void setSpecies(const std::string& species);

    std::string getScientificName() const;
    void setScientificName(const std::string& name);

    int getAge() const;
    void incrementAge();  // Called daily/per time step

    // ========== PHYSICAL GETTERS/SETTERS ==========
    double getHeight() const;
    void setHeight(double h);
    void grow(double amount);  // Increase height

    double getBasePrice() const;
    void setBasePrice(double price);

    bool isReadyForSale() const;
    void setReadyForSale(bool ready);

    int getHealthLevel() const;
    void setHealthLevel(int health);
    void modifyHealth(int delta);  // +/- health

    // ========== CARE REQUIREMENTS GETTERS/SETTERS ==========
    int getWateringFrequency() const;
    void setWateringFrequency(int days);

    int getSunlightRequirement() const;
    void setSunlightRequirement(int hours);

    int getFertilizingFrequency() const;
    void setFertilizingFrequency(int days);

    std::string getSoilType() const;
    void setSoilType(const std::string& soil);

    // ========== LIFECYCLE GETTERS/SETTERS ==========
    int getDaysToMaturity() const;
    void setDaysToMaturity(int days);

    int getCurrentGrowthDays() const;
    void incrementGrowthDays();

    std::string getCurrentSeason() const;
    void setCurrentSeason(const std::string& season);

    bool isMature() const;  // currentGrowthDays >= daysToMaturity

    // ========== PATTERN RELATIONSHIP METHODS ==========

    // Template Pattern - Care Routine
    PlantCareRoutine* getCareRoutine() const;
    void setCareRoutine(PlantCareRoutine* routine);
    void executeCareRoutine();  // Execute the template method

    // State Pattern - Lifecycle State
    PlantContext* getContext() const;
    void setContext(PlantContext* ctx);

    PlantState* getCurrentState() const;
    void setState(PlantState* state);
    void transitionState();  // Trigger state change

    // Strategy Pattern - Care Strategy
    PlantCareStrategy* getCareStrategy() const;
    void setCareStrategy(PlantCareStrategy* strategy);
    void applyCareStrategy();  // Use current strategy

    // ========== CARE ACTION METHODS (Command Pattern) ==========
    void water();
    void fertilize();
    void prune();
    void inspect();

    // ========== HISTORY TRACKING ==========
    std::string getLastWatered() const;
    void updateLastWatered(const std::string& timestamp);

    std::string getLastFertilized() const;
    void updateLastFertilized(const std::string& timestamp);

    std::string getLastPruned() const;
    void updateLastPruned(const std::string& timestamp);

    int getTimesWatered() const;
    int getTimesFertilized() const;
    int getTimesPruned() const;

    // ========== LOCATION METHODS (Composite Pattern) ==========
    std::string getLocation() const;
    void setLocation(const std::string& loc);

    int getShelfNumber() const;
    void setShelfNumber(int shelf);

    // ========== DISPLAY & INFO ==========
    virtual void display() const;  // Virtual for polymorphism
    virtual std::string getType() const = 0;  // Pure virtual - each plant type implements
    std::string getStateDescription() const;
    std::string getCareDescription() const;

    // ========== VALIDATION & CHECKS ==========
    bool needsWater() const;       // Check if watering is due
    bool needsFertilizer() const;  // Check if fertilizing is due
    bool needsPruning() const;     // Check if pruning is needed
    bool isHealthy() const;        // health > 70
    bool needsAttention() const;   // Needs any care action

    // ========== UTILITY METHODS ==========
    void update();  // Called each simulation step/day
    virtual void initialize();  // Initialize plant-specific values

    // ========== SERIALIZATION (Optional for save/load) ==========
    std::string serialize() const;  // Convert to string for saving
    void deserialize(const std::string& data);  // Load from string
};

#endif // PLANT_H