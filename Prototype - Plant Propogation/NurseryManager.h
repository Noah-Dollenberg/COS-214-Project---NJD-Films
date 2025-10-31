/**
 * @file NurseryManager.h
 * @brief Manager class for the Prototype pattern that maintains a registry of plant prototypes
 * @author NJD Films
 */

#ifndef NURSERYMANAGER_H
#define NURSERYMANAGER_H
#include <vector>
#include <string>

class PlantPrototype;

/**
 * @class NurseryManager
 * @brief Manages a collection of plant prototypes for cloning operations
 *
 * This class acts as a prototype registry/manager in the Prototype design pattern.
 * It maintains a collection of plant prototypes (mother plants) that can be cloned
 * on demand. This simulates a real nursery where successful plant specimens are
 * kept as "mother plants" for propagation purposes.
 *
 * The manager allows you to:
 * - Register new prototypes (add successful plant specimens)
 * - Clone existing prototypes by type (propagate plants)
 * - Maintain a catalog of available plant types for propagation
 */
class NurseryManager {
private:
    std::vector<PlantPrototype*> prototypes;  ///< Collection of registered plant prototypes

public:
    /**
     * @brief Virtual destructor
     *
     * Cleans up all registered prototypes.
     */
    virtual ~NurseryManager() = default;

    /**
     * @brief Add a new prototype to the registry
     * @param proto Pointer to the PlantPrototype to register
     *
     * Registers a new plant prototype that can be cloned later.
     * This is like adding a new "mother plant" to the nursery's collection.
     */
    void addPrototype(PlantPrototype* proto);

    /**
     * @brief Clone a prototype by plant type
     * @param type String specifying the plant type to clone (e.g., "Rose", "Succulent")
     * @return Pointer to a new PlantPrototype that is a clone of the requested type,
     *         or nullptr if the type is not found
     *
     * Searches the prototype registry for the specified plant type and creates
     * a clone of it. This is the key operation of the Prototype pattern - creating
     * new objects by copying existing prototypes.
     */
    PlantPrototype* clonePrototype(const std::string& type);
};

#endif // NURSERYMANAGER_H