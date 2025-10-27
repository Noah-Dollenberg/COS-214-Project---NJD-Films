#include <iostream>
#include <vector>
#include "ArrangementDirector.h"
#include "GiftArrangementBuilder.h"
#include "LandscapeArrangementBuilder.h"
#include "PlantArrangement.h"
#include "../Plant - Abstract Base/Plant.h"

int TestingBuilder() {
    std::cout << "Plant Nursery - Builder Pattern Demo " << std::endl;
    
    // Create some mock plants (you'll use real Plant objects)
    std::vector<Plant*> availablePlants;
    // In real code: create Rose, Lavender, Succulent, etc.
    // For now, assuming Plant* pointers exist
    
    // Create director
    ArrangementDirector director;
    
    // ========== BUILD GIFT ARRANGEMENTS ==========
    std::cout << "\n\n********** GIFT ARRANGEMENTS **********\n" << std::endl;
    
    GiftArrangementBuilder giftBuilder;
    giftBuilder.setAvailablePlants(availablePlants);
    director.setBuilder(&giftBuilder);
    
    // Simple gift
    PlantArrangement* simpleGift = director.constructSimpleArrangement();
    if (simpleGift) {
        simpleGift->display();
        delete simpleGift;
    }
    
    // Deluxe gift
    PlantArrangement* deluxeGift = director.constructDeluxeArrangement();
    if (deluxeGift) {
        deluxeGift->display();
        delete deluxeGift;
    }
    
    // ========== BUILD LANDSCAPE ARRANGEMENTS ==========
    std::cout << "\n\n********** LANDSCAPE ARRANGEMENTS **********\n" << std::endl;
    
    LandscapeArrangementBuilder landscapeBuilder;
    landscapeBuilder.setAvailablePlants(availablePlants);
    landscapeBuilder.setTheme("tropical");
    director.setBuilder(&landscapeBuilder);
    
    // Simple landscape
    PlantArrangement* simpleLandscape = director.constructSimpleArrangement();
    if (simpleLandscape) {
        simpleLandscape->display();
        delete simpleLandscape;
    }
    
    // Deluxe landscape
    PlantArrangement* deluxeLandscape = director.constructDeluxeArrangement();
    if (deluxeLandscape) {
        deluxeLandscape->display();
        delete deluxeLandscape;
    }
    
    // Custom arrangement
    PlantArrangement* customArrangement = director.constructCustomArrangement(true);
    if (customArrangement) {
        customArrangement->display();
        delete customArrangement;
    }
    
    std::cout << "\n Builder Pattern Demo Complete " << std::endl;
    
    return 0;
}