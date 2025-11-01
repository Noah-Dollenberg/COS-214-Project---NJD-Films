/**
 * @file FrequentWatering.h
 * @brief Header file for the FrequentWatering class
 * @author NJD Films
 * @date 2024
 */

#ifndef FREQUENTWATERING_H
#define FREQUENTWATERING_H
#include "PlantCareStrategy.h"

/**
 * @class FrequentWatering
 * @brief Concrete strategy for frequent plant watering
 * 
 * This class implements the PlantCareStrategy interface to provide
 * a frequent watering approach, suitable for plants that require
 * daily watering and consistently moist soil.
 */
class FrequentWatering : public PlantCareStrategy {
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~FrequentWatering() = default;
    
    /**
     * @brief Implements frequent watering care for plants
     * 
     * Provides daily watering to keep soil consistently moist.
     * This method overrides the base class implementation.
     */
    void careForPlant() override;
};

#endif // FREQUENTWATERING_H