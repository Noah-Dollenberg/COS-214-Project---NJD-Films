/**
 * @file MinimalWatering.cpp
 * @brief Implementation of the MinimalWatering class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 * 
 * This file contains the implementation of the MinimalWatering strategy
 * which provides care instructions for plants requiring minimal water.
 */

#include "MinimalWatering .h"
#include <iostream>

/**
 * @brief Implements minimal watering care for plants
 * @details Provides care instructions for drought-tolerant plants
 * 
 * This method implements the Strategy pattern's concrete strategy
 * for minimal plant watering. It outputs care instructions that
 * emphasize sparse watering and complete soil drying between
 * watering sessions.
 * 
 * The implementation is particularly suitable for:
 * - Cacti and succulents
 * - Desert plants
 * - Plants adapted to arid conditions
 * - Any plant species that prefer dry soil conditions
 * 
 * @post Outputs watering instructions to standard output
 * @complexity O(1) - Constant time operation
 * @threadsafe This method is thread-safe as it only performs output
 * 
 * @see FrequentWatering::careForPlant()
 * @see ModerateWatering::careForPlant()
 */
void MinimalWatering::careForPlant() {
    std::cout << "Watering sparingly, allowing soil to dry completely between waterings\n";
}
