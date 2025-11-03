/**
 * @file ModerateWatering.h
 * @brief Header file for the ModerateWatering class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 */

#ifndef MODERATEWATERING_H
#define MODERATEWATERING_H
#include "PlantCareStrategy.h"

/**
 * @class ModerateWatering
 * @brief Concrete strategy for moderate plant watering
 * @ingroup Strategy
 * 
 * This class implements the PlantCareStrategy interface to provide
 * a balanced watering approach. This strategy maintains moderate
 * soil moisture by watering when the top inch of soil becomes dry,
 * making it suitable for most common houseplants and garden plants.
 * 
 * The moderate watering strategy strikes a balance between frequent
 * and minimal watering, preventing both overwatering and underwatering
 * issues that can harm plant health.
 * 
 * @par Usage Example:
 * @code
 * ModerateWatering* strategy = new ModerateWatering();
 * PlantCareContext context(strategy);
 * context.executeStrategy();
 * @endcode
 * 
 * @see PlantCareStrategy
 * @see FrequentWatering
 * @see MinimalWatering
 * @see PlantCareContext
 */
class ModerateWatering : public PlantCareStrategy {
public:
    /**
     * @brief Virtual destructor
     * @details Ensures proper cleanup of derived class objects
     * @note Default implementation is sufficient for this class
     */
    virtual ~ModerateWatering() = default;
    
    /**
     * @brief Implements moderate watering care for plants
     * @details Provides balanced watering maintaining moderate moisture
     * 
     * This method implements the careForPlant interface to provide
     * moderate watering care. It outputs instructions for watering
     * when the top inch of soil is dry, maintaining optimal moisture
     * levels for most plant species.
     * 
     * @pre Plant care context must be properly initialized
     * @post Watering instructions are output to standard stream
     * @note Suitable for most common houseplants and garden varieties
     * @warning Monitor individual plant needs as some may require adjustments
     * @override PlantCareStrategy::careForPlant()
     * @since Version 1.0
     */
    void careForPlant() override;
};

#endif // MODERATEWATERING_H