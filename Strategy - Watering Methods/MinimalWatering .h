/**
 * @file MinimalWatering .h
 * @brief Header file for the MinimalWatering class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 */

#ifndef MINIMALWATERING_H
#define MINIMALWATERING_H
#include "PlantCareStrategy.h"

/**
 * @class MinimalWatering
 * @brief Concrete strategy for minimal plant watering
 * @ingroup Strategy
 * 
 * This class implements the PlantCareStrategy interface to provide
 * a minimal watering approach. This strategy is designed for plants
 * that prefer dry conditions and require infrequent watering, such
 * as cacti and succulents.
 * 
 * The minimal watering strategy allows soil to dry completely between
 * watering sessions, preventing root rot and other moisture-related
 * plant diseases.
 * 
 * @see PlantCareStrategy
 * @see FrequentWatering
 * @see ModerateWatering
 */
class MinimalWatering : public PlantCareStrategy {
public:
    /**
     * @brief Virtual destructor
     * @details Ensures proper cleanup of derived class objects
     */
    virtual ~MinimalWatering() = default;
    
    /**
     * @brief Implements minimal watering care for plants
     * @details Provides sparse watering allowing soil to dry completely
     * 
     * This method implements the careForPlant interface to provide
     * minimal watering care. It outputs instructions for watering
     * sparingly and allowing complete soil drying between sessions.
     * 
     * @note This strategy is ideal for drought-tolerant plants
     * @warning Overwatering with this strategy may harm the plant
     * @override PlantCareStrategy::careForPlant()
     */
    void careForPlant() override;
};

#endif // MINIMALWATERING_H
