/**
 * @file RosePrototype.h
 * @brief Concrete prototype for cloning rose plants
 * @author NJD Films
 */

#ifndef ROSEPROTOTYPE_H
#define ROSEPROTOTYPE_H
#include "PlantPrototype.h"

/**
 * @class RosePrototype
 * @brief Concrete prototype implementation for rose propagation
 *
 * This class implements the Prototype pattern for rose plants. Roses can be
 * propagated through stem cuttings, and this prototype allows creating new
 * rose plants from existing specimens. The clone() method creates a new
 * RosePrototype with similar characteristics to the original.
 */
class RosePrototype : public PlantPrototype {
public:
    /**
     * @brief Default constructor
     *
     * Creates a new rose prototype with default characteristics.
     */
    RosePrototype();

    /**
     * @brief Copy constructor
     * @param other The RosePrototype to copy from
     *
     * Creates a deep copy of another rose prototype, used internally
     * during the cloning process.
     */
    RosePrototype(const RosePrototype& other);

    /**
     * @brief Virtual destructor
     */
    virtual ~RosePrototype();

    /**
     * @brief Clone this rose prototype
     * @return Pointer to a new RosePrototype that is a copy of this one
     *
     * Implements the Prototype pattern's clone operation. Creates a new
     * rose plant with the same characteristics as the original.
     * Useful for propagating successful rose varieties.
     */
    PlantPrototype* clone() override;
};

#endif // ROSEPROTOTYPE_H