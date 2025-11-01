/**
 * @file InventoryIterator.h
 * @brief Concrete Iterator implementation for greenhouse inventory traversal
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef INVENTORYITERATOR_H
#define INVENTORYITERATOR_H
#include "PlantIterator.h"
#include <vector>
#include <cstddef>

// Forward declarations
class GreenhouseInventory;
class Plant;

/**
 * @class InventoryIterator
 * @brief Concrete Iterator for traversing GreenhouseInventory collections
 * 
 * InventoryIterator is a concrete implementation of the PlantIterator interface
 * that provides sequential access to plants stored in a GreenhouseInventory.
 * This is the ConcreteIterator role in the Iterator design pattern.
 * 
 * The iterator maintains its own copy of the plant collection at construction time,
 * providing a snapshot that remains valid even if the original inventory is modified
 * during iteration. This prevents issues with concurrent modification.
 * 
 * Key responsibilities:
 * - Track the current position in the iteration (currentIndex)
 * - Maintain a reference to the source inventory
 * - Store a local copy of plants for safe traversal
 * - Provide sequential access methods (first, next, isDone, currentItem)
 * 
 * @note This iterator provides forward-only traversal
 * @see PlantIterator, GreenhouseInventory, Plant
 * 
 * Example usage:
 * @code
 * GreenhouseInventory* inv = new GreenhouseInventory();
 * inv->addPlant(new Rose());
 * inv->addPlant(new Cactus());
 * 
 * InventoryIterator* it = new InventoryIterator(inv);
 * for (it->first(); !it->isDone(); it->next()) {
 *     Plant* plant = it->currentItem();
 *     std::cout << "Plant: " << plant->getName() << std::endl;
 * }
 * delete it;
 * @endcode
 */
class InventoryIterator : public PlantIterator {
private:
    /**
     * @brief Pointer to the GreenhouseInventory being iterated
     * 
     * Maintains a reference to the source inventory. Used primarily for
     * establishing the relationship, as the actual plant data is copied
     * to the plants vector.
     */
    GreenhouseInventory* inventory;
    
    /**
     * @brief Current position in the iteration
     * 
     * Zero-based index tracking which plant is currently being accessed.
     * Starts at 0 and increments with each next() call.
     */
    size_t currentIndex;
    
    /**
     * @brief Local copy of plants for safe iteration
     * 
     * Stores a snapshot of the plant collection at iterator creation time.
     * This copy ensures the iterator remains valid even if the original
     * inventory is modified during iteration, preventing concurrent
     * modification issues.
     */
    std::vector<Plant*> plants;

public:
    /**
     * @brief Constructs an InventoryIterator for a given inventory
     * @param inv Pointer to the GreenhouseInventory to iterate over
     * 
     * Creates an iterator and takes a snapshot of the inventory's plants
     * at construction time. The iterator will traverse this snapshot even
     * if the original inventory is modified.
     * 
     * @pre inv must not be nullptr
     * @post Iterator is ready to traverse the inventory's plants
     */
    InventoryIterator(GreenhouseInventory* inv);
    
    /**
     * @brief Virtual destructor for cleanup
     * 
     * Default destructor is sufficient as this class doesn't own
     * the Plant objects or the GreenhouseInventory.
     */
    virtual ~InventoryIterator() = default;
    
    /**
     * @brief Resets iterator to the first plant
     * 
     * Sets currentIndex to 0, positioning the iterator at the beginning
     * of the plant collection.
     * 
     * @post currentIndex == 0
     * @post Iterator points to the first plant (if collection is not empty)
     */
    void first() override;
    
    /**
     * @brief Advances iterator to the next plant
     * 
     * Increments currentIndex to move to the next plant in the collection.
     * If already at the end, this has no effect.
     * 
     * @pre Iterator should not be done (isDone() returns false)
     * @post currentIndex is incremented by 1
     */
    void next() override;
    
    /**
     * @brief Checks if iteration is complete
     * @return true if currentIndex has reached or exceeded the collection size
     * @return false if there are more plants to iterate
     * 
     * Determines whether all plants have been visited. Use this as a loop
     * condition to avoid accessing invalid indices.
     */
    bool isDone() const override;
    
    /**
     * @brief Gets the plant at the current position
     * @return Pointer to the current Plant, or nullptr if iteration is done
     * 
     * Retrieves the plant at currentIndex without advancing the iterator.
     * Returns nullptr if isDone() is true.
     * 
     * @pre isDone() should return false for valid results
     * @warning Calling when isDone() is true returns nullptr
     */
    Plant* currentItem() const override;
};

#endif // INVENTORYITERATOR_H
