/**
 * @file GreenhouseSection.h
 * @brief Composite class representing a section within a greenhouse
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef GREENHOUSESECTION_H
#define GREENHOUSESECTION_H
#include "GreenhouseComponent.h"

/**
 * @class GreenhouseSection
 * @brief Composite node representing a logical section within a greenhouse
 * 
 * GreenhouseSection is a composite class that represents a distinct area or section
 * within a greenhouse facility. Each section can have a specific type (e.g., "Tropical",
 * "Succulents", "Flowering Plants") and contains multiple Shelf objects.
 * 
 * This class sits in the middle of the Composite pattern hierarchy:
 * - Parent: Greenhouse
 * - Children: Shelf objects
 * - Grandchildren: PlantLeaf objects (contained within Shelves)
 * 
 * Sections allow for logical organization of plants by type, climate requirements,
 * or any other categorization scheme.
 * 
 * @note This is a Composite node - it can contain Shelf children
 * @see GreenhouseComponent, Greenhouse, Shelf
 * 
 * Example usage:
 * @code
 * GreenhouseSection* tropicalSection = new GreenhouseSection("Tropical", "Tropical Zone");
 * Shelf* shelf1 = new Shelf(1, "Tropical Shelf 1");
 * tropicalSection->add(shelf1);
 * greenhouse->add(tropicalSection);
 * @endcode
 */
class GreenhouseSection : public GreenhouseComponent {
private:
    /**
     * @brief Type/category of this greenhouse section
     * 
     * Describes the type or purpose of the section (e.g., "Tropical Plants",
     * "Desert Plants", "Flowering Section"). This helps organize plants
     * by similar characteristics or care requirements.
     */
    std::string sectionType;
    
public:
    /**
     * @brief Constructs a GreenhouseSection with a type and name
     * @param type The type/category of this section (e.g., "Tropical", "Arid")
     * @param name Display name for this section (default: "Section")
     * 
     * Creates a new greenhouse section with a specified type. The type helps
     * categorize what kinds of plants belong in this section, while the name
     * provides a unique identifier.
     */
    GreenhouseSection(const std::string& type, const std::string& name = "Section");
    
    /**
     * @brief Virtual destructor for proper cleanup
     * 
     * Ensures proper cleanup of the section and its child components.
     * Child Shelf objects should be properly managed to avoid memory leaks.
     */
    virtual ~GreenhouseSection();
    
    /**
     * @brief Displays the section and all its shelves and plants hierarchically
     * @param depth The indentation depth for display (default: 0)
     * 
     * Recursively displays this section's information including its type,
     * and then displays all contained shelves and their plants with
     * appropriate indentation.
     */
    void display(int depth = 0) const override;
    
    /**
     * @brief Gets the section type
     * @return The type/category string of this section
     * 
     * Returns the section type which categorizes the kinds of plants
     * this section is designed to hold.
     */
    std::string getSectionType() const;
    
    /**
     * @brief Indicates that GreenhouseSection is a composite node
     * @return Always returns true as sections can contain Shelf children
     */
    bool isComposite() const override;
};

#endif // GREENHOUSESECTION_H
