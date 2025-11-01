/**
 * @file TreeCare.h
 * @brief Header file for the TreeCare class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 */

#ifndef TREECARE_H
#define TREECARE_H
#include "PlantCareRoutine.h"

/**
 * @class TreeCare
 * @brief Concrete implementation of plant care routine for trees
 * @ingroup Template
 * 
 * This class provides a specialized implementation of the PlantCareRoutine
 * template method for tree plants. It implements large-scale care
 * techniques suitable for woody perennial plants with extensive
 * root systems and canopy structures.
 * 
 * Trees require specific care considerations:
 * - Deep soil moisture assessment at root level
 * - Deep watering at the drip line for root penetration
 * - Slow-release fertilization for sustained nutrition
 * - Structural pruning for health and safety
 * - Trunk inspection and mulching for protection
 * 
 * @par Design Pattern Role:
 * This class serves as a ConcreteClass in the Template Method pattern:
 * - AbstractClass: PlantCareRoutine
 * - ConcreteClass: TreeCare (this class)
 * - Implements large-scale woody plant care operations
 * 
 * @par Tree Care Specifications:
 * - Soil: Deep moisture assessment at root depth
 * - Watering: Deep watering at drip line, infrequent but thorough
 * - Fertilizer: Slow-release formulations for sustained feeding
 * - Pruning: Structural pruning for health, safety, and aesthetics
 * - Special needs: Trunk protection, mulching, canopy management
 * 
 * @see PlantCareRoutine
 * @see RoseCare
 * @see SucculentCare
 * 
 * @since Version 1.0
 */
class TreeCare : public PlantCareRoutine {
public:
    /**
     * @brief Virtual destructor
     * @details Ensures proper cleanup of TreeCare objects
     * 
     * Default implementation is sufficient as this class
     * does not manage any dynamic resources.
     */
    virtual ~TreeCare() = default;
    
protected:
    /**
     * @brief Checks soil moisture at tree root depth
     * @details Implements deep soil moisture assessment
     * 
     * Trees have extensive root systems that require moisture
     * assessment at deeper soil levels than smaller plants.
     * This method checks moisture at the root zone depth.
     * 
     * @pre Tree and surrounding soil are accessible for deep checking
     * @post Deep soil moisture status is determined and reported
     * @note Tree roots extend well beyond surface soil
     * @override PlantCareRoutine::checkSoilMoisture()
     */
    void checkSoilMoisture() override;
    
    /**
     * @brief Waters trees using deep drip line technique
     * @details Implements deep watering at tree drip line
     * 
     * Trees should be watered deeply at the drip line (edge of
     * canopy) to encourage deep root growth and provide adequate
     * water penetration to the entire root system.
     * 
     * @pre Soil moisture has been assessed at depth
     * @post Tree receives deep watering at drip line
     * @note Drip line watering promotes healthy root development
     * @override PlantCareRoutine::water()
     */
    void water() override;
    
    /**
     * @brief Applies slow-release fertilizer for trees
     * @details Implements sustained nutrition program
     * 
     * Trees benefit from slow-release fertilizers that provide
     * sustained nutrition over extended periods, supporting
     * long-term growth and health of woody structures.
     * 
     * @pre Tree has been properly watered
     * @post Slow-release fertilizer is applied for sustained nutrition
     * @note Long-term feeding supports woody growth patterns
     * @override PlantCareRoutine::fertilize()
     */
    void fertilize() override;
    
    /**
     * @brief Prunes trees for structure and health
     * @details Implements structural pruning techniques
     * 
     * Tree pruning involves removing dead branches, shaping
     * the canopy for optimal structure, and ensuring safety
     * by removing potentially hazardous limbs.
     * 
     * @pre Tree has been fertilized
     * @post Dead branches removed and canopy properly shaped
     * @note Structural pruning promotes tree health and safety
     * @override PlantCareRoutine::prune()
     */
    void prune() override;
    
    /**
     * @brief Performs additional tree-specific care
     * @details Implements trunk inspection and mulching
     * 
     * Trees require additional care including trunk inspection
     * for damage, disease, or pest issues, and mulching around
     * the base for moisture retention and root protection.
     * 
     * @pre Standard care routine has been completed
     * @post Trunk inspection and mulching are performed
     * @note Trunk health is critical for overall tree vitality
     * @override PlantCareRoutine::additionalCare()
     */
    void additionalCare() override;
};

#endif
