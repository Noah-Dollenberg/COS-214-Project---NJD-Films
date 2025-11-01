/**
 * @file PlantCollection.h
 * @brief Abstract Aggregate interface for plant collections
 * @author Josh Reynolds
 * @date 2025
 */

#ifndef PLANTCOLLECTION_H
#define PLANTCOLLECTION_H

// Forward declarations
class PlantIterator;
class Plant;

/**
 * @class PlantCollection
 * @brief Abstract Aggregate interface for the Iterator design pattern
 * 
 * PlantCollection defines the interface for aggregate objects that can create
 * iterators to traverse their elements. This is the Aggregate role in the
 * Iterator design pattern.
 * 
 * The pattern separates the collection's interface from the traversal mechanism,
 * allowing different iteration strategies (forward, reverse, filtered, etc.)
 * without modifying the collection class itself.
 * 
 * Concrete implementations (like GreenhouseInventory) provide specific collection
 * storage and iterator creation logic.
 * 
 * @note This is an abstract interface class - cannot be instantiated directly
 * @see PlantIterator, GreenhouseInventory, InventoryIterator
 * 
 * Example usage:
 * @code
 * PlantCollection* collection = new GreenhouseInventory();
 * collection->addPlant(new Rose());
 * collection->addPlant(new Cactus());
 * 
 * PlantIterator* it = collection->createIterator();
 * for (it->first(); !it->isDone(); it->next()) {
 *     Plant* p = it->currentItem();
 *     std::cout << p->getName() << std::endl;
 * }
 * delete it;
 * @endcode
 */
class PlantCollection {
public:
    /**
     * @brief Virtual destructor for proper cleanup of derived classes
     * 
     * Ensures derived collection classes are properly destroyed when deleted
     * through a base class pointer.
     */
    virtual ~PlantCollection() = default;
    
    /**
     * @brief Factory method to create an iterator for this collection
     * @return Pointer to a new PlantIterator for traversing this collection
     * 
     * Creates and returns an iterator appropriate for traversing this specific
     * collection type. The caller is responsible for deleting the iterator.
     * 
     * @note Caller must delete the returned iterator to avoid memory leaks
     * @post Returns a valid iterator positioned at the beginning of the collection
     */
    virtual PlantIterator* createIterator() = 0;
    
    /**
     * @brief Adds a plant to the collection
     * @param plant Pointer to the Plant object to add
     * 
     * Inserts a plant into the collection. The specific insertion behavior
     * (position, ordering, etc.) depends on the concrete implementation.
     * 
     * @note The collection does not take ownership of the plant - caller manages lifetime
     * @warning Adding nullptr may cause undefined behavior
     */
    virtual void addPlant(Plant* plant) = 0;
    
    /**
     * @brief Removes a plant from the collection
     * @param plant Pointer to the Plant object to remove
     * 
     * Removes the specified plant from the collection if it exists.
     * Does nothing if the plant is not found.
     * 
     * @note Does not delete the plant object, only removes it from the collection
     */
    virtual void removePlant(Plant* plant) = 0;
    
    /**
     * @brief Checks if the collection is empty
     * @return true if the collection contains no plants, false otherwise
     * 
     * Tests whether the collection has any plants. Useful for validation
     * before iteration or other operations.
     */
    virtual bool isEmpty() const = 0;
};

#endif // PLANTCOLLECTION_H
