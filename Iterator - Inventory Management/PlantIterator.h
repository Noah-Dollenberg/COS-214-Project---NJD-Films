/**
 * @file PlantIterator.h
 * @brief Abstract Iterator interface for traversing plant collections
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

// Forward declaration
class Plant;

/**
 * @class PlantIterator
 * @brief Abstract Iterator interface for the Iterator design pattern
 * 
 * PlantIterator defines the interface for traversing a collection of Plant objects
 * without exposing the underlying representation of the collection. This is the
 * Iterator role in the Iterator design pattern.
 * 
 * The pattern provides a uniform way to access elements of different aggregate
 * objects (like vectors, lists, or custom data structures) without needing to
 * know the specifics of how they're stored.
 * 
 * Concrete implementations (like InventoryIterator) provide the actual traversal
 * logic for specific collection types.
 * 
 * @note This is an abstract interface class - cannot be instantiated directly
 * @see PlantCollection, InventoryIterator, GreenhouseInventory
 * 
 * Example usage:
 * @code
 * PlantCollection* inventory = new GreenhouseInventory();
 * PlantIterator* it = inventory->createIterator();
 * 
 * for (it->first(); !it->isDone(); it->next()) {
 *     Plant* plant = it->currentItem();
 *     plant->display();
 * }
 * delete it;
 * @endcode
 */
class PlantIterator {
public:
    /**
     * @brief Virtual destructor for proper cleanup of derived classes
     * 
     * Ensures derived iterator classes are properly destroyed when deleted
     * through a base class pointer.
     */
    virtual ~PlantIterator() = default;
    
    /**
     * @brief Resets the iterator to the first element
     * 
     * Positions the iterator at the beginning of the collection, allowing
     * for traversal from the start. Must be called before beginning iteration.
     * 
     * @post Iterator points to the first element in the collection
     */
    virtual void first() = 0;
    
    /**
     * @brief Advances the iterator to the next element
     * 
     * Moves the iterator forward to the next plant in the collection.
     * Should be called after processing the current element.
     * 
     * @pre Iterator is not at the end of the collection
     * @post Iterator points to the next element, or is done if at the end
     */
    virtual void next() = 0;
    
    /**
     * @brief Checks if iteration is complete
     * @return true if there are no more elements to iterate, false otherwise
     * 
     * Tests whether the iterator has passed the last element in the collection.
     * Use this in loop conditions to determine when to stop iterating.
     */
    virtual bool isDone() const = 0;
    
    /**
     * @brief Gets the current plant in the iteration
     * @return Pointer to the current Plant object, or nullptr if done
     * 
     * Retrieves the plant at the current iterator position without
     * advancing the iterator. Returns nullptr if iteration is complete.
     * 
     * @warning Do not call when isDone() returns true
     */
    virtual Plant* currentItem() const = 0;
};

#endif // PLANTITERATOR_H
