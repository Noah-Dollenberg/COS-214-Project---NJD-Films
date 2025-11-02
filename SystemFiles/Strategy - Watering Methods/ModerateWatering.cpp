/**
 * @file ModerateWatering.cpp
 * @brief Implementation of the ModerateWatering class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 * 
 * This file contains the implementation of the ModerateWatering strategy
 * which provides balanced care instructions for plants requiring moderate
 * watering schedules. This strategy is the most commonly used approach
 * for typical houseplants and garden varieties.
 * 
 * @par Implementation Notes:
 * The moderate watering strategy follows the "top inch rule" which is
 * a widely accepted horticultural practice for determining when to water
 * most plant species.
 */

#include "ModerateWatering.h"
#include <iostream>

/**
 * @brief Implements moderate watering care for plants
 * @details Provides balanced care instructions using the top inch rule
 * 
 * This method implements the Strategy pattern's concrete strategy
 * for moderate plant watering. It outputs care instructions that
 * follow the horticultural best practice of checking the top inch
 * of soil for dryness before watering.
 * 
 * The implementation provides optimal care for:
 * - Most common houseplants (pothos, philodendron, etc.)
 * - Garden perennials and annuals
 * - Tropical plants in indoor environments
 * - Plants with moderate water requirements
 * - General-purpose plant care scenarios
 * 
 * @par Algorithm:
 * 1. Check if top inch of soil is dry
 * 2. Water thoroughly when condition is met
 * 3. Maintain consistent moderate moisture levels
 * 
 * @pre None - method can be called at any time
 * @post Outputs watering instructions to standard output stream
 * @return void
 * @complexity O(1) - Constant time operation
 * @threadsafe This method is thread-safe as it only performs output operations
 * @exception None - No exceptions thrown
 * 
 * @see FrequentWatering::careForPlant() for high-moisture plants
 * @see MinimalWatering::careForPlant() for drought-tolerant plants
 * @see PlantCareContext::executeStrategy() for usage context
 * 
 * @todo Consider adding soil moisture level parameters in future versions
 * @bug None known
 */
void ModerateWatering::careForPlant() {
    std::cout << "Watering when top inch of soil is dry, maintaining moderate moisture\n";
}
