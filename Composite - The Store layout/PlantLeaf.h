/**
 * @file PlantLeaf.h
 * @brief Leaf class in the Composite pattern representing individual plants
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef PLANTLEAF_H
#define PLANTLEAF_H
#include "GreenhouseComponent.h"

// Forward declaration
class Plant;

/**
 * @class PlantLeaf
 * @brief Leaf node in the Composite pattern representing an individual plant
 * 
 * PlantLeaf is the leaf class in the Composite pattern hierarchy. It represents
 * individual plant objects that cannot have children. Unlike composite nodes
 * (Greenhouse, GreenhouseSection, Shelf), a PlantLeaf wraps a single Plant object
 * and provides no-op implementations for child management operations.
 * 
 * This class demonstrates the key principle of the Composite pattern: treating
 * leaf and composite objects uniformly through the same interface, even though
 * leaf nodes don't support child operations.
 * 
 * @note This is a Leaf node - it cannot have children
 * @see GreenhouseComponent, Plant, Shelf
 * 
 * Example usage:
 * @code
 * Plant* rose = new Rose();
 * PlantLeaf* leaf = new PlantLeaf(rose, "Beautiful Red Rose");
 * shelf->add(leaf);  // Add to shelf
 * leaf->display();   // Display plant info
 * @endcode
 */
class PlantLeaf : public GreenhouseComponent {
private:
    /**
     * @brief Pointer to the actual Plant object this leaf represents
     * 
     * Stores the Plant that this leaf node wraps. The PlantLeaf acts as
     * an adapter between the Plant class and the Composite pattern hierarchy.
     */
    Plant* plant;
    
public:
    /**
     * @brief Constructs a PlantLeaf wrapping a Plant object
     * @param p Pointer to the Plant object to wrap
     * @param name Display name for this plant leaf (default: "Plant")
     * 
     * Creates a leaf node that represents an individual plant in the
     * greenhouse hierarchy. The Plant pointer must remain valid for
     * the lifetime of this PlantLeaf.
     * 
     * @warning The caller is responsible for the lifetime of the Plant object
     */
    PlantLeaf(Plant* p, const std::string& name = "Plant");
    
    /**
     * @brief Virtual destructor for proper cleanup
     * 
     * Cleans up the PlantLeaf. Note that this does not delete the wrapped
     * Plant object - the caller maintains ownership of the Plant.
     */
    virtual ~PlantLeaf();
    
    /**
     * @brief Displays this plant's information
     * @param depth The indentation depth for hierarchical display (default: 0)
     * 
     * Displays the plant's information with appropriate indentation to show
     * its position in the greenhouse hierarchy. Shows plant-specific details
     * such as type, state, and other properties.
     */
    void display(int depth = 0) const override;
    
    /**
     * @brief Gets the wrapped Plant object
     * @return Pointer to the Plant object this leaf represents
     */
    Plant* getPlant() const;
    
    /**
     * @brief No-op operation for leaf nodes - cannot add children
     * @param component Component to add (ignored)
     * 
     * Since PlantLeaf is a leaf node, it cannot have children. This method
     * is a no-op (does nothing) to maintain interface consistency.
     * 
     * @note This operation does nothing for leaf nodes
     */
    void add(GreenhouseComponent* component) override;
    
    /**
     * @brief No-op operation for leaf nodes - cannot remove children
     * @param component Component to remove (ignored)
     * 
     * Since PlantLeaf is a leaf node, it cannot have children. This method
     * is a no-op (does nothing) to maintain interface consistency.
     * 
     * @note This operation does nothing for leaf nodes
     */
    void remove(GreenhouseComponent* component) override;
    
    /**
     * @brief Always returns nullptr for leaf nodes
     * @param index Child index (ignored)
     * @return Always returns nullptr as leaf nodes have no children
     * 
     * Leaf nodes cannot have children, so this always returns nullptr
     * regardless of the index provided.
     */
    GreenhouseComponent* getChild(int index) const override;
    
    /**
     * @brief Indicates that PlantLeaf is a leaf node
     * @return Always returns false as PlantLeaf cannot contain children
     */
    bool isComposite() const override;
};

#endif // PLANTLEAF_H
