/**
 * Greenhouse Project Simulation
 *
 * This demo showcases ALL 11 design patterns working together in a realistic
 * greenhouse management scenario.
 *
 * Course: COS 214
 * Project: Greenhouse Management System (NJD Films)
 *
 * Design Patterns Demonstrated (in order):
 * 1.  Factory Pattern      - Creating different plant types
 * 2.  Prototype Pattern    - Cloning plants for propagation
 * 3.  Composite Pattern    - Organizing greenhouse structure
 * 4.  Iterator Pattern     - Traversing plant inventory
 * 5.  Template Pattern     - Standardized plant care routines
 * 6.  Strategy Pattern     - Dynamic watering strategies
 * 7.  State Pattern        - Plant lifecycle management
 * 8.  Adapter Pattern      - Integrating legacy watering system
 * 9.  Command Pattern      - Scheduling staff tasks
 * 10. Decorator Pattern    - Adding features to plant products
 * 11. Builder Pattern      - Creating complex plant arrangements
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

// Plant base class
#include "Plant - Abstract Base/Plant.h"

// Factory Pattern (includes plant class definitions)
#include "Factory - Plant Creation/PlantFactory.h"
#include "Factory - Plant Creation/RoseFactory.h"
#include "Factory - Plant Creation/CactusFactory.h"
#include "Factory - Plant Creation/SucculentFactory.h"
#include "Factory - Plant Creation/LavenderFactory.h"
#include "Factory - Plant Creation/BaobabFactory.h"

// Composite Pattern
#include "Composite - The Store layout/GreenhouseComponent.h"
#include "Composite - The Store layout/Greenhouse.h"
#include "Composite - The Store layout/GreenhouseSection.h"
#include "Composite - The Store layout/Shelf.h"
#include "Composite - The Store layout/PlantLeaf.h"

// Iterator Pattern
#include "Iterator - Inventory Management/PlantIterator.h"
#include "Iterator - Inventory Management/GreenhouseInventory.h"

// Template Pattern
#include "Template- Plant Care/PlantCareRoutine.h"
#include "Template- Plant Care/RoseCare.h"
#include "Template- Plant Care/SucculentCare.h"

// Strategy Pattern
#include "Strategy - Watering Methods/PlantCareStrategy.h"
#include "Strategy - Watering Methods/FrequentWatering.h"
#include "Strategy - Watering Methods/ModerateWatering.h"
#include "Strategy - Watering Methods/MinimalWatering .h"
#include "Strategy - Watering Methods/PlantCareContext.h"

// State Pattern
#include "State - Plant lifecycle/PlantContext.h"
#include "State - Plant lifecycle/SeedlingState.h"
#include "State - Plant lifecycle/GrowingState.h"
#include "State - Plant lifecycle/MatureState.h"
#include "State - Plant lifecycle/FloweringState.h"
#include "State - Plant lifecycle/DormantState.h"

// Adapter Pattern
#include "Adapter - Legacy Watering System/LegacyIrrigationSystem.h"
#include "Adapter - Legacy Watering System/ModernWateringSystem.h"
#include "Adapter - Legacy Watering System/WateringAdapter.h"
#include "Adapter - Legacy Watering System/GreenhouseController.h"

// Command Pattern
#include "Command - Staff Functions/StaffCommand.h"
#include "Command - Staff Functions/WaterPlantsCommand.h"
#include "Command - Staff Functions/FertilizePlantsCommand.h"
#include "Command - Staff Functions/PrunePlantsCommand.h"
#include "Command - Staff Functions/AssistCustomerCommand.h"
#include "Command - Staff Functions/StaffMember.h"
#include "Command - Staff Functions/PlantCareStaff.h"
#include "Command - Staff Functions/SalesStaff.h"
#include "Command - Staff Functions/TaskScheduler.h"

// Decorator Pattern
#include "Decorator - Plant Decoration/PlantProduct.h"
#include "Decorator - Plant Decoration/BasicPlant.h"
#include "Decorator - Plant Decoration/PlantDecorator.h"
#include "Decorator - Plant Decoration/DecorativePotDecorator.h"
#include "Decorator - Plant Decoration/GiftWrappingDecorator.h"
#include "Decorator - Plant Decoration/GreetingCardDecorator.h"

// Builder Pattern
#include "Builder - Plant Bundle Creator/PlantArrangement.h"
#include "Builder - Plant Bundle Creator/PlantArrangementBuilder.h"
#include "Builder - Plant Bundle Creator/GiftArrangementBuilder.h"
#include "Builder - Plant Bundle Creator/LandscapeArrangementBuilder.h"
#include "Builder - Plant Bundle Creator/ArrangementDirector.h"

using namespace std;

// Util Functions

void printDivider() {
    cout << "\n" << string(80, '=') << endl;
}

void printHeader(const string& title) {
    printDivider();
    cout << "  " << title << endl;
    printDivider();
}

void printSubheader(const string& subtitle) {
    cout << "\n" << string(80, '-') << endl;
    cout << "  " << subtitle << endl;
    cout << string(80, '-') << endl;
}

void waitForUser() {
    cout << "\nPress Enter to continue";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// DEMO 1: FACTORY PATTERN - Plant Creation

vector<Plant*> demonstrateFactoryPattern() {
    printHeader("PATTERN 1: FACTORY PATTERN - Plant Creation");

    cout << "\nThe Factory Pattern provides an interface for creating objects in a" << endl;
    cout << "superclass, but allows subclasses to alter the type of objects created." << endl;
    cout << "\nIn our greenhouse, we use factories to create different plant types." << endl;

    vector<Plant*> plants;
    vector<PlantFactory*> factories;

    // Create factories
    factories.push_back(new RoseFactory());
    factories.push_back(new LavenderFactory());
    factories.push_back(new CactusFactory());
    factories.push_back(new SucculentFactory());
    factories.push_back(new BaobabFactory());

    printSubheader("Creating Plants Using Factories");

    for (PlantFactory* factory : factories) {
        cout << "\nUsing " << factory->getPlantType() << " Factory" << endl;
        Plant* plant = factory->createPlant();
        plant->setPlantId(plants.size() + 1);
        plants.push_back(plant);

        cout << "  Created: " << plant->getSpecies() << endl;
        cout << "  Price: R" << fixed << setprecision(2) << plant->getBasePrice() << endl;
        cout << "  Watering: Every " << plant->getWateringFrequency() << " days" << endl;
        cout << "  Sunlight: " << plant->getSunlightRequirement() << " hours/day" << endl;
    }

    cout << "\nFactories encapsulate object creation logic," << endl;
    cout << "making it easy to add new plant types without changing client code." << endl;

    // Cleanup factories
    for (PlantFactory* factory : factories) {
        delete factory;
    }

    waitForUser();
    return plants;
}

// DEMO 2: PROTOTYPE PATTERN - Plant Propagation

void demonstratePrototypePattern(vector<Plant*>& plants) {
    printHeader("PATTERN 2: PROTOTYPE PATTERN - Plant Propagation");

    cout << "\nThe Prototype Pattern creates new objects by cloning existing ones," << endl;
    cout << "which is perfect for plant propagation in our greenhouse!" << endl;

    printSubheader("Cloning Rose for Propagation");

    Plant* originalRose = plants[0];
    cout << "\nOriginal Rose:" << endl;
    cout << "  ID: " << originalRose->getPlantId() << endl;
    cout << "  Species: " << originalRose->getSpecies() << endl;
    cout << "  Price: R" << fixed << setprecision(2) << originalRose->getBasePrice() << endl;
    cout << "  Health: " << originalRose->getHealthLevel() << "%" << endl;

    // Clone the rose
    Plant* clonedRose = originalRose->clone();
    clonedRose->setPlantId(plants.size() + 1);
    plants.push_back(clonedRose);

    cout << "\nCloned Rose (Propagated):" << endl;
    cout << "  ID: " << clonedRose->getPlantId() << endl;
    cout << "  Species: " << clonedRose->getSpecies() << endl;
    cout << "  Price: R" << fixed << setprecision(2) << clonedRose->getBasePrice() << endl;
    cout << "  Health: " << clonedRose->getHealthLevel() << "%" << endl;
    cout << "  Same characteristics as original!" << endl;

    printSubheader("Cloning Succulent for Propagation");

    Plant* originalSucculent = plants[3];
    Plant* clonedSucculent = originalSucculent->clone();
    clonedSucculent->setPlantId(plants.size() + 1);
    plants.push_back(clonedSucculent);

    cout << "\nCloned Succulent (Propagated):" << endl;
    cout << "  ID: " << clonedSucculent->getPlantId() << endl;
    cout << "  Species: " << clonedSucculent->getSpecies() << endl;

    printSubheader("Testing Clone Independence");

    // Modify the clone to show it's independent
    clonedRose->setHealthLevel(95);
    cout << "\nAfter modifying clone health to 95%:" << endl;
    cout << "  Original Rose Health: " << originalRose->getHealthLevel() << "%" << endl;
    cout << "  Cloned Rose Health: " << clonedRose->getHealthLevel() << "%" << endl;
    cout << "  Clones are independent objects!" << endl;

    printSubheader("Mass Propagation Demo");

    cout << "\nCreating multiple clones for nursery stock:" << endl;
    for (int i = 0; i < 3; i++) {
        Plant* clone = originalRose->clone();
        clone->setPlantId(plants.size() + 1);
        plants.push_back(clone);
        cout << "  Clone #" << (i + 1) << " created (ID: " << clone->getPlantId() << ")" << endl;
    }

    cout << "\nPrototype allows efficient plant propagation by cloning" << endl;
    cout << "existing healthy plants, preserving their characteristics." << endl;

    waitForUser();
}

// DEMO 3: COMPOSITE PATTERN - Greenhouse Structure

Greenhouse* demonstrateCompositePattern(vector<Plant*>& plants) {
    printHeader("PATTERN 3: COMPOSITE PATTERN - Greenhouse Organization");

    cout << "\nThe Composite Pattern lets you compose objects into tree structures" << endl;
    cout << "to represent part-whole hierarchies." << endl;
    cout << "\nOur greenhouse is organized hierarchically: Greenhouse → Sections → Shelves → Plants" << endl;

    printSubheader("Building Greenhouse Structure");

    // Create main greenhouse
    Greenhouse* greenhouse = new Greenhouse("NJD Films Main Greenhouse");
    cout << "\nCreated: Main Greenhouse" << endl;

    // Create Flowering Section
    GreenhouseSection* floweringSection = new GreenhouseSection("flowering", "Flowering Plants Section");
    Shelf* shelf1 = new Shelf(1);
    shelf1->add(new PlantLeaf(plants[0], "Rose #1"));
    shelf1->add(new PlantLeaf(plants[1], "Lavender #1"));
    shelf1->add(new PlantLeaf(plants[6], "Rose Clone #1"));
    floweringSection->add(shelf1);
    greenhouse->add(floweringSection);
    cout << "  Added: Flowering Section with Shelf 1 (3 plants)" << endl;

    // Create Desert Section
    GreenhouseSection* desertSection = new GreenhouseSection("desert", "Desert Plants Section");
    Shelf* shelf2 = new Shelf(2);
    shelf2->add(new PlantLeaf(plants[2], "Cactus #1"));
    shelf2->add(new PlantLeaf(plants[3], "Succulent #1"));
    shelf2->add(new PlantLeaf(plants[7], "Succulent Clone #1"));
    desertSection->add(shelf2);
    greenhouse->add(desertSection);
    cout << "  Added: Desert Section with Shelf 2 (3 plants)" << endl;

    // Create Tropical Section
    GreenhouseSection* tropicalSection = new GreenhouseSection("tropical", "Tropical Trees Section");
    Shelf* shelf3 = new Shelf(3);
    shelf3->add(new PlantLeaf(plants[4], "Baobab Tree #1"));
    tropicalSection->add(shelf3);
    greenhouse->add(tropicalSection);
    cout << "  Added: Tropical Section with Shelf 3 (1 tree)" << endl;

    printSubheader("Displaying Greenhouse Hierarchy");
    greenhouse->display(0);

    cout << "\nBENEFIT: Composite pattern allows treating individual plants and" << endl;
    cout << "groups of plants uniformly, simplifying greenhouse management." << endl;

    waitForUser();
    return greenhouse;
}

// DEMO 4: ITERATOR PATTERN - Inventory Management

GreenhouseInventory* demonstrateIteratorPattern(vector<Plant*>& plants) {
    printHeader("PATTERN 4: ITERATOR PATTERN - Inventory Management");

    cout << "\nThe Iterator Pattern provides a way to access elements of a collection" << endl;
    cout << "sequentially without exposing its underlying representation." << endl;

    printSubheader("Building Plant Inventory");

    // Create inventory and add plants
    GreenhouseInventory* inventory = new GreenhouseInventory();
    for (Plant* plant : plants) {
        inventory->addPlant(plant);
    }

    cout << "\nAdded " << plants.size() << " plants to inventory." << endl;

    printSubheader("Iterating Through Inventory");

    PlantIterator* iterator = inventory->createIterator();
    int count = 0;

    cout << "\nInventory Contents:" << endl;
    for (iterator->first(); !iterator->isDone(); iterator->next()) {
        Plant* plant = iterator->currentItem();
        count++;
        cout << "\n[" << count << "] " << plant->getSpecies() << " (ID: " << plant->getPlantId() << ")" << endl;
        cout << "    Price: R" << fixed << setprecision(2) << plant->getBasePrice() << endl;
        cout << "    Health: " << plant->getHealthLevel() << "%" << endl;
    }

    cout << "\nBENEFIT: Iterator provides a standard way to traverse collections," << endl;
    cout << "hiding the internal storage structure from clients." << endl;

    delete iterator;
    waitForUser();
    return inventory;
}

// DEMO 5: TEMPLATE PATTERN - Standardized Plant Care

void demonstrateTemplatePattern(vector<Plant*>& plants) {
    printHeader("PATTERN 5: TEMPLATE PATTERN - Plant Care Routines");

    cout << "\nThe Template Pattern defines the skeleton of an algorithm in a method," << endl;
    cout << "deferring some steps to subclasses." << endl;
    cout << "\nAll plants follow the same care routine structure, but with different implementations." << endl;

    printSubheader("Rose Care Routine (RoseCare Template)");

    PlantCareRoutine* roseCare = new RoseCare();
    cout << "\nExecuting standardized care routine for Rose:" << endl;
    roseCare->careForPlant();

    printSubheader("Succulent Care Routine (SucculentCare Template)");

    PlantCareRoutine* succulentCare = new SucculentCare();
    cout << "\nExecuting standardized care routine for Succulent:" << endl;
    succulentCare->careForPlant();

    cout << "\nBENEFIT: Template ensures consistent care procedures while allowing" << endl;
    cout << "customization for different plant species." << endl;

    delete roseCare;
    delete succulentCare;
    waitForUser();
}

// DEMO 6: STRATEGY PATTERN - Dynamic Watering Strategies

void demonstrateStrategyPattern(vector<Plant*>& plants) {
    printHeader("PATTERN 6: STRATEGY PATTERN - Watering Strategies");

    cout << "\nThe Strategy Pattern defines a family of algorithms, encapsulates each one," << endl;
    cout << "and makes them interchangeable at runtime." << endl;
    cout << "\nDifferent plants need different watering strategies that can change seasonally." << endl;

    Plant* rose = plants[0];
    PlantCareContext* context = new PlantCareContext(rose);

    printSubheader("Spring: Frequent Watering for Roses");
    cout << "\nSeason: Spring - Active growth period" << endl;
    context->setStrategy(new FrequentWatering());
    context->executeCare();

    printSubheader("Summer: Increased to Very Frequent Watering");
    cout << "\nSeason: Summer - Hot weather, more water needed" << endl;
    context->setStrategy(new FrequentWatering());
    context->executeCare();

    printSubheader("Fall: Moderate Watering");
    cout << "\nSeason: Fall - Preparing for dormancy" << endl;
    context->setStrategy(new ModerateWatering());
    context->executeCare();

    printSubheader("Winter: Minimal Watering");
    cout << "\nSeason: Winter - Dormant period" << endl;
    context->setStrategy(new MinimalWatering());
    context->executeCare();

    cout << "\nBENEFIT: Strategy allows dynamic adjustment of watering based on" << endl;
    cout << "season, weather, and plant needs without changing plant code." << endl;

    delete context;
    waitForUser();
}

// DEMO 7: STATE PATTERN - Plant Lifecycle Management

void demonstrateStatePattern(vector<Plant*>& plants) {
    printHeader("PATTERN 7: STATE PATTERN - Plant Lifecycle");

    cout << "\nThe State Pattern allows an object to alter its behavior when its" << endl;
    cout << "internal state changes." << endl;
    cout << "\nPlants go through different lifecycle states: Seedling → Growing → Mature → Flowering → Dormant" << endl;

    Plant* rose = plants[0];

    printSubheader("Tracking Rose Lifecycle States");

    // Create plant context for state management
    PlantContext* plantContext = new PlantContext(rose);

    // Seedling State
    cout << "\nState 1: SEEDLING" << endl;
    PlantState* seedlingState = new SeedlingState();
    plantContext->setState(seedlingState);
    cout << "  Current State: " << plantContext->getCurrentState()->getStateName() << endl;
    cout << "  - Newly planted, fragile" << endl;
    cout << "  - Needs gentle care" << endl;
    cout << "  - Not ready for sale" << endl;
    cout << "\n  Performing care actions:" << endl;
    cout << "    Watering..." << endl;
    plantContext->water();
    cout << "    Fertilizing..." << endl;
    plantContext->fertilize();
    cout << "    Checking health..." << endl;
    plantContext->checkHealth();

    // Growing State
    cout << "\n\nState 2: GROWING" << endl;
    PlantState* growingState = new GrowingState();
    plantContext->setState(growingState);
    cout << "  Current State: " << plantContext->getCurrentState()->getStateName() << endl;
    cout << "  - Actively developing" << endl;
    cout << "  - Regular care required" << endl;
    cout << "  - Still not ready for sale" << endl;
    cout << "\n  Performing care actions:" << endl;
    cout << "    Watering..." << endl;
    plantContext->water();
    cout << "    Fertilizing..." << endl;
    plantContext->fertilize();

    // Mature State
    cout << "\n\nState 3: MATURE" << endl;
    PlantState* matureState = new MatureState();
    plantContext->setState(matureState);
    cout << "  Current State: " << plantContext->getCurrentState()->getStateName() << endl;
    cout << "  - Fully developed" << endl;
    cout << "  - Ready for sale!" << endl;
    cout << "  - Price: R" << fixed << setprecision(2) << rose->getBasePrice() << endl;
    rose->setReadyForSale(true);
    cout << "\n  Performing care actions:" << endl;
    cout << "    Watering..." << endl;
    plantContext->water();
    cout << "    Checking health..." << endl;
    plantContext->checkHealth();

    // Flowering State
    cout << "\n\nState 4: FLOWERING" << endl;
    PlantState* floweringState = new FloweringState();
    plantContext->setState(floweringState);
    cout << "  Current State: " << plantContext->getCurrentState()->getStateName() << endl;
    cout << "  - Producing blooms" << endl;
    cout << "  - Premium value" << endl;
    cout << "  - Most attractive to customers" << endl;
    cout << "\n  Performing care actions:" << endl;
    cout << "    Watering..." << endl;
    plantContext->water();
    cout << "    Fertilizing..." << endl;
    plantContext->fertilize();

    // Dormant State
    cout << "\n\nState 5: DORMANT (Winter)" << endl;
    PlantState* dormantState = new DormantState();
    plantContext->setState(dormantState);
    cout << "  Current State: " << plantContext->getCurrentState()->getStateName() << endl;
    cout << "  - Minimal growth" << endl;
    cout << "  - Reduced care needs" << endl;
    cout << "  - Will return to Growing in spring" << endl;
    cout << "\n  Performing care actions:" << endl;
    cout << "    Watering..." << endl;
    plantContext->water();
    cout << "    Checking health..." << endl;
    plantContext->checkHealth();

    printSubheader("Demonstrating State Transitions");
    cout << "\nTransitioning through lifecycle:" << endl;
    plantContext->setState(new SeedlingState());
    cout << "  Starting: " << plantContext->getCurrentState()->getStateName() << endl;

    plantContext->setState(new GrowingState());
    cout << plantContext->getCurrentState()->getStateName() << endl;

    plantContext->setState(new MatureState());
    cout << plantContext->getCurrentState()->getStateName() << endl;

    plantContext->setState(new FloweringState());
    cout << plantContext->getCurrentState()->getStateName() << endl;

    cout << "\nBENEFIT: State pattern makes lifecycle transitions explicit and" << endl;
    cout << "manages state-specific behaviors cleanly." << endl;

    delete plantContext;
    waitForUser();
}

// DEMO 8: ADAPTER PATTERN - Legacy Watering System Integration

void demonstrateAdapterPattern(Greenhouse* greenhouse) {
    printHeader("PATTERN 8: ADAPTER PATTERN - Legacy System Integration");

    cout << "\nThe Adapter Pattern converts the interface of a class into another" << endl;
    cout << "interface clients expect." << endl;
    cout << "\nOur greenhouse has an old irrigation system with incompatible interface." << endl;
    cout << "The adapter makes it work with our modern watering system!" << endl;

    printSubheader("Legacy Irrigation System (Old Interface)");

    LegacyIrrigationSystem* legacySystem = new LegacyIrrigationSystem();
    cout << "\nLegacy system uses zone-based watering:" << endl;
    cout << "  - activateZone(zoneId, duration)" << endl;
    cout << "  - setPressure(level)" << endl;
    cout << "  - Old-style status reporting" << endl;

    printSubheader("Creating Adapter to Modern Interface");

    WateringAdapter* adapter = new WateringAdapter(legacySystem);
    cout << "\nAdapter translates modern calls to legacy format:" << endl;
    cout << "  Modern: waterGreenhouse(component)" << endl;
    cout << "  Legacy: activateZone(1, 10), activateZone(2, 10), etc." << endl;

    printSubheader("Using Greenhouse Controller (Modern Interface)");

    GreenhouseController* controller = new GreenhouseController(adapter, greenhouse);

    cout << "\nSetting Season: Spring" << endl;
    controller->changeSeason("spring");

    cout << "\nWatering Greenhouse (via adapter)..." << endl;
    controller->waterGreenhouse();

    cout << "\n" << controller->getSystemStatus() << endl;

    cout << "\nChanging Season: Summer (needs more water)" << endl;
    controller->changeSeason("summer");
    cout << "Adapter automatically adjusts pressure and duration!" << endl;

    cout << "\nBENEFIT: Adapter lets us use legacy equipment without rewriting" << endl;
    cout << "existing irrigation hardware or modern greenhouse management code." << endl;

    delete controller;
    delete adapter;
    delete legacySystem;
    waitForUser();
}

// DEMO 9: COMMAND PATTERN - Staff Task Scheduling

void demonstrateCommandPattern() {
    printHeader("PATTERN 9: COMMAND PATTERN - Staff Task Management");

    cout << "\nThe Command Pattern encapsulates a request as an object, letting you" << endl;
    cout << "parameterize clients with different requests, queue requests, and log them." << endl;
    cout << "\nStaff tasks are encapsulated as commands and scheduled for execution." << endl;

    printSubheader("Creating Staff Members");

    PlantCareStaff* careStaff = new PlantCareStaff("John");
    SalesStaff* salesStaff = new SalesStaff("Sarah");

    cout << "\nPlant Care Staff: " << careStaff->getName() << endl;
    cout << "Sales Staff: " << salesStaff->getName() << endl;

    printSubheader("Creating Task Commands");

    StaffCommand* waterCmd = new WaterPlantsCommand(careStaff);
    StaffCommand* fertilizeCmd = new FertilizePlantsCommand(careStaff);
    StaffCommand* pruneCmd = new PrunePlantsCommand(careStaff);
    StaffCommand* assistCmd = new AssistCustomerCommand(salesStaff);

    cout << "\nCommands created:" << endl;
    cout << "  1. Water Plants" << endl;
    cout << "  2. Fertilize Plants" << endl;
    cout << "  3. Prune Plants" << endl;
    cout << "  4. Assist Customer" << endl;

    printSubheader("Scheduling Commands with Task Scheduler");

    TaskScheduler* scheduler = new TaskScheduler();
    scheduler->addCommand(waterCmd);
    scheduler->addCommand(fertilizeCmd);
    scheduler->addCommand(pruneCmd);
    scheduler->addCommand(assistCmd);

    cout << "\nAll tasks queued in scheduler." << endl;

    printSubheader("Executing Scheduled Tasks");

    cout << "\nExecuting all queued commands:" << endl;
    scheduler->executeCommands();

    cout << "\nBENEFIT: Command pattern decouples task requests from execution," << endl;
    cout << "enabling queuing, scheduling, and undo capabilities." << endl;

    delete scheduler;
    delete waterCmd;
    delete fertilizeCmd;
    delete pruneCmd;
    delete assistCmd;
    delete careStaff;
    delete salesStaff;
    waitForUser();
}

// DEMO 10: DECORATOR PATTERN - Enhancing Plant Products

void demonstrateDecoratorPattern(vector<Plant*>& plants) {
    printHeader("PATTERN 10: DECORATOR PATTERN - Product Customization");

    cout << "\nThe Decorator Pattern attaches additional responsibilities to an object" << endl;
    cout << "dynamically. Decorators provide a flexible alternative to subclassing." << endl;
    cout << "\nCustomers can add decorations to plants: pots, gift wrap, greeting cards." << endl;

    Plant* rose = plants[0];

    printSubheader("Scenario 1: Basic Plant (No Decorations)");

    PlantProduct* basicPlant = new BasicPlant(rose);
    basicPlant->display();

    printSubheader("Scenario 2: Plant with Decorative Pot");

    PlantProduct* plantWithPot = new DecorativePotDecorator(
        new BasicPlant(rose),
        "modern",
        "matte black"
    );
    plantWithPot->display();

    printSubheader("Scenario 3: Gift-Wrapped Plant");

    PlantProduct* giftPlant = new GiftWrappingDecorator(
        new DecorativePotDecorator(
            new BasicPlant(rose),
            "vintage",
            "terracotta"
        ),
        "elegant",
        "gold",
        true
    );
    giftPlant->display();

    printSubheader("Scenario 4: Complete Gift Package (All Decorations)");

    PlantProduct* completeGift = new BasicPlant(rose);
    completeGift = new DecorativePotDecorator(completeGift, "modern", "white");
    completeGift = new GiftWrappingDecorator(completeGift, "festive", "red", true);
    completeGift = new GreetingCardDecorator(
        completeGift,
        "birthday",
        "Happy Birthday! May your day bloom with joy!",
        "Mom",
        "The Family"
    );
    completeGift->display();

    cout << "\nBENEFIT: Decorators can be stacked dynamically, creating unlimited" << endl;
    cout << "combinations without creating subclasses for each possibility." << endl;

    delete basicPlant;
    delete plantWithPot;
    delete giftPlant;
    delete completeGift;
    waitForUser();
}

// DEMO 11: BUILDER PATTERN - Creating Plant Arrangements


void demonstrateBuilderPattern(vector<Plant*>& plants) {
    printHeader("PATTERN 11: BUILDER PATTERN - Complex Arrangements");

    cout << "\nThe Builder Pattern separates the construction of a complex object from" << endl;
    cout << "its representation, allowing the same construction process to create" << endl;
    cout << "different representations." << endl;
    cout << "\nWe create different plant arrangements using the same building process." << endl;

    // Prepare plants for arrangements
    vector<Plant*> arrangementPlants;
    arrangementPlants.push_back(plants[0]); // Rose
    arrangementPlants.push_back(plants[1]); // Lavender
    arrangementPlants.push_back(plants[6]); // Cloned Rose

    printSubheader("Building Simple Gift Arrangement");

    GiftArrangementBuilder* giftBuilder = new GiftArrangementBuilder();
    giftBuilder->setAvailablePlants(arrangementPlants);

    ArrangementDirector* director = new ArrangementDirector();
    director->setBuilder(giftBuilder);

    PlantArrangement* simpleGift = director->constructSimpleArrangement();
    simpleGift->display();

    printSubheader("Building Deluxe Gift Arrangement");

    PlantArrangement* deluxeGift = director->constructDeluxeArrangement();
    deluxeGift->display();

    printSubheader("Building Landscape Arrangement");

    LandscapeArrangementBuilder* landscapeBuilder = new LandscapeArrangementBuilder();
    landscapeBuilder->setAvailablePlants(arrangementPlants);
    landscapeBuilder->setTheme("cottage");

    director->setBuilder(landscapeBuilder);
    PlantArrangement* landscape = director->constructDeluxeArrangement();
    landscape->display();

    cout << "\nBENEFIT: Builder isolates complex construction code from business logic" << endl;
    cout << "and allows creating different representations using the same process." << endl;

    delete simpleGift;
    delete deluxeGift;
    delete landscape;
    delete giftBuilder;
    delete landscapeBuilder;
    delete director;
    waitForUser();
}

int main() {
    printHeader("Greenhouse Management System");

    cout << "\nWelcome to the NJD Films Greenhouse Management System!" << endl;
    cout << "\nThis simulation demonstrates 11 design patterns working together" << endl;
    cout << "in a realistic greenhouse environment." << endl;
    cout << "\nPatterns: Factory, Prototype, Composite, Iterator, Template," << endl;
    cout << "         Strategy, State, Adapter, Command, Decorator, Builder" << endl;

    waitForUser();

    // Storage for created objects
    vector<Plant*> plants;
    Greenhouse* greenhouse = nullptr;
    GreenhouseInventory* inventory = nullptr;

    try {
        // 1. Factory Pattern - Create plants
        plants = demonstrateFactoryPattern();

        // 2. Prototype Pattern - Clone plants
        demonstratePrototypePattern(plants);

        // 3. Composite Pattern - Organize greenhouse
        greenhouse = demonstrateCompositePattern(plants);

        // 4. Iterator Pattern - Manage inventory
        inventory = demonstrateIteratorPattern(plants);

        // 5. Template Pattern - Standardized care
        demonstrateTemplatePattern(plants);

        // 6. Strategy Pattern - Dynamic watering
        demonstrateStrategyPattern(plants);

        // 7. State Pattern - Lifecycle management
        demonstrateStatePattern(plants);

        // 8. Adapter Pattern - Legacy system integration
        demonstrateAdapterPattern(greenhouse);

        // 9. Command Pattern - Staff task scheduling
        demonstrateCommandPattern();

        // 10. Decorator Pattern - Product customization
        demonstrateDecoratorPattern(plants);

        // 11. Builder Pattern - Complex arrangements
        demonstrateBuilderPattern(plants);

        // Final Summary
        printHeader("Sim Done :) now let us relax please");

        cout << "\nFinal Stats:" << endl;
        cout << "  - Plants created: " << plants.size() << endl;
        cout << "  - Greenhouse sections: 3" << endl;
        cout << "  - Shelves: 3" << endl;
        cout << "  - Patterns demonstrated: 11" << endl;

        cout << "\nBenefits of Design Patterns:" << endl;
        cout << "  1. Code reusability and modularity" << endl;
        cout << "  2. Flexibility and extensibility" << endl;
        cout << "  3. Maintainable and testable code" << endl;
        cout << "  4. Clear separation of concerns" << endl;
        cout << "  5. Industry-standard solutions" << endl;

        cout << "\nThank you for exploring the NJD Films Greenhouse Management System!" << endl;
        printDivider();

    } catch (const exception& e) {
        cerr << "\nError during simulation: " << e.what() << endl;
    }

    // Cleanup
    for (Plant* plant : plants) {
        delete plant;
    }
    delete greenhouse;
    delete inventory;

    return 0;
}
