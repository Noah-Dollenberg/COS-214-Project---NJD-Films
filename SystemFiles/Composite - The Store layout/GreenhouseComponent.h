/**
 * @file GreenhouseComponent.h
 * @brief Abstract base class for the Composite design pattern in greenhouse management
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef GREENHOUSECOMPONENT_H
#define GREENHOUSECOMPONENT_H
#include <vector>
#include <string>

// Forward declarations
class InventoryManager;
class Shelf;
class Greenhouse;
class GreenhouseSection;

/**
 * @class GreenhouseComponent
 * @brief Abstract Component class in the Composite pattern for greenhouse store layout
 * 
 * This class serves as the base component in a Composite design pattern implementation
 * for managing hierarchical greenhouse store structures. It defines the common interface
 * for both leaf objects (PlantLeaf) and composite objects (Greenhouse, GreenhouseSection, Shelf).
 * 
 * The pattern allows clients to treat individual plants and groups of plants uniformly,
 * enabling operations on entire greenhouse structures or individual components.
 * 
 * @note This is an abstract class and cannot be instantiated directly
 * @see Greenhouse, GreenhouseSection, Shelf, PlantLeaf
 */
class GreenhouseComponent {
protected:
    /**
     * @brief Container for child components in the composite structure
     * 
     * Stores pointers to child GreenhouseComponent objects. For leaf nodes,
     * this vector remains empty. For composite nodes (Greenhouse, Section, Shelf),
     * it contains their children.
     */
    std::vector<GreenhouseComponent*> children;
    
    /**
     * @brief Name identifier for this component
     * 
     * Stores a descriptive name for the component (e.g., "Section A", "Rose Shelf", "Rose Plant #1")
     */
    std::string name;
    
public:
    /**
     * @brief Constructs a GreenhouseComponent with an optional name
     * @param componentName The name for this component (default: empty string)
     */
    GreenhouseComponent(const std::string& componentName = "");
    
    /**
     * @brief Virtual destructor to ensure proper cleanup of derived classes
     * 
     * Ensures that derived class destructors are called when deleting through
     * a base class pointer, preventing memory leaks
     */
    virtual ~GreenhouseComponent();
    
    /**
     * @brief Pure virtual method to display component information
     * @param depth Indentation depth for hierarchical display (default: 0)
     * 
     * This method must be implemented by all concrete classes. It displays
     * the component's information with proper indentation to show hierarchy.
     */
    virtual void display(int depth = 0) const = 0;
    
    /**
     * @brief Adds a child component to this component
     * @param component Pointer to the GreenhouseComponent to add as a child
     * 
     * For leaf nodes, this operation may do nothing or throw an exception.
     * For composite nodes, it adds the component to the children vector.
     * 
     * @note The caller is responsible for ensuring the component pointer remains valid
     * @warning Adding null pointers or already-added components may cause undefined behavior
     */
    virtual void add(GreenhouseComponent* component);
    
    /**
     * @brief Removes a child component from this component
     * @param component Pointer to the GreenhouseComponent to remove
     * 
     * Searches the children vector and removes the specified component if found.
     * For leaf nodes, this operation typically does nothing.
     * 
     * @note Does not delete the component object, only removes it from the children list
     */
    virtual void remove(GreenhouseComponent* component);
    
    /**
     * @brief Retrieves a child component at the specified index
     * @param index Zero-based index of the child to retrieve
     * @return Pointer to the child component, or nullptr if index is invalid
     * 
     * @warning Accessing an out-of-bounds index may return nullptr or cause undefined behavior
     */
    virtual GreenhouseComponent* getChild(int index) const;
    
    /**
     * @brief Gets the number of children this component has
     * @return The count of child components (0 for leaf nodes)
     */
    virtual int getChildCount() const;
    
    /**
     * @brief Gets the name of this component
     * @return The component's name as a string
     */
    std::string getName() const;
    
    /**
     * @brief Checks if this component is a composite (has children)
     * @return true if this is a composite node, false if it's a leaf node
     * 
     * Default implementation returns false. Composite classes should override
     * this to return true.
     */
    virtual bool isComposite() const;
};

#endif // GREENHOUSECOMPONENT_H
