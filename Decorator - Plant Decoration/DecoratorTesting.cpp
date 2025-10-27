#include <iomanip>
#include <iostream>
#include "../Plant - Abstract Base/Plant.h"
#include "../Plant - Abstract Base/Rose.h"
#include "BasicPlant.h"
#include "DecorativePotDecorator.h"
#include "GiftWrappingDecorator.h"
#include "GreetingCardDecorator.h"

int main() {
    std::cout << "\n=== PLANT NURSERY - DECORATOR PATTERN DEMO ===\n" << std::endl;
    
    // Create a plant
    Plant* rose = new Rose();  // Assuming Rose class exists
    rose->setPlantId(101);
    rose->setBasePrice(120.0);
    
    std::cout << "Original Plant:" << std::endl;
    rose->display();
    
    // ========== SCENARIO 1: Basic Plant ==========
    std::cout << "\n\n*** SCENARIO 1: Basic Plant (No Decorations) ***" << std::endl;
    PlantProduct* basic = new BasicPlant(rose);
    basic->display();
    
    // ========== SCENARIO 2: Plant with Decorative Pot ==========
    std::cout << "\n\n*** SCENARIO 2: Plant + Decorative Pot ***" << std::endl;
    PlantProduct* withPot = new DecorativePotDecorator(basic, "ceramic", "blue");
    withPot->display();
    
    // ========== SCENARIO 3: Plant + Pot + Gift Wrap ==========
    std::cout << "\n\n*** SCENARIO 3: Plant + Pot + Gift Wrap ***" << std::endl;
    PlantProduct* withPotAndWrap = new GiftWrappingDecorator(withPot, "elegant", "gold", true);
    withPotAndWrap->display();
    
    // ========== SCENARIO 4: Fully Decorated Gift ==========
    std::cout << "\n\n*** SCENARIO 4: Complete Gift Package ***" << std::endl;
    PlantProduct* completeGift = new GreetingCardDecorator(
        withPotAndWrap,
        "birthday",
        "Wishing you a blooming wonderful birthday!",
        "Sarah",
        "The Garden Team"
    );
    completeGift->display();
    
    std::cout << "\nPrice Breakdown:" << std::endl;
    std::cout << "Base Plant: R120.00" << std::endl;
    std::cout << "+ Ceramic Pot: R50.00" << std::endl;
    std::cout << "+ Elegant Wrap: R75.00" << std::endl;
    std::cout << "+ Birthday Card: R15.00" << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "Total: R" << std::fixed << std::setprecision(2)
              << completeGift->getPrice() << std::endl;
    
    // ========== SCENARIO 5: Different Combination ==========
    std::cout << "\n\n*** SCENARIO 5: Simple Gift (Wrap + Card Only) ***" << std::endl;
    PlantProduct* simpleGift = new GreetingCardDecorator(
        new GiftWrappingDecorator(basic, "classic", "red", true),
        "thank_you",
        "Thank you for your kindness!",
        "John",
        "The Smith Family"
    );
    simpleGift->display();
    
    // Cleanup
    delete completeGift;
    delete withPotAndWrap;
    delete withPot;
    delete simpleGift;
    delete basic;
    delete rose;
    
    std::cout << "\n=== DECORATOR PATTERN DEMO COMPLETE ===\n" << std::endl;
    
    return 0;
}