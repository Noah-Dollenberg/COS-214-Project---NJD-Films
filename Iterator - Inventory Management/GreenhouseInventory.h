/**
 * @file GreenhouseInventory.h
 * @brief Concrete Aggregate implementation for plant inventory management
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef GREENHOUSEINVENTORY_H
#define GREENHOUSEINVENTORY_H
#include "PlantCollection.h"
#include <vector>

// Forward declarations
class InventoryIterator;
class Plant;
class PlantIterator;

/**
 * @class GreenhouseInventory
 * @brief Concrete collection class for storing and managing greenhouse plants
 * 
 * GreenhouseInventory is a concrete implementation of the PlantCollection interface
 * that stores plants in a vector. This is the ConcreteAggregate role in the
 * Iterator design pattern.
 * 
 * The class provides:
 * - Storage for Plant objects in a dynamic vector
 * - Factory method to create InventoryIterator instances
 * - Standard collection operations (add, remove, isEmpty)
 * - Direct access methods for specific use cases
 * 
 * The iterator created by this class allows external code to traverse the plant
 * collection without exposing the internal vector representation, maintaining
 * proper encapsulation.
 * 
 * @note InventoryIterator is a friend class to allow safe access to the plants vector
 * @see PlantCollection, InventoryIterator, Plant
 * 
 * Example usage:
 * @code
 * GreenhouseInventory* inventory = new GreenhouseInventory();
 * inventory->addPlant(new Rose());
 * inventory->addPlant(new Cactus());
 * inventory->addPlant(new Lavender());
 * 
 * // Iterate through all plants
 * PlantIterator* it = inventory->createIterator();
 * for (it->first(); !it->isDone(); it->next()) {
 *     Plant* p = it->currentItem();
 *     p->display();
 * }
 * delete it;
 * 
 * std::cout << "Total plants: " << inventory->getCount() << std::endl;
 * @endcode
 */
class GreenhouseInventory : public PlantCollection {
private:
    /**
     * @brief Internal storage for plant pointers
     * 
     * Vector storing pointers to Plant objects in the inventory.
     * The vector allows dynamic sizing and efficient access.
     * 
     * @note The inventory does not own the Plant objects - caller manages their lifetime
     */
    std::vector<Plant*> plants;
    
    /**
     * @brief Friend declaration for InventoryIterator
     * 
     * Allows InventoryIterator to access the private plants vector for
     * creating a snapshot during iteration. This maintains encapsulation
     * while enabling the iterator pattern.
     */
    friend class InventoryIterator;

public:
    /**
     * @brief Constructs an empty GreenhouseInventory
     * 
     * Creates a new inventory with no plants. The internal vector is
     * initialized but empty.
     * 
     * @post Inventory is empty (isEmpty() returns true)
     */
    GreenhouseInventory();
    
    /**
     * @brief Virtual destructor for proper cleanup
     * 
     * Cleans up the inventory. Note that this does not delete the Plant
     * objects themselves - the caller is responsible for plant lifetime.
     */
    virtual ~GreenhouseInventory();
    
    /**
     * @brief Factory method to create an iterator for this inventory
     * @return Pointer to a new InventoryIterator for traversing plants
     * 
     * Creates and returns an InventoryIterator positioned at the beginning
     * of this collection. The iterator takes a snapshot of the current plants,
     * so modifications to the inventory won't affect ongoing iteration.
     * 
     * @note Caller must delete the returned iterator
     * @post Returns a valid iterator ready for traversal
     */
    PlantIterator* createIterator() override;
    
    /**
     * @brief Adds a plant to the inventory
     * @param plant Pointer to the Plant to add
     * 
     * Appends the plant to the end of the internal vector. Does not check
     * for duplicates - the same plant can be added multiple times.
     * 
     * @note The inventory does not take ownership - caller manages plant lifetime
     * @warning Adding nullptr may cause issues during iteration
     * @post getCount() is incremented by 1
     */
    void addPlant(Plant* plant) override;
    
    /**
     * @brief Removes a plant from the inventory
     * @param plant Pointer to the Plant to remove
     * 
     * Searches for the plant in the vector and removes the first occurrence
     * if found. If the plant is not in the inventory, nothing happens.
     * 
     * @note Does not delete the Plant object, only removes it from the collection
     * @post If plant was found, getCount() is decremented by 1
     */
    void removePlant(Plant* plant) override;
    
    /**
     * @brief Checks if the inventory is empty
     * @return true if the inventory contains no plants, false otherwise
     * 
     * Tests whether the plants vector is empty. Useful for validation
     * before iteration or other operations.
     */
    bool isEmpty() const override;
    
    /**
     * @brief Gets the number of plants in the inventory
     * @return The count of plants currently stored
     * 
     * Returns the size of the internal plants vector, indicating how
     * many plants are currently in the inventory.
     */
    size_t getCount() const;
    
    /**
     * @brief Direct access to a plant at a specific index
     * @param index Zero-based index of the plant to retrieve
     * @return Pointer to the Plant at the given index, or nullptr if invalid
     * 
     * Provides direct access to plants by index. This bypasses the iterator
     * and should be used sparingly when index-based access is specifically needed.
     * 
     * @warning Returns nullptr if index is out of bounds
     * @note Prefer using an iterator for sequential access
     */
    Plant* getPlantAt(size_t index) const;
};

#endif // GREENHOUSEINVENTORY_H
