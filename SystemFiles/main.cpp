/**
 * @file main.cpp
 * @brief Interactive Greenhouse Management System - Design Pattern Showcase
 * @author NJD Films
 * @date 2024
 *
 * This program demonstrates all 11 design patterns used in the greenhouse system:
 * 1. Factory - Plant creation
 * 2. Prototype - Plant cloning/propagation
 * 3. Composite - Greenhouse hierarchy
 * 4. Iterator - Inventory traversal
 * 5. Template - Standardized plant care
 * 6. Strategy - Dynamic watering approaches
 * 7. State - Plant lifecycle management
 * 8. Adapter - Legacy system integration
 * 9. Command - Task scheduling and execution
 * 10. Decorator - Plant product customization
 * 11. Builder - Complex arrangement construction
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// ==================== INCLUDES ====================

// Core
#include "Plant - Abstract Base/Plant.h"

// Factory Pattern (includes plant definitions)
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
#include "Template- Plant Care/TreeCare.h"

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

// ==================== UTILITY FUNCTIONS ====================

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printHeader(const string& title) {
    cout << "\n========================================" << endl;
    cout << "  " << title << endl;
    cout << "========================================" << endl;
}

void printPatternHeader(const string& patternName) {
    cout << "\n[DESIGN PATTERN: " << patternName << "]" << endl;
    cout << string(40, '-') << endl;
}

void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int getChoice(int min, int max) {
    int choice;
    while (true) {
        cout << "\nChoice (" << min << "-" << max << "): ";
        if (cin >> choice && choice >= min && choice <= max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Try again." << endl;
    }
}

// ==================== GLOBAL DATA ====================

vector<Plant*> plants;
Greenhouse* greenhouse = nullptr;
GreenhouseInventory* inventory = nullptr;

// ==================== PATTERN DEMONSTRATIONS ====================

/**
 * @brief Demonstrates Factory Pattern
 * Creates different plant types using specialized factories
 */
void demo01_Factory() {
    clearScreen();
    printHeader("PATTERN 1: FACTORY");
    printPatternHeader("FACTORY PATTERN");

    cout << "\nThe Factory Pattern creates objects without specifying exact class types.\n";
    cout << "Each factory knows how to create its specific plant type.\n";

    // Create factories
    RoseFactory roseFactory;
    CactusFactory cactusFactory;
    SucculentFactory succulentFactory;
    LavenderFactory lavenderFactory;
    BaobabFactory baobabFactory;

    cout << "\nCreating plants using different factories...\n" << endl;

    // Create plants
    Plant* rose = roseFactory.createPlant();
    rose->setPlantId(1);
    plants.push_back(rose);
    cout << "RoseFactory      -> Created: " << rose->getType()
         << " (Price: R" << rose->getBasePrice() << ")" << endl;

    Plant* cactus = cactusFactory.createPlant();
    cactus->setPlantId(2);
    plants.push_back(cactus);
    cout << "CactusFactory    -> Created: " << cactus->getType()
         << " (Price: R" << cactus->getBasePrice() << ")" << endl;

    Plant* succulent = succulentFactory.createPlant();
    succulent->setPlantId(3);
    plants.push_back(succulent);
    cout << "SucculentFactory -> Created: " << succulent->getType()
         << " (Price: R" << succulent->getBasePrice() << ")" << endl;

    Plant* lavender = lavenderFactory.createPlant();
    lavender->setPlantId(4);
    plants.push_back(lavender);
    cout << "LavenderFactory  -> Created: " << lavender->getType()
         << " (Price: R" << lavender->getBasePrice() << ")" << endl;

    Plant* baobab = baobabFactory.createPlant();
    baobab->setPlantId(5);
    plants.push_back(baobab);
    cout << "BaobabFactory    -> Created: " << baobab->getType()
         << " (Price: R" << baobab->getBasePrice() << ")" << endl;

    cout << "\nFactory Pattern Benefits:" << endl;
    cout << "- Encapsulates object creation logic" << endl;
    cout << "- Easy to add new plant types without changing client code" << endl;
    cout << "- Each factory handles its plant's specific initialization" << endl;

    waitForEnter();
}

/**
 * @brief Demonstrates Prototype Pattern
 * Clones existing plants for propagation
 */
void demo02_Prototype() {
    clearScreen();
    printHeader("PATTERN 2: PROTOTYPE");
    printPatternHeader("PROTOTYPE PATTERN");

    cout << "\nThe Prototype Pattern creates new objects by copying existing ones.\n";
    cout << "Useful for plant propagation - cloning mature plants.\n";

    if (plants.empty()) {
        cout << "\nNo plants available! Run Factory demo first." << endl;
        waitForEnter();
        return;
    }

    Plant* original = plants[0];
    cout << "\nOriginal Plant:" << endl;
    cout << "  ID: " << original->getPlantId() << endl;
    cout << "  Type: " << original->getType() << endl;
    cout << "  Price: R" << original->getBasePrice() << endl;

    // Clone the plant
    Plant* clone = original->clone();
    clone->setPlantId(plants.size() + 1);
    clone->setHealthLevel(85);
    plants.push_back(clone);

    cout << "\nCloned Plant (Propagated):" << endl;
    cout << "  ID: " << clone->getPlantId() << endl;
    cout << "  Type: " << clone->getType() << endl;
    cout << "  Price: R" << clone->getBasePrice() << endl;
    cout << "  Health: " << clone->getHealthLevel() << "%" << endl;

    cout << "\nPrototype Pattern Benefits:" << endl;
    cout << "- Fast object creation (copying vs. creating from scratch)" << endl;
    cout << "- Maintains same characteristics as original" << endl;
    cout << "- Perfect for plant propagation simulation" << endl;

    waitForEnter();
}

/**
 * @brief Demonstrates Composite Pattern
 * Shows hierarchical greenhouse structure
 */
void demo03_Composite() {
    clearScreen();
    printHeader("PATTERN 3: COMPOSITE");
    printPatternHeader("COMPOSITE PATTERN");

    cout << "\nThe Composite Pattern creates tree structures to represent part-whole hierarchies.\n";
    cout << "The greenhouse has sections, which contain shelves, which hold plants.\n";

    // Build greenhouse structure
    greenhouse = new Greenhouse("NJD Films Greenhouse");

    GreenhouseSection* tropical = new GreenhouseSection("Tropical Section");
    GreenhouseSection* desert = new GreenhouseSection("Desert Section");

    Shelf* shelf1 = new Shelf(1);
    Shelf* shelf2 = new Shelf(2);

    // Add some plants to shelves
    if (plants.size() >= 2) {
        shelf1->add(new PlantLeaf(plants[0]));
        shelf2->add(new PlantLeaf(plants[1]));
    }

    tropical->add(shelf1);
    desert->add(shelf2);

    greenhouse->add(tropical);
    greenhouse->add(desert);

    cout << "\nGreenhouse Hierarchy:\n" << endl;
    greenhouse->display();

    cout << "\nComposite Pattern Benefits:" << endl;
    cout << "- Treats individual objects and compositions uniformly" << endl;
    cout << "- Easy to add new components to the hierarchy" << endl;
    cout << "- Simplifies client code (single interface for all)" << endl;

    waitForEnter();
}

/**
 * @brief Demonstrates Iterator Pattern
 * Traverses plant inventory without exposing internal structure
 */
void demo04_Iterator() {
    clearScreen();
    printHeader("PATTERN 4: ITERATOR");
    printPatternHeader("ITERATOR PATTERN");

    cout << "\nThe Iterator Pattern provides a way to access elements sequentially\n";
    cout << "without exposing the underlying collection structure.\n";

    // Create inventory
    inventory = new GreenhouseInventory();
    for (Plant* plant : plants) {
        inventory->addPlant(plant);
    }

    cout << "\nIterating through inventory:\n" << endl;
    cout << left << setw(5) << "ID" << setw(15) << "Type"
         << setw(12) << "Price" << setw(10) << "Health" << endl;
    cout << string(42, '-') << endl;

    PlantIterator* iterator = inventory->createIterator();
    iterator->first();

    while (!iterator->isDone()) {
        Plant* plant = iterator->currentItem();
        cout << left << setw(5) << plant->getPlantId()
             << setw(15) << plant->getType()
             << "R" << setw(11) << fixed << setprecision(2) << plant->getBasePrice()
             << setw(10) << plant->getHealthLevel() << "%"
             << endl;
        iterator->next();
    }

    delete iterator;

    cout << "\nIterator Pattern Benefits:" << endl;
    cout << "- Hides internal collection structure" << endl;
    cout << "- Multiple iterators can traverse independently" << endl;
    cout << "- Uniform interface for different collection types" << endl;

    waitForEnter();
}

/**
 * @brief Demonstrates Template Pattern
 * Shows standardized plant care routines with variations
 */
void demo05_Template() {
    clearScreen();
    printHeader("PATTERN 5: TEMPLATE");
    printPatternHeader("TEMPLATE PATTERN");

    cout << "\nThe Template Pattern defines a skeleton algorithm in a base class,\n";
    cout << "allowing subclasses to override specific steps without changing structure.\n";

    cout << "\nAvailable Care Routines:" << endl;
    cout << "1. Rose Care (frequent watering + fertilizing)" << endl;
    cout << "2. Succulent Care (minimal water + inspection)" << endl;
    cout << "3. Tree Care (moderate water + pruning)" << endl;

    int choice = getChoice(1, 3);

    PlantCareRoutine* routine = nullptr;
    string type;

    if (choice == 1) {
        routine = new RoseCare();
        type = "ROSE CARE";
    } else if (choice == 2) {
        routine = new SucculentCare();
        type = "SUCCULENT CARE";
    } else {
        routine = new TreeCare();
        type = "TREE CARE";
    }

    cout << "\nExecuting " << type << " Routine:\n" << endl;
    routine->careForPlant();

    cout << "\nTemplate Pattern Benefits:" << endl;
    cout << "- Defines common algorithm structure" << endl;
    cout << "- Allows customization of specific steps" << endl;
    cout << "- Reduces code duplication across similar algorithms" << endl;

    delete routine;
    waitForEnter();
}

/**
 * @brief Demonstrates Strategy Pattern
 * Shows dynamic watering strategy selection
 */
void demo06_Strategy() {
    clearScreen();
    printHeader("PATTERN 6: STRATEGY");
    printPatternHeader("STRATEGY PATTERN");

    cout << "\nThe Strategy Pattern defines a family of algorithms,\n";
    cout << "encapsulates each one, and makes them interchangeable.\n";

    if (plants.empty()) {
        cout << "\nNo plants available!" << endl;
        waitForEnter();
        return;
    }

    cout << "\nWatering Strategies:" << endl;
    cout << "1. Frequent Watering (daily, high volume)" << endl;
    cout << "2. Moderate Watering (every 3-5 days)" << endl;
    cout << "3. Minimal Watering (weekly, low volume)" << endl;

    int choice = getChoice(1, 3);

    PlantCareStrategy* strategy = nullptr;
    string type;

    if (choice == 1) {
        strategy = new FrequentWatering();
        type = "FREQUENT WATERING";
    } else if (choice == 2) {
        strategy = new ModerateWatering();
        type = "MODERATE WATERING";
    } else {
        strategy = new MinimalWatering();
        type = "MINIMAL WATERING";
    }

    Plant* plant = plants[0];
    PlantCareContext context(plant);
    context.setStrategy(strategy);

    cout << "\nApplying " << type << " to " << plant->getType() << ":\n" << endl;
    context.executeCare();

    cout << "\nStrategy Pattern Benefits:" << endl;
    cout << "- Algorithms can be selected at runtime" << endl;
    cout << "- Easy to add new strategies without modifying context" << endl;
    cout << "- Eliminates conditional statements for strategy selection" << endl;

    delete strategy;
    waitForEnter();
}

/**
 * @brief Demonstrates State Pattern
 * Shows plant lifecycle state transitions
 */
void demo07_State() {
    clearScreen();
    printHeader("PATTERN 7: STATE");
    printPatternHeader("STATE PATTERN");

    cout << "\nThe State Pattern allows an object to alter its behavior\n";
    cout << "when its internal state changes (appears to change its class).\n";

    if (plants.empty()) {
        cout << "\nNo plants available!" << endl;
        waitForEnter();
        return;
    }

    Plant* plant = plants[0];
    PlantContext* context = new PlantContext(plant);

    cout << "\nPlant: " << plant->getType() << endl;
    cout << "\nLifecycle States:" << endl;
    cout << "  Seedling -> Growing -> Mature -> Flowering -> Dormant\n" << endl;

    // Set initial state
    context->setState(new SeedlingState());
    cout << "Current State: SEEDLING" << endl;
    context->water();
    context->checkHealth();

    cout << "\n[Transitioning to Growing...]" << endl;
    context->setState(new GrowingState());
    cout << "Current State: GROWING" << endl;
    context->water();
    context->fertilize();

    cout << "\n[Transitioning to Mature...]" << endl;
    context->setState(new MatureState());
    cout << "Current State: MATURE" << endl;
    context->water();
    context->checkHealth();

    cout << "\nState Pattern Benefits:" << endl;
    cout << "- Localizes state-specific behavior" << endl;
    cout << "- Makes state transitions explicit" << endl;
    cout << "- Eliminates large conditional statements" << endl;

    delete context;
    waitForEnter();
}

/**
 * @brief Demonstrates Adapter Pattern
 * Shows legacy system integration
 */
void demo08_Adapter() {
    clearScreen();
    printHeader("PATTERN 8: ADAPTER");
    printPatternHeader("ADAPTER PATTERN");

    cout << "\nThe Adapter Pattern converts the interface of a class into another\n";
    cout << "interface clients expect, allowing incompatible systems to work together.\n";

    cout << "\nScenario: Integrating legacy irrigation system with modern greenhouse.\n" << endl;

    // Create legacy system
    LegacyIrrigationSystem* legacy = new LegacyIrrigationSystem();

    // Create adapter
    ModernWateringSystem* adapter = new WateringAdapter(legacy);

    // Create simple greenhouse component for controller
    Greenhouse* tempGreenhouse = new Greenhouse("Demo Greenhouse");

    // Create controller (requires 2 parameters)
    GreenhouseController controller(adapter, tempGreenhouse);

    cout << "Using adapted legacy system through modern interface:\n" << endl;
    controller.waterGreenhouse();

    cout << "\nAdapter Pattern Benefits:" << endl;
    cout << "- Reuses existing legacy code" << endl;
    cout << "- Provides clean modern interface" << endl;
    cout << "- Isolates legacy system complexity" << endl;

    delete tempGreenhouse;
    delete adapter;
    delete legacy;
    waitForEnter();
}

/**
 * @brief Demonstrates Command Pattern
 * Shows task scheduling and execution
 */
void demo09_Command() {
    clearScreen();
    printHeader("PATTERN 9: COMMAND");
    printPatternHeader("COMMAND PATTERN");

    cout << "\nThe Command Pattern encapsulates a request as an object,\n";
    cout << "allowing parameterization, queuing, logging, and undo operations.\n";

    if (plants.empty()) {
        cout << "\nNo plants available!" << endl;
        waitForEnter();
        return;
    }

    // Create staff members
    PlantCareStaff careStaff("Alice");
    SalesStaff salesStaff("Bob");

    // Create commands (commands don't take plant lists)
    StaffCommand* waterCmd = new WaterPlantsCommand(&careStaff);
    StaffCommand* fertilizeCmd = new FertilizePlantsCommand(&careStaff);
    StaffCommand* pruneCmd = new PrunePlantsCommand(&careStaff);
    StaffCommand* assistCmd = new AssistCustomerCommand(&salesStaff);

    // Create task scheduler
    TaskScheduler scheduler;

    cout << "\nScheduling tasks for the day:\n" << endl;

    scheduler.addCommand(waterCmd);
    cout << "- Added: Water Plants" << endl;

    scheduler.addCommand(fertilizeCmd);
    cout << "- Added: Fertilize Plants" << endl;

    scheduler.addCommand(pruneCmd);
    cout << "- Added: Prune Plants" << endl;

    scheduler.addCommand(assistCmd);
    cout << "- Added: Assist Customer" << endl;

    cout << "\nExecuting all scheduled tasks:\n" << endl;
    scheduler.executeCommands();

    cout << "\nCommand Pattern Benefits:" << endl;
    cout << "- Decouples sender from receiver" << endl;
    cout << "- Easy to add new commands" << endl;
    cout << "- Supports queuing, logging, and undo" << endl;

    delete waterCmd;
    delete fertilizeCmd;
    delete pruneCmd;
    delete assistCmd;
    waitForEnter();
}

/**
 * @brief Demonstrates Decorator Pattern
 * Shows dynamic feature addition to plant products
 */
void demo10_Decorator() {
    clearScreen();
    printHeader("PATTERN 10: DECORATOR");
    printPatternHeader("DECORATOR PATTERN");

    cout << "\nThe Decorator Pattern attaches additional responsibilities to an object\n";
    cout << "dynamically, providing a flexible alternative to subclassing.\n";

    if (plants.empty()) {
        cout << "\nNo plants available!" << endl;
        waitForEnter();
        return;
    }

    Plant* plant = plants[0];

    cout << "\nCreating customized plant product:\n" << endl;

    // Start with basic plant
    PlantProduct* product = new BasicPlant(plant);
    cout << "1. Basic Plant: " << product->getDescription() << endl;
    cout << "   Price: R" << fixed << setprecision(2) << product->getPrice() << endl;

    // Add decorative pot
    product = new DecorativePotDecorator(product, "ceramic", "white");
    cout << "\n2. + Decorative Pot: " << product->getDescription() << endl;
    cout << "   Price: R" << product->getPrice() << endl;

    // Add gift wrapping
    product = new GiftWrappingDecorator(product, "elegant", "gold", true);
    cout << "\n3. + Gift Wrapping: " << product->getDescription() << endl;
    cout << "   Price: R" << product->getPrice() << endl;

    // Add greeting card
    product = new GreetingCardDecorator(product, "birthday", "Happy Birthday!", "Mom", "Sarah");
    cout << "\n4. + Greeting Card: " << product->getDescription() << endl;
    cout << "   Price: R" << product->getPrice() << endl;

    cout << "\nFinal product:" << endl;
    product->display();

    cout << "\nDecorator Pattern Benefits:" << endl;
    cout << "- Adds responsibilities without modifying original class" << endl;
    cout << "- More flexible than static inheritance" << endl;
    cout << "- Decorators can be stacked/combined" << endl;

    delete product;
    waitForEnter();
}

/**
 * @brief Demonstrates Builder Pattern
 * Shows complex object construction
 */
void demo11_Builder() {
    clearScreen();
    printHeader("PATTERN 11: BUILDER");
    printPatternHeader("BUILDER PATTERN");

    cout << "\nThe Builder Pattern separates the construction of a complex object\n";
    cout << "from its representation, allowing the same process to create different types.\n";

    if (plants.size() < 3) {
        cout << "\nNeed at least 3 plants! Run Factory demo first." << endl;
        waitForEnter();
        return;
    }

    cout << "\nArrangement Types:" << endl;
    cout << "1. Gift Arrangement (romantic roses in decorative basket)" << endl;
    cout << "2. Landscape Arrangement (outdoor garden mix)" << endl;

    int choice = getChoice(1, 2);

    PlantArrangementBuilder* builder = nullptr;
    ArrangementDirector director;

    if (choice == 1) {
        builder = new GiftArrangementBuilder();
        cout << "\nBuilding GIFT ARRANGEMENT...\n" << endl;
    } else {
        builder = new LandscapeArrangementBuilder();
        cout << "\nBuilding LANDSCAPE ARRANGEMENT...\n" << endl;
    }

    // Set available plants
    if (choice == 1) {
        GiftArrangementBuilder* giftBuilder = static_cast<GiftArrangementBuilder*>(builder);
        giftBuilder->setAvailablePlants(plants);
    } else {
        LandscapeArrangementBuilder* landscapeBuilder = static_cast<LandscapeArrangementBuilder*>(builder);
        landscapeBuilder->setAvailablePlants(plants);
    }

    // Use director to construct
    director.setBuilder(builder);

    cout << "Choose arrangement complexity:" << endl;
    cout << "1. Simple Arrangement" << endl;
    cout << "2. Deluxe Arrangement" << endl;

    int complexity = getChoice(1, 2);

    PlantArrangement* arrangement = nullptr;
    if (complexity == 1) {
        arrangement = director.constructSimpleArrangement();
    } else {
        arrangement = director.constructDeluxeArrangement();
    }

    cout << "\nArrangement created successfully!\n" << endl;
    arrangement->display();

    cout << "\nBuilder Pattern Benefits:" << endl;
    cout << "- Separates construction from representation" << endl;
    cout << "- Allows step-by-step construction" << endl;
    cout << "- Same construction process creates different products" << endl;

    delete arrangement;
    delete builder;
    waitForEnter();
}

// ==================== MAIN MENU ====================

void displayMainMenu() {
    clearScreen();
    printHeader("NJD FILMS GREENHOUSE");
    cout << "\nDesign Patterns Demonstration System" << endl;
    cout << "\nCreational Patterns:" << endl;
    cout << " 1. Factory Pattern      - Plant creation" << endl;
    cout << " 2. Prototype Pattern    - Plant cloning" << endl;
    cout << " 3. Builder Pattern      - Arrangement construction" << endl;

    cout << "\nStructural Patterns:" << endl;
    cout << " 4. Composite Pattern    - Greenhouse hierarchy" << endl;
    cout << " 5. Decorator Pattern    - Product customization" << endl;
    cout << " 6. Adapter Pattern      - Legacy system integration" << endl;

    cout << "\nBehavioral Patterns:" << endl;
    cout << " 7. Iterator Pattern     - Inventory traversal" << endl;
    cout << " 8. Template Pattern     - Standardized care routines" << endl;
    cout << " 9. Strategy Pattern     - Watering strategies" << endl;
    cout << "10. State Pattern        - Lifecycle management" << endl;
    cout << "11. Command Pattern      - Task scheduling" << endl;

    cout << "\n 0. Exit" << endl;
}

// ==================== MAIN ====================

int main() {
    cout << "================================================" << endl;
    cout << "   NJD FILMS GREENHOUSE MANAGEMENT SYSTEM" << endl;
    cout << "   COS 214 Project - Design Patterns Showcase" << endl;
    cout << "================================================" << endl;

    waitForEnter();

    while (true) {
        displayMainMenu();
        int choice = getChoice(0, 11);

        switch (choice) {
            case 1:  demo01_Factory(); break;
            case 2:  demo02_Prototype(); break;
            case 3:  demo11_Builder(); break;
            case 4:  demo03_Composite(); break;
            case 5:  demo10_Decorator(); break;
            case 6:  demo08_Adapter(); break;
            case 7:  demo04_Iterator(); break;
            case 8:  demo05_Template(); break;
            case 9:  demo06_Strategy(); break;
            case 10: demo07_State(); break;
            case 11: demo09_Command(); break;
            case 0:
                cout << "\nThank you for using NJD Films Greenhouse System!" << endl;

                // Cleanup
                for (Plant* plant : plants) delete plant;
                delete greenhouse;
                delete inventory;

                return 0;
        }
    }

    return 0;
}
