/**
 * @file SucculentCare.h
 * @brief Header file for the SucculentCare class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 */

#ifndef SUCCULENTCARE_H
#define SUCCULENTCARE_H
#include "PlantCareRoutine.h"

/**
 * @class SucculentCare
 * @brief Concrete implementation of plant care routine for succulents
 * @ingroup Template
 * 
 * This class provides a specialized implementation of the PlantCareRoutine
 * template method for succulent plants. It implements drought-tolerant
 * care techniques suitable for water-storing plants.
 * 
 * Succulents require specific care considerations:
 * - Soil must be completely dry before watering
 * - Infrequent but thorough watering with excellent drainage
 * - Minimal fertilization with diluted solutions
 * - Simple pruning of dead or damaged parts
 * - No additional care typically needed
 * 
 * @par Design Pattern Role:
 * This class serves as a ConcreteClass in the Template Method pattern:
 * - AbstractClass: PlantCareRoutine
 * - ConcreteClass: SucculentCare (this class)
 * - Implements drought-tolerant care operations
 * 
 * @par Succulent Care Specifications:
 * - Soil: Well-draining, allowed to dry completely
 * - Watering: Infrequent, deep watering with drainage
 * - Fertilizer: Diluted cactus fertilizer, monthly during growing season
 * - Pruning: Minimal, only dead or damaged material
 * - Special needs: Excellent drainage, avoid overwatering
 * 
 * @see PlantCareRoutine
 * @see RoseCare
 * @see TreeCare
 * 
 * @since Version 1.0
 */
class SucculentCare : public PlantCareRoutine {
public:
    /**
     * @brief Virtual destructor
     * @details Ensures proper cleanup of SucculentCare objects
     * 
     * Default implementation is sufficient as this class
     * does not manage any dynamic resources.
     */
    virtual ~SucculentCare() = default;
    
protected:
    /**
     * @brief Checks soil moisture for succulents
     * @details Implements drought-tolerant moisture assessment
     * 
     * Succulents require soil to be completely dry before watering
     * to prevent root rot. This method ensures proper dry conditions
     * are met before any watering occurs.
     * 
     * @pre Succulent plant and soil are accessible for checking
     * @post Soil dryness status is determined and reported
     * @note Succulents prefer complete soil drying between waterings
     * @override PlantCareRoutine::checkSoilMoisture()
     */
    void checkSoilMoisture() override;
    
    /**
     * @brief Waters succulents using drought-tolerant technique
     * @details Implements sparse watering with excellent drainage
     * 
     * Succulents should be watered thoroughly but infrequently,
     * ensuring excess water drains away quickly to prevent root rot.
     * The "soak and dry" method is preferred.
     * 
     * @pre Soil has been confirmed completely dry
     * @post Succulent receives thorough but infrequent watering
     * @note Drainage is critical to prevent waterlogging
     * @override PlantCareRoutine::water()
     */
    void water() override;
    
    /**
     * @brief Applies diluted fertilizer for succulents
     * @details Implements minimal fertilization program
     * 
     * Succulents require very little fertilization. Diluted cactus
     * fertilizer applied monthly during growing season provides
     * adequate nutrition without promoting excessive growth.
     * 
     * @pre Plant has been properly watered
     * @post Diluted fertilizer is applied for minimal nutrition
     * @note Over-fertilization can harm drought-adapted plants
     * @override PlantCareRoutine::fertilize()
     */
    void fertilize() override;
    
    /**
     * @brief Prunes succulents minimally
     * @details Implements simple pruning for succulents
     * 
     * Succulent pruning is minimal, involving only removal of
     * dead, damaged, or diseased parts. Healthy succulents
     * rarely require extensive pruning.
     * 
     * @pre Plant has been fertilized
     * @post Dead or damaged material is removed
     * @note Minimal pruning preserves natural succulent form
     * @override PlantCareRoutine::prune()
     */
    void prune() override;
    
    /**
     * @brief Additional care for succulents
     * @details No additional care typically needed
     * 
     * Succulents are low-maintenance plants that typically do not
     * require additional care beyond the standard routine. The base
     * class hook method is not overridden, using default empty implementation.
     * 
     * @note Uses default empty implementation from base class
     * @see PlantCareRoutine::additionalCare()
     */
    // additionalCare() uses default empty implementation
};

#endif