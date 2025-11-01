/**
 * @file InventoryManager.h
 * @brief High-level manager class for greenhouse inventory operations
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H
#include <vector>

// Forward declarations
class PlantCollection;
class PlantIterator;
class GreenhouseComponent;
class Plant;

/**
 * @class InventoryManager
 * @brief Facade and manager for inventory operations using the Iterator pattern
 * 
 * InventoryManager serves as a high-level interface for managing greenhouse
 * inventory operations. It acts as a client of the Iterator pattern, demonstrating
 * how to use PlantCollection and PlantIterator to manage and traverse plant data.
 * 
 * This class provides:
 * - Simplified interface for inventory operations
 * - Integration between collections and greenhouse components
 * - Convenient methods for adding plants and displaying inventory
 * - Iterator creation and management
 * 
 * The manager demonstrates the Iterator pattern's value: it can work with any
 * PlantCollection implementation without knowing the internal storage details,
 * relying solely on the iterator interface for traversal.
 * 
 * @note This is a client class that uses the Iterator pattern
 * @see PlantCollection, PlantIterator, GreenhouseInventory
 * 
 * Example usage:
 * @code
 * InventoryManager* manager = new InventoryManager();
 * GreenhouseInventory* inventory = new GreenhouseInventory();
 * manager->setCollection(inventory);
 * 
 * manager->addPlant(new Rose());
 * manager->addPlant(new Cactus());
 * manager->displayInventory();  // Uses iterator internally
 * 
 * // Manual iteration
 * PlantIterator* it = manager->getIterator();
 * for (it->first(); !it->isDone(); it->next()) {
 *     Plant* p = it->currentItem();
 *     // Process plant
 * }
 * delete it;
 * @endcode
 */
class InventoryManager {
private:
    /**
     * @brief Pointer to the managed plant collection
     * 
     * Stores a reference to the PlantCollection (typically GreenhouseInventory)
     * that this manager operates on. The manager delegates storage operations
     * to this collection.
     * 
     * @note Manager does not own the collection - caller manages its lifetime
     */
    PlantCollection* collection;
    
    /**
     * @brief Vector of greenhouse components
     * 
     * Maintains references to GreenhouseComponent objects (like Greenhouse,
     * Section, Shelf) that may contain plants. Provides integration between
     * the inventory system and the greenhouse layout structure.
     */
    std::vector<GreenhouseComponent*> components;
    
public:
    /**
     * @brief Constructs an InventoryManager with no collection
     * 
     * Creates a manager with collection set to nullptr. Call setCollection()
     * before performing inventory operations.
     * 
     * @post collection == nullptr, components vector is empty
     */
    InventoryManager();
    
    /**
     * @brief Virtual destructor for cleanup
     * 
     * Cleans up the manager. Does not delete the collection or components
     * as they are owned by external code.
     */
    virtual ~InventoryManager();
    
    /**
     * @brief Sets the plant collection to manage
     * @param coll Pointer to a PlantCollection (typically GreenhouseInventory)
     * 
     * Assigns a collection for this manager to operate on. All subsequent
     * inventory operations will use this collection.
     * 
     * @note Manager does not take ownership - caller retains responsibility
     * @post collection points to coll
     */
    void setCollection(PlantCollection* coll);
    
    /**
     * @brief Creates an iterator for the managed collection
     * @return Pointer to a PlantIterator for traversing the collection
     * 
     * Factory method that delegates to the collection's createIterator().
     * Returns nullptr if no collection is set.
     * 
     * @note Caller must delete the returned iterator
     * @return Iterator for the collection, or nullptr if collection is not set
     * @warning Returns nullptr if setCollection() has not been called
     */
    PlantIterator* getIterator();
    
    /**
     * @brief Adds a plant to the managed collection
     * @param plant Pointer to the Plant to add
     * 
     * Convenience method that delegates to collection->addPlant(). Does
     * nothing if no collection is set.
     * 
     * @note Does nothing if collection is nullptr
     * @warning Ensure setCollection() has been called first
     */
    void addPlant(Plant* plant);
    
    /**
     * @brief Displays all plants in the inventory using iteration
     * 
     * Demonstrates the Iterator pattern by creating an iterator and
     * traversing all plants in the collection, displaying information
     * about each one. This method shows how to use the iterator interface
     * without knowing the collection's internal structure.
     * 
     * Typical output format shows plant type, name, and other details
     * for each plant in the inventory.
     * 
     * @note Does nothing if collection is nullptr or empty
     * @post Inventory contents are printed to standard output
     */
    void displayInventory();
};

#endif // INVENTORYMANAGER_H
