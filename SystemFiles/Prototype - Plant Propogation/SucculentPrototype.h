/**
 * @file SucculentPrototype.h
 * @brief Concrete prototype for cloning succulent plants
 * @author NJD Films
 */

#ifndef SUCCULENTPROTOTYPE_H
#define SUCCULENTPROTOTYPE_H
#include "PlantPrototype.h"

/**
 * @class SucculentPrototype
 * @brief Concrete prototype implementation for succulent propagation
 *
 * This class implements the Prototype pattern for succulent plants. Succulents
 * are particularly easy to propagate through leaf or stem cuttings, making them
 * ideal candidates for the prototype pattern. The clone() method creates new
 * succulent plants from existing specimens, preserving their characteristics.
 */
class SucculentPrototype : public PlantPrototype {
public:
    /**
     * @brief Default constructor
     *
     * Creates a new succulent prototype with default characteristics.
     */
    SucculentPrototype();

    /**
     * @brief Copy constructor
     * @param other The SucculentPrototype to copy from
     *
     * Creates a deep copy of another succulent prototype, used internally
     * during the cloning process.
     */
    SucculentPrototype(const SucculentPrototype& other);

    /**
     * @brief Virtual destructor
     */
    virtual ~SucculentPrototype();

    /**
     * @brief Clone this succulent prototype
     * @return Pointer to a new SucculentPrototype that is a copy of this one
     *
     * Implements the Prototype pattern's clone operation. Creates a new
     * succulent plant with the same characteristics as the original.
     * Succulents clone easily through leaf or stem propagation.
     */
    PlantPrototype* clone() override;
};

#endif // SUCCULENTPROTOTYPE_H