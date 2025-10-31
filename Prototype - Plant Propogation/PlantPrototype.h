/**
 * @file PlantPrototype.h
 * @brief Abstract base class for the Prototype design pattern for plant propagation
 * @author NJD Films
 */

#ifndef PLANTPROTOTYPE_H
#define PLANTPROTOTYPE_H

#include <string>

class Plant;

/**
 * @class PlantPrototype
 * @brief Abstract prototype class for cloning plants
 *
 * This class implements the Prototype design pattern, allowing plants to be
 * cloned/propagated without knowing their concrete types. This is useful for
 * creating new plants from existing specimens through vegetative propagation
 * (cuttings, division, etc.). Each concrete prototype knows how to clone itself.
 */
class PlantPrototype {
protected:
    Plant* plant;  ///< Pointer to the plant being prototyped

public:
    /**
     * @brief Default constructor
     */
    PlantPrototype();

    /**
     * @brief Copy constructor for cloning
     * @param other The PlantPrototype to copy from
     *
     * Creates a deep copy of the prototype including its plant data.
     */
    PlantPrototype(const PlantPrototype& other);

    /**
     * @brief Virtual destructor
     */
    virtual ~PlantPrototype();

    /**
     * @brief Clone this prototype (pure virtual)
     * @return Pointer to a new PlantPrototype that is a copy of this one
     *
     * Concrete subclasses must implement this to create clones of themselves.
     * This is the key method of the Prototype pattern.
     */
    virtual PlantPrototype* clone() = 0;

    /**
     * @brief Get the type/species of the plant
     * @return String containing the plant type
     */
    std::string getPlantType() const;

    /**
     * @brief Get the health level of the plant
     * @return Integer representing plant health (typically 0-100)
     */
    int getPlantHealth() const;

    /**
     * @brief Set the health level of the plant
     * @param h New health value to set
     */
    void setPlantHealth(int h);
};

#endif // PLANTPROTOTYPE_H