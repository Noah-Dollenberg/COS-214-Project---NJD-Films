/**
 * @file Shelf.h
 * @brief Composite class representing a shelf that holds plants
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef SHELF_H
#define SHELF_H
#include "GreenhouseComponent.h"

/**
 * @class Shelf
 * @brief Composite node representing a physical shelf holding plants
 * 
 * The Shelf class represents a physical shelf or display area within a greenhouse
 * section. Each shelf is numbered for identification and can contain multiple
 * PlantLeaf objects representing individual plants.
 * 
 * This class is a composite node in the hierarchy:
 * - Parent: GreenhouseSection
 * - Children: PlantLeaf objects (individual plants)
 * 
 * Shelves provide the physical organization layer in the greenhouse, allowing
 * multiple plants to be grouped together on the same display surface.
 * 
 * @note This is a Composite node - it can contain PlantLeaf children
 * @see GreenhouseComponent, GreenhouseSection, PlantLeaf
 * 
 * Example usage:
 * @code
 * Shelf* shelf = new Shelf(1, "Rose Shelf");
 * PlantLeaf* rose1 = new PlantLeaf(new Rose(), "Red Rose #1");
 * PlantLeaf* rose2 = new PlantLeaf(new Rose(), "Red Rose #2");
 * shelf->add(rose1);
 * shelf->add(rose2);
 * section->add(shelf);
 * shelf->display();  // Shows shelf and all plants on it
 * @endcode
 */
class Shelf : public GreenhouseComponent {
private:
    /**
     * @brief Numeric identifier for this shelf
     * 
     * Stores a unique number to identify this shelf within its section.
     * This allows for easy reference and organization (e.g., Shelf 1, Shelf 2).
     */
    int shelfNumber;
    
public:
    /**
     * @brief Constructs a Shelf with a number and name
     * @param number The numeric identifier for this shelf
     * @param name Display name for this shelf (default: "Shelf")
     * 
     * Creates a shelf with a specific number for identification. The number
     * helps organize multiple shelves within a section, while the name
     * provides additional context or description.
     */
    Shelf(int number, const std::string& name = "Shelf");
    
    /**
     * @brief Virtual destructor for proper cleanup
     * 
     * Ensures proper cleanup of the shelf and its child PlantLeaf objects.
     * Child components should be properly managed to avoid memory leaks.
     */
    virtual ~Shelf();
    
    /**
     * @brief Displays the shelf and all plants on it hierarchically
     * @param depth The indentation depth for display (default: 0)
     * 
     * Recursively displays this shelf's information (number and name),
     * then displays all PlantLeaf objects (plants) contained on this
     * shelf with appropriate indentation to show the hierarchy.
     */
    void display(int depth = 0) const override;
    
    /**
     * @brief Gets the shelf number
     * @return The numeric identifier of this shelf
     * 
     * Returns the shelf number which uniquely identifies this shelf
     * within its parent section.
     */
    int getShelfNumber() const;
    
    /**
     * @brief Indicates that Shelf is a composite node
     * @return Always returns true as shelves can contain PlantLeaf children
     */
    bool isComposite() const override;
};

#endif // SHELF_H
