/**
 * @file RoseCare.h
 * @brief Header file for the RoseCare class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 * @copyright Copyright (c) 2024 NJD Films. All rights reserved.
 */

#ifndef ROSECARE_H
#define ROSECARE_H
#include "PlantCareRoutine.h"

/**
 * @class RoseCare
 * @brief Concrete implementation of plant care routine for roses
 * @ingroup Template
 * 
 * This class provides a specialized implementation of the PlantCareRoutine
 * template method for rose plants. It implements all the required care
 * steps with rose-specific techniques and requirements.
 * 
 * Roses require specific care considerations:
 * - Consistent soil moisture without waterlogging
 * - Deep watering at the base to avoid leaf diseases
 * - Balanced fertilization for optimal blooming
 * - Regular pruning for shape and health
 * - Pest and disease monitoring
 * 
 * @par Design Pattern Role:
 * This class serves as a ConcreteClass in the Template Method pattern:
 * - AbstractClass: PlantCareRoutine
 * - ConcreteClass: RoseCare (this class)
 * - Implements all primitive operations for rose-specific care
 * 
 * @see PlantCareRoutine
 * @see SucculentCare
 * @see TreeCare
 * 
 * @since Version 1.0
 */
class RoseCare : public PlantCareRoutine {
public:
    /**
     * @brief Virtual destructor
     * @details Ensures proper cleanup of RoseCare objects
     */
    virtual ~RoseCare() = default;
    
protected:
    /**
     * @brief Checks soil moisture for roses
     * @details Implements rose-specific moisture assessment
     * 
     * @pre Rose plant and soil are accessible for checking
     * @post Soil moisture status is determined and reported
     * @override PlantCareRoutine::checkSoilMoisture()
     */
    void checkSoilMoisture() override;
    
    /**
     * @brief Waters roses using proper technique
     * @details Implements deep watering at plant base
     * 
     * @pre Soil moisture has been assessed
     * @post Rose receives appropriate deep watering
     * @override PlantCareRoutine::water()
     */
    void water() override;
    
    /**
     * @brief Applies balanced fertilizer for roses
     * @details Implements rose-specific fertilization program
     * 
     * @pre Plant has been properly watered
     * @post Appropriate fertilizer is applied for rose nutrition
     * @override PlantCareRoutine::fertilize()
     */
    void fertilize() override;
    
    /**
     * @brief Prunes roses for health and shape
     * @details Implements rose-specific pruning techniques
     * 
     * @pre Plant has been fertilized
     * @post Dead material removed and bush properly shaped
     * @override PlantCareRoutine::prune()
     */
    void prune() override;
    
    /**
     * @brief Performs additional rose-specific care
     * @details Implements pest and disease monitoring
     * 
     * @pre Standard care routine has been completed
     * @post Pest and disease inspection is performed
     * @override PlantCareRoutine::additionalCare()
     */
    void additionalCare() override;
};

#endif
