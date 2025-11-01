/**
 * @file Plant.h
 * @brief Header file for the Plant abstract base class
 * @author NJD Films
 * @date 2024
 */

#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <vector>

// Forward declarations
class PlantCareRoutine;
class PlantContext;
class PlantCareStrategy;
class PlantState;

/**
 * @class Plant
 * @brief Abstract base class representing a plant in the greenhouse system
 * @ingroup Core
 *
 * Plant serves as the abstract base for all plant types in the greenhouse management system.
 * It maintains comprehensive plant data including identity, physical characteristics, care
 * requirements, lifecycle state, and pattern-based behaviors.
 *
 * The class integrates multiple design patterns:
 * - **Prototype**: Supports cloning via pure virtual `clone()` method
 * - **Template**: Uses PlantCareRoutine for standardized care procedures
 * - **State**: Manages lifecycle stages (seedling, growing, mature, flowering, dormant)
 * - **Strategy**: Applies different care strategies (frequent, moderate, minimal watering)
 *
 * @par Key Responsibilities:
 * - Track plant identity, species, age, and health
 * - Manage growth and maturity lifecycle
 * - Store care requirements (watering, sunlight, fertilizing, soil)
 * - Maintain care history (last watered, fertilized, pruned)
 * - Support pattern-based behaviors (clone, state transitions, care strategies)
 *
 * @par Design Pattern Roles:
 * - Prototype: Abstract prototype defining `clone()` interface
 * - Template: Client of PlantCareRoutine template method
 * - State: Context maintaining current PlantState
 * - Strategy: Context using PlantCareStrategy
 *
 * @see PlantCareRoutine
 * @see PlantContext
 * @see PlantState
 * @see PlantCareStrategy
 */
class Plant {
private:
    // Identity attributes
    int plantId;                        
    std::string species;                  
    std::string scientificName;        
    int age;                              

    // Physical attributes
    double height;                       
    double basePrice;                   
    bool readyForSale;                  
    int healthLevel;                   

    // Care requirements
    int wateringFrequency;               
    int sunlightRequirement;           
    int fertilizingFrequency;          
    std::string soilType;                 

    // Lifecycle attributes
    int daysToMaturity;                   
    int currentGrowthDays;                
    std::string currentSeason;            

    // Pattern integration
    PlantCareRoutine* careRoutine;       
    PlantContext* context;                
    PlantState* currentState;           
    PlantCareStrategy* careStrategy;      

    // Care history
    std::string lastWatered;           
    std::string lastFertilized;           
    std::string lastPruned;               
    int timesWatered;                   
    int timesFertilized;                 
    int timesPruned;                     

    // Location tracking
    std::string location;               
    int shelfNumber;                      

protected:
    /**
     * @brief Protected constructor for derived classes
     * @param species Species name
     * @param daysToMaturity Days until plant reaches maturity
     */
    Plant(const std::string& species, int daysToMaturity);

public:
    /** @brief Default constructor */
    Plant();

    /**
     * @brief Constructor with ID and species
     * @param id Plant ID
     * @param species Species name
     */
    Plant(int id, const std::string& species);

    /** @brief Virtual destructor */
    virtual ~Plant();

    /**
     * @brief Copy constructor for Prototype pattern
     * @param other Plant to copy from
     */
    Plant(const Plant& other);

    /**
     * @brief Pure virtual clone method for Prototype pattern
     * @return Pointer to cloned plant
     * @note Must be implemented by derived classes
     */
    virtual Plant* clone() const = 0;

    // Basic getters/setters (inline comments for brevity)
    int getPlantId() const;                     
    void setPlantId(int id);                 
    std::string getSpecies() const;            
    void setSpecies(const std::string& species); 
    std::string getScientificName() const;      
    void setScientificName(const std::string& name); 
    int getAge() const;                         
    void incrementAge();                        
    double getHeight() const;                   
    void setHeight(double h);                  
    void grow(double amount);                   
    double getBasePrice() const;                
    void setBasePrice(double price);         
    bool isReadyForSale() const;                
    void setReadyForSale(bool ready);           
    int getHealthLevel() const;                 
    void setHealthLevel(int health);         
    void modifyHealth(int delta);               
    int getWateringFrequency() const;           
    void setWateringFrequency(int days);        
    int getSunlightRequirement() const;         
    void setSunlightRequirement(int hours);     
    int getFertilizingFrequency() const;       
    void setFertilizingFrequency(int days);     
    std::string getSoilType() const;          
    void setSoilType(const std::string& soil);  
    int getDaysToMaturity() const;              
    void setDaysToMaturity(int days);           
    int getCurrentGrowthDays() const;           
    void incrementGrowthDays();                 
    std::string getCurrentSeason() const;      
    void setCurrentSeason(const std::string& season); 
    bool isMature() const;                     

    // Template Pattern - Care Routine
    PlantCareRoutine* getCareRoutine() const;   
    void setCareRoutine(PlantCareRoutine* routine); 
    /**
     * @brief Execute the template method care routine
     * @note Uses Template Pattern through PlantCareRoutine
     */
    void executeCareRoutine();

    // State Pattern - Lifecycle State
    PlantContext* getContext() const;         
    void setContext(PlantContext* ctx);        
    PlantState* getCurrentState() const;        
    void setState(PlantState* state);           
    /**
     * @brief Trigger state transition
     * @note Uses State Pattern to move between lifecycle stages
     */
    void transitionState();

    // Strategy Pattern - Care Strategy
    PlantCareStrategy* getCareStrategy() const; 
    void setCareStrategy(PlantCareStrategy* strategy); 
    /**
     * @brief Apply current care strategy
     * @note Uses Strategy Pattern for watering approach
     */
    void applyCareStrategy();

    // Care actions
    void water();                       
    void fertilize();                       
    void prune();                              
    void inspect();                            

    // Care history
    std::string getLastWatered() const;        
    void updateLastWatered(const std::string& timestamp);
    std::string getLastFertilized() const;  
    void updateLastFertilized(const std::string& timestamp);
    std::string getLastPruned() const;        
    void updateLastPruned(const std::string& timestamp); 
    int getTimesWatered() const;               
    int getTimesFertilized() const;           
    int getTimesPruned() const;                 

    // Location
    std::string getLocation() const;            
    void setLocation(const std::string& loc);  
    int getShelfNumber() const;               
    void setShelfNumber(int shelf);             

    // Display and type information
    /**
     * @brief Display plant information
     * @note Virtual for polymorphic behavior
     */
    virtual void display() const;

    /**
     * @brief Get plant type
     * @return Type string (e.g., "Rose", "Cactus")
     * @note Pure virtual - must be implemented by derived classes
     */
    virtual std::string getType() const = 0;

    std::string getStateDescription() const;   
    std::string getCareDescription() const;    

    // Care needs assessment
    bool needsWater() const;                  
    bool needsFertilizer() const;             
    bool needsPruning() const;                 
    bool isHealthy() const;                     
    bool needsAttention() const;               

    // Simulation
    void update();                             
    /**
     * @brief Initialize plant-specific values
     * @note Virtual for derived class customization
     */
    virtual void initialize();

    // Persistence
    std::string serialize() const;           
    void deserialize(const std::string& data);  
};

#endif // PLANT_H