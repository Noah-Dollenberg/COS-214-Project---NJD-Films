/**
 * Interactive Greenhouse Management System
 *
 * COS 214 Project - NJD Films
 *
 * This interactive demo lets users experience the greenhouse system as either:
 * - STAFF MEMBER: Manage plants, propagate, care for inventory, view store layout
 * - CUSTOMER: Browse plants, purchase, create arrangements, customize with decorations
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
#include <memory>

using namespace std;

// Plant base class
#include "Plant - Abstract Base/Plant.h"

// Factory Pattern
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
    cout << "\n";
    cout << "================================================" << endl;
    cout << "  " << title << endl;
    cout << "================================================" << endl;
}

void printSubheader(const string& title) {
    cout << "\n--- " << title << " ---" << endl;
}

void waitForUser() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int getMenuChoice(int min, int max) {
    int choice;
    while (true) {
        cout << "\nEnter your choice (" << min << "-" << max << "): ";
        if (cin >> choice && choice >= min && choice <= max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please try again." << endl;
    }
}

// ==================== GLOBAL STATE ====================

struct GreenhouseState {
    Greenhouse* greenhouse;
    GreenhouseInventory* inventory;
    vector<Plant*> allPlants;
    vector<PlantProduct*> customerCart;
    double customerBalance;
    string currentSeason;

    GreenhouseState() : greenhouse(nullptr), inventory(nullptr),
                        customerBalance(5000.0), currentSeason("spring") {}

    ~GreenhouseState() {
        delete greenhouse;
        delete inventory;
        for (auto plant : allPlants) delete plant;
        for (auto product : customerCart) delete product;
    }
};

GreenhouseState* state = nullptr;

// ==================== INITIALIZATION ====================

void initializeGreenhouse() {
    printHeader("GREENHOUSE SYSTEM INITIALIZATION");
    cout << "\nSetting up greenhouse structure and initial inventory..." << endl;

    // Create greenhouse structure using Composite Pattern
    state->greenhouse = new Greenhouse("NJD Films Greenhouse");

    GreenhouseSection* tropicalSection = new GreenhouseSection("Tropical Section");
    GreenhouseSection* desertSection = new GreenhouseSection("Desert Section");
    GreenhouseSection* herbSection = new GreenhouseSection("Herb & Flower Section");

    Shelf* tropicalShelf1 = new Shelf(1);
    Shelf* tropicalShelf2 = new Shelf(2);
    Shelf* desertShelf1 = new Shelf(3);
    Shelf* desertShelf2 = new Shelf(4);
    Shelf* herbShelf1 = new Shelf(5);

    // Create initial plants using Factory Pattern
    RoseFactory roseFactory;
    CactusFactory cactusFactory;
    SucculentFactory succulentFactory;
    LavenderFactory lavenderFactory;
    BaobabFactory baobabFactory;

    // Create plants
    for (int i = 1; i <= 3; i++) {
        Plant* rose = roseFactory.createPlant();
        rose->setPlantId(state->allPlants.size() + 1);
        rose->setReadyForSale(true);
        state->allPlants.push_back(rose);
        tropicalShelf1->add(new PlantLeaf(rose));
    }

    for (int i = 1; i <= 4; i++) {
        Plant* cactus = cactusFactory.createPlant();
        cactus->setPlantId(state->allPlants.size() + 1);
        cactus->setReadyForSale(true);
        state->allPlants.push_back(cactus);
        desertShelf1->add(new PlantLeaf(cactus));
    }

    for (int i = 1; i <= 3; i++) {
        Plant* succulent = succulentFactory.createPlant();
        succulent->setPlantId(state->allPlants.size() + 1);
        succulent->setReadyForSale(true);
        state->allPlants.push_back(succulent);
        desertShelf2->add(new PlantLeaf(succulent));
    }

    for (int i = 1; i <= 2; i++) {
        Plant* lavender = lavenderFactory.createPlant();
        lavender->setPlantId(state->allPlants.size() + 1);
        lavender->setReadyForSale(true);
        state->allPlants.push_back(lavender);
        herbShelf1->add(new PlantLeaf(lavender));
    }

    Plant* baobab = baobabFactory.createPlant();
    baobab->setPlantId(state->allPlants.size() + 1);
    baobab->setReadyForSale(true);
    state->allPlants.push_back(baobab);
    tropicalShelf2->add(new PlantLeaf(baobab));

    // Build structure
    tropicalSection->add(tropicalShelf1);
    tropicalSection->add(tropicalShelf2);
    desertSection->add(desertShelf1);
    desertSection->add(desertShelf2);
    herbSection->add(herbShelf1);

    state->greenhouse->add(tropicalSection);
    state->greenhouse->add(desertSection);
    state->greenhouse->add(herbSection);

    // Create inventory using Iterator Pattern
    state->inventory = new GreenhouseInventory();
    for (auto plant : state->allPlants) {
        state->inventory->addPlant(plant);
    }

    cout << "\nGreenhouse initialized successfully!" << endl;
    cout << "Total plants in inventory: " << state->allPlants.size() << endl;
    waitForUser();
}

// ==================== STAFF FUNCTIONS ====================

void staffViewStoreLayout() {
    clearScreen();
    printHeader("GREENHOUSE STORE LAYOUT");
    cout << "\nComposite Pattern: Hierarchical greenhouse structure\n" << endl;
    state->greenhouse->display();
    waitForUser();
}

void staffViewInventory() {
    clearScreen();
    printHeader("PLANT INVENTORY");
    cout << "\nIterator Pattern: Traversing plant collection\n" << endl;

    PlantIterator* iterator = state->inventory->createIterator();
    int count = 0;

    cout << left << setw(5) << "ID" << setw(15) << "Species"
         << setw(12) << "Price (R)" << setw(12) << "Health"
         << setw(15) << "Ready?" << endl;
    cout << string(65, '-') << endl;

    iterator->first();
    while (!iterator->isDone()) {
        Plant* plant = iterator->currentItem();
        count++;
        cout << left << setw(5) << plant->getPlantId()
             << setw(15) << plant->getSpecies()
             << "R" << setw(11) << fixed << setprecision(2) << plant->getBasePrice()
             << setw(12) << plant->getHealthLevel() << "%"
             << setw(15) << (plant->isReadyForSale() ? "YES" : "NO")
             << endl;
        iterator->next();
    }

    cout << "\nTotal plants: " << count << endl;
    delete iterator;
    waitForUser();
}

void staffPropagatePlant() {
    clearScreen();
    printHeader("PLANT PROPAGATION");
    cout << "\nPrototype Pattern: Cloning plants for propagation\n" << endl;

    staffViewInventory();

    cout << "\nEnter the Plant ID to propagate: ";
    int id;
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Plant* original = nullptr;
    for (auto plant : state->allPlants) {
        if (plant->getPlantId() == id) {
            original = plant;
            break;
        }
    }

    if (!original) {
        cout << "\nPlant not found!" << endl;
        waitForUser();
        return;
    }

    // Clone using Prototype Pattern
    Plant* clone = original->clone();
    clone->setPlantId(state->allPlants.size() + 1);
    clone->setReadyForSale(false); // New clones need time to mature
    clone->setHealthLevel(80); // Start with good health

    state->allPlants.push_back(clone);
    state->inventory->addPlant(clone);

    cout << "\n[PROTOTYPE PATTERN]" << endl;
    cout << "Successfully propagated " << original->getSpecies() << "!" << endl;
    cout << "Original ID: " << original->getPlantId() << endl;
    cout << "Clone ID: " << clone->getPlantId() << endl;
    cout << "\nThe clone will be ready for sale after maturation." << endl;

    waitForUser();
}

void staffCarePlants() {
    clearScreen();
    printHeader("PLANT CARE ROUTINE");
    cout << "\nTemplate Pattern: Standardized care procedures\n" << endl;

    cout << "Select care routine:" << endl;
    cout << "1. Rose Care (Frequent watering + fertilizing)" << endl;
    cout << "2. Succulent Care (Minimal water + inspection)" << endl;
    cout << "3. Tree Care (Moderate water + pruning)" << endl;

    int choice = getMenuChoice(1, 3);

    PlantCareRoutine* routine = nullptr;
    string routineType;

    if (choice == 1) {
        routine = new RoseCare();
        routineType = "Rose Care";
    } else if (choice == 2) {
        routine = new SucculentCare();
        routineType = "Succulent Care";
    } else {
        routine = new TreeCare();
        routineType = "Tree Care";
    }

    cout << "\n[TEMPLATE PATTERN: " << routineType << "]" << endl;
    routine->careForPlant();

    cout << "\nCare routine completed successfully!" << endl;

    delete routine;
    waitForUser();
}

void staffWaterPlants() {
    clearScreen();
    printHeader("WATERING PLANTS");
    cout << "\nStrategy Pattern: Dynamic watering strategies\n" << endl;

    cout << "Select watering strategy:" << endl;
    cout << "1. Frequent Watering (Daily, high water)" << endl;
    cout << "2. Moderate Watering (Every 3-5 days)" << endl;
    cout << "3. Minimal Watering (Weekly, low water)" << endl;

    int choice = getMenuChoice(1, 3);

    PlantCareStrategy* strategy = nullptr;
    string strategyType;

    if (choice == 1) {
        strategy = new FrequentWatering();
        strategyType = "Frequent Watering";
    } else if (choice == 2) {
        strategy = new ModerateWatering();
        strategyType = "Moderate Watering";
    } else {
        strategy = new MinimalWatering();
        strategyType = "Minimal Watering";
    }

    // Use first plant as example for strategy
    Plant* examplePlant = state->allPlants[0];
    PlantCareContext context(examplePlant);
    context.setStrategy(strategy);

    cout << "\n[STRATEGY PATTERN: " << strategyType << "]" << endl;
    cout << "Applying strategy to plant: " << examplePlant->getSpecies() << endl;
    context.executeCare();

    cout << "\nWatering completed successfully!" << endl;
    cout << "Strategy applied to plants in greenhouse." << endl;

    delete strategy;
    waitForUser();
}

void staffManageLifecycle() {
    clearScreen();
    printHeader("PLANT LIFECYCLE MANAGEMENT");
    cout << "\nState Pattern: Managing plant growth states\n" << endl;

    if (state->allPlants.empty()) {
        cout << "No plants available!" << endl;
        waitForUser();
        return;
    }

    Plant* plant = state->allPlants[0];
    PlantContext* context = new PlantContext(plant);

    cout << "Demonstrating lifecycle for: " << plant->getSpecies() << " (ID: " << plant->getPlantId() << ")\n" << endl;

    // Progress through states
    cout << "1. SEEDLING STATE" << endl;
    context->setState(new SeedlingState());
    cout << "   Current: " << context->getCurrentState()->getStateName() << endl;
    context->water();

    cout << "\n2. GROWING STATE" << endl;
    context->setState(new GrowingState());
    cout << "   Current: " << context->getCurrentState()->getStateName() << endl;
    context->fertilize();

    cout << "\n3. MATURE STATE" << endl;
    context->setState(new MatureState());
    cout << "   Current: " << context->getCurrentState()->getStateName() << endl;
    context->checkHealth();

    cout << "\n4. FLOWERING STATE" << endl;
    context->setState(new FloweringState());
    cout << "   Current: " << context->getCurrentState()->getStateName() << endl;
    cout << "   Plant is now in peak condition!" << endl;

    cout << "\n[STATE PATTERN]" << endl;
    cout << "Plant has progressed through all lifecycle states successfully." << endl;

    delete context;
    waitForUser();
}

void staffUseAdapter() {
    clearScreen();
    printHeader("LEGACY WATERING SYSTEM");
    cout << "\nAdapter Pattern: Integrating old irrigation system\n" << endl;

    LegacyIrrigationSystem* legacySystem = new LegacyIrrigationSystem();
    ModernWateringSystem* modernSystem = new WateringAdapter(legacySystem);

    GreenhouseController controller(modernSystem, state->greenhouse);

    cout << "\n[ADAPTER PATTERN]" << endl;
    cout << "Using legacy irrigation system through modern interface..." << endl;

    controller.performDailyMaintenance();

    cout << "\nAdapter successfully integrated legacy system!" << endl;

    delete modernSystem;
    delete legacySystem;
    waitForUser();
}

void staffScheduleTasks() {
    clearScreen();
    printHeader("STAFF TASK SCHEDULING");
    cout << "\nCommand Pattern: Queuing and executing staff tasks\n" << endl;

    TaskScheduler scheduler;

    PlantCareStaff* careStaff = new PlantCareStaff("John");
    SalesStaff* salesStaff = new SalesStaff("Sarah");

    cout << "Creating staff task schedule...\n" << endl;

    // Create commands
    WaterPlantsCommand* waterCmd = new WaterPlantsCommand(careStaff);
    FertilizePlantsCommand* fertilizeCmd = new FertilizePlantsCommand(careStaff);
    PrunePlantsCommand* pruneCmd = new PrunePlantsCommand(careStaff);

    scheduler.addCommand(waterCmd);
    scheduler.addCommand(fertilizeCmd);
    scheduler.addCommand(pruneCmd);

    cout << "[COMMAND PATTERN]" << endl;
    cout << "Executing scheduled tasks...\n" << endl;
    scheduler.executeCommands();

    cout << "\nAll tasks completed successfully!" << endl;

    delete careStaff;
    delete salesStaff;
    waitForUser();
}

void staffMenu() {
    while (true) {
        clearScreen();
        printHeader("STAFF MEMBER PORTAL");
        cout << "\nWelcome, Staff Member! Current Season: " << state->currentSeason << endl;
        cout << "\n1. View Store Layout (Composite)" << endl;
        cout << "2. View Inventory (Iterator)" << endl;
        cout << "3. Propagate Plant (Prototype)" << endl;
        cout << "4. Perform Care Routine (Template)" << endl;
        cout << "5. Water Plants (Strategy)" << endl;
        cout << "6. Manage Plant Lifecycle (State)" << endl;
        cout << "7. Use Legacy Watering System (Adapter)" << endl;
        cout << "8. Schedule Staff Tasks (Command)" << endl;
        cout << "9. Back to Main Menu" << endl;

        int choice = getMenuChoice(1, 9);

        switch (choice) {
            case 1: staffViewStoreLayout(); break;
            case 2: staffViewInventory(); break;
            case 3: staffPropagatePlant(); break;
            case 4: staffCarePlants(); break;
            case 5: staffWaterPlants(); break;
            case 6: staffManageLifecycle(); break;
            case 7: staffUseAdapter(); break;
            case 8: staffScheduleTasks(); break;
            case 9: return;
        }
    }
}

// ==================== CUSTOMER FUNCTIONS ====================

void customerBrowsePlants() {
    clearScreen();
    printHeader("BROWSE AVAILABLE PLANTS");

    cout << "\nPlants ready for sale:\n" << endl;
    cout << left << setw(5) << "ID" << setw(15) << "Species"
         << setw(12) << "Price (R)" << setw(12) << "Health" << endl;
    cout << string(50, '-') << endl;

    for (auto plant : state->allPlants) {
        if (plant->isReadyForSale()) {
            cout << left << setw(5) << plant->getPlantId()
                 << setw(15) << plant->getSpecies()
                 << "R" << setw(11) << fixed << setprecision(2) << plant->getBasePrice()
                 << setw(12) << plant->getHealthLevel() << "%"
                 << endl;
        }
    }

    cout << "\nYour balance: R" << fixed << setprecision(2) << state->customerBalance << endl;
    waitForUser();
}

void customerBuyPlant() {
    clearScreen();
    printHeader("PURCHASE PLANT");

    customerBrowsePlants();

    cout << "\nEnter Plant ID to purchase (0 to cancel): ";
    int id;
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (id == 0) return;

    Plant* plant = nullptr;
    for (auto p : state->allPlants) {
        if (p->getPlantId() == id && p->isReadyForSale()) {
            plant = p;
            break;
        }
    }

    if (!plant) {
        cout << "\nPlant not found or not available for sale!" << endl;
        waitForUser();
        return;
    }

    if (plant->getBasePrice() > state->customerBalance) {
        cout << "\nInsufficient funds!" << endl;
        waitForUser();
        return;
    }

    // Create basic plant product
    PlantProduct* product = new BasicPlant(plant);

    cout << "\nWould you like to add decorations?" << endl;
    cout << "1. Just the plant (R0)" << endl;
    cout << "2. Add Decorative Pot (+R50)" << endl;
    cout << "3. Add Gift Wrapping (+R25)" << endl;
    cout << "4. Add Both Pot & Wrapping (+R75)" << endl;

    int choice = getMenuChoice(1, 4);

    cout << "\n[DECORATOR PATTERN]" << endl;

    if (choice == 2 || choice == 4) {
        product = new DecorativePotDecorator(product);
        cout << "Added: Decorative Pot" << endl;
    }
    if (choice == 3 || choice == 4) {
        product = new GiftWrappingDecorator(product);
        cout << "Added: Gift Wrapping" << endl;
    }

    state->customerCart.push_back(product);
    state->customerBalance -= product->getPrice();

    cout << "\nPurchase successful!" << endl;
    cout << "Total cost: R" << fixed << setprecision(2) << product->getPrice() << endl;
    cout << "Remaining balance: R" << state->customerBalance << endl;

    waitForUser();
}

void customerCreateArrangement() {
    clearScreen();
    printHeader("CREATE PLANT ARRANGEMENT");
    cout << "\nBuilder Pattern: Building custom arrangements\n" << endl;

    cout << "Select arrangement type:" << endl;
    cout << "1. Gift Arrangement (Romantic theme with roses)" << endl;
    cout << "2. Landscape Arrangement (Outdoor garden theme)" << endl;

    int choice = getMenuChoice(1, 2);

    ArrangementDirector director;
    PlantArrangement* arrangement = nullptr;

    if (choice == 1) {
        GiftArrangementBuilder* builder = new GiftArrangementBuilder();
        director.setBuilder(builder);
        cout << "\n[BUILDER PATTERN: Gift Arrangement]" << endl;
        arrangement = director.constructDeluxeArrangement();
        delete builder;
    } else {
        LandscapeArrangementBuilder* builder = new LandscapeArrangementBuilder();
        director.setBuilder(builder);
        cout << "\n[BUILDER PATTERN: Landscape Arrangement]" << endl;
        arrangement = director.constructSimpleArrangement();
        delete builder;
    }

    cout << "\nArrangement created successfully!" << endl;
    arrangement->display();

    double cost = arrangement->getTotalPrice();

    if (cost > state->customerBalance) {
        cout << "\nInsufficient funds! Arrangement not purchased." << endl;
        delete arrangement;
    } else {
        state->customerBalance -= cost;
        cout << "\nPurchase successful!" << endl;
        cout << "Remaining balance: R" << fixed << setprecision(2) << state->customerBalance << endl;
        delete arrangement;
    }

    waitForUser();
}

void customerViewCart() {
    clearScreen();
    printHeader("YOUR SHOPPING CART");

    if (state->customerCart.empty()) {
        cout << "\nYour cart is empty." << endl;
    } else {
        cout << "\nItems in cart:\n" << endl;
        double total = 0.0;
        int count = 1;

        for (auto product : state->customerCart) {
            cout << count++ << ". ";
            product->display();
            cout << "   Price: R" << fixed << setprecision(2) << product->getPrice() << "\n" << endl;
            total += product->getPrice();
        }

        cout << "Total spent: R" << fixed << setprecision(2) << total << endl;
    }

    cout << "Current balance: R" << fixed << setprecision(2) << state->customerBalance << endl;
    waitForUser();
}

void customerMenu() {
    while (true) {
        clearScreen();
        printHeader("CUSTOMER PORTAL");
        cout << "\nWelcome to NJD Films Greenhouse!" << endl;
        cout << "Your balance: R" << fixed << setprecision(2) << state->customerBalance << endl;
        cout << "\n1. Browse Plants" << endl;
        cout << "2. Purchase Plant (with Decorations)" << endl;
        cout << "3. Create Custom Arrangement (Builder)" << endl;
        cout << "4. View Shopping Cart" << endl;
        cout << "5. Back to Main Menu" << endl;

        int choice = getMenuChoice(1, 5);

        switch (choice) {
            case 1: customerBrowsePlants(); break;
            case 2: customerBuyPlant(); break;
            case 3: customerCreateArrangement(); break;
            case 4: customerViewCart(); break;
            case 5: return;
        }
    }
}

// ==================== MAIN MENU ====================

void mainMenu() {
    while (true) {
        clearScreen();
        printHeader("NJD FILMS GREENHOUSE MANAGEMENT SYSTEM");
        cout << "\nInteractive Demo - All 11 Design Patterns" << endl;
        cout << "\nSelect your role:" << endl;
        cout << "1. Staff Member (Manage greenhouse operations)" << endl;
        cout << "2. Customer (Browse and purchase plants)" << endl;
        cout << "3. Exit" << endl;

        int choice = getMenuChoice(1, 3);

        switch (choice) {
            case 1:
                staffMenu();
                break;
            case 2:
                customerMenu();
                break;
            case 3:
                cout << "\nThank you for using NJD Films Greenhouse System!" << endl;
                return;
        }
    }
}

// ==================== MAIN ====================

int main() {
    state = new GreenhouseState();

    try {
        initializeGreenhouse();
        mainMenu();
    } catch (const exception& e) {
        cerr << "\nError: " << e.what() << endl;
    }

    delete state;

    return 0;
}
