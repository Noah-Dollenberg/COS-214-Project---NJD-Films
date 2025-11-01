/**
 * @file Greenhouse.h
 * @brief Top-level Composite class representing an entire greenhouse facility
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef GREENHOUSE_H
#define GREENHOUSE_H
#include "GreenhouseComponent.h"

// Forward declaration
class GreenhouseController;

/**
 * @class Greenhouse
 * @brief Represents the top-level composite in the greenhouse store hierarchy
 * 
 * The Greenhouse class is the root composite in the Composite pattern implementation.
 * It can contain multiple GreenhouseSection objects, each of which contains Shelves,
 * which in turn contain PlantLeaf objects. This creates a tree structure that allows
 * uniform treatment of individual plants and entire greenhouse sections.
 * 
 * The Greenhouse also manages a GreenhouseController for coordinating operations
 * across the entire facility.
 * 
 * @note This is a Composite node - it can have multiple children
 * @see GreenhouseComponent, GreenhouseSection, GreenhouseController
 */
class Greenhouse : public GreenhouseComponent {
private:
    /**
     * @brief Controller for managing greenhouse operations
     * 
     * Pointer to a GreenhouseController that coordinates watering, temperature,
     * and other environmental controls across the greenhouse
     */
    GreenhouseController* controller;
    
public:
    /**
     * @brief Constructs a Greenhouse with a given name
     * @param name The name of the greenhouse (default: "Main Greenhouse")
     */
    Greenhouse(const std::string& name = "Main Greenhouse");
    
    /**
     * @brief Virtual destructor for proper cleanup
     * 
     * Ensures proper cleanup of greenhouse resources and child components
     */
    virtual ~Greenhouse();
    
    /**
     * @brief Displays the greenhouse and all its children hierarchically
     * @param depth The indentation depth for display (default: 0)
     * 
     * Recursively displays the greenhouse name and all contained sections,
     * shelves, and plants with proper indentation to show the hierarchy
     */
    void display(int depth = 0) const override;
    
    /**
     * @brief Sets the greenhouse controller
     * @param ctrl Pointer to the GreenhouseController to manage this greenhouse
     * 
     * Assigns a controller to manage environmental systems and operations
     * 
     * @note The Greenhouse does not take ownership of the controller
     */
    void setController(GreenhouseController* ctrl);
    
    /**
     * @brief Gets the greenhouse controller
     * @return Pointer to the GreenhouseController, or nullptr if none set
     */
    GreenhouseController* getController() const;
    
    /**
     * @brief Indicates that Greenhouse is a composite node
     * @return Always returns true as Greenhouse can contain children
     */
    bool isComposite() const override;
};

#endif // GREENHOUSE_H
