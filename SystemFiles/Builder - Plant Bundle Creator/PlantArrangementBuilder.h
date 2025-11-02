/**
 * @file PlantArrangementBuilder.h
 * @brief Header file for the PlantArrangementBuilder abstract builder class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 */

#ifndef PLANTARRANGEMENTBUILDER_H
#define PLANTARRANGEMENTBUILDER_H

// Forward declarations
class PlantArrangement;
class Plant;

/**
 * @class PlantArrangementBuilder
 * @brief Abstract builder class for constructing plant arrangements
 * @ingroup Builder
 *
 * PlantArrangementBuilder serves as the Builder in the Builder design pattern.
 * It defines the interface for creating complex PlantArrangement objects through
 * a series of construction steps. Each step can be implemented differently by
 * concrete builders to create various types of arrangements.
 *
 * The builder abstracts the construction process, allowing the same construction
 * steps to produce different representations. Concrete builders (like
 * GiftArrangementBuilder and LandscapeArrangementBuilder) implement these steps
 * to create specific arrangement types.
 *
 * The builder maintains a reference to the arrangement being constructed and
 * provides it through getArrangement() when construction is complete.
 *
 * @par Design Pattern Role:
 * - Builder: PlantArrangementBuilder (this class)
 * - Product: PlantArrangement
 * - ConcreteBuilders: GiftArrangementBuilder, LandscapeArrangementBuilder
 * - Director: ArrangementDirector
 *
 * @par Construction Steps:
 * 1. reset() - Initialize new arrangement
 * 2. setBasicInfo() - Set name and description
 * 3. selectContainer() - Choose container type
 * 4. addPlants() - Add plants to arrangement
 * 5. addDecorations() - Add decorative elements
 * 6. calculatePrice() - Compute total price
 *
 * @par Usage Example:
 * @code
 * PlantArrangementBuilder* builder = new GiftArrangementBuilder();
 * builder->reset();
 * builder->setBasicInfo();
 * builder->selectContainer();
 * builder->addPlants();
 * builder->calculatePrice();
 * PlantArrangement* result = builder->getArrangement();
 * @endcode
 *
 * @see PlantArrangement
 * @see GiftArrangementBuilder
 * @see LandscapeArrangementBuilder
 * @see ArrangementDirector
 */
class PlantArrangementBuilder {
protected:
    /**
     * @brief Pointer to the arrangement being constructed
     * @details Maintains the product object during construction process
     */
    PlantArrangement* arrangement;

public:
    /**
     * @brief Default constructor
     * @post Builder initialized with nullptr arrangement
     */
    PlantArrangementBuilder();

    /**
     * @brief Virtual destructor
     * @note Does not delete arrangement - client code manages product lifetime
     */
    virtual ~PlantArrangementBuilder();

    /**
     * @brief Pure virtual method to reset builder state
     * @details Creates a fresh PlantArrangement object for new construction
     * @post New empty arrangement is ready for building
     * @warning Must be implemented by all concrete builders
     */
    virtual void reset() = 0;

    /**
     * @brief Pure virtual method to set arrangement name and description
     * @details Establishes the basic identity of the arrangement
     * @post Arrangement has name and description set
     * @warning Must be implemented by all concrete builders
     */
    virtual void setBasicInfo() = 0;

    /**
     * @brief Pure virtual method to select container type
     * @details Chooses appropriate container (basket, planter, vase, etc.)
     * @post Arrangement has container type specified
     * @warning Must be implemented by all concrete builders
     */
    virtual void selectContainer() = 0;

    /**
     * @brief Pure virtual method to add plants to arrangement
     * @details Selects and adds appropriate plants for this arrangement type
     * @post Plants are added to the arrangement
     * @warning Must be implemented by all concrete builders
     */
    virtual void addPlants() = 0;

    /**
     * @brief Pure virtual method to add decorative elements
     * @details Adds ribbons, cards, ornaments, or other decorations
     * @post Decorations are added if applicable
     * @warning Must be implemented by all concrete builders
     */
    virtual void addDecorations() = 0;

    /**
     * @brief Pure virtual method to calculate arrangement price
     * @details Computes total price based on plants, container, and decorations
     * @post Arrangement has final price calculated
     * @warning Must be implemented by all concrete builders
     */
    virtual void calculatePrice() = 0;

    /**
     * @brief Gets the constructed arrangement
     * @return Pointer to the completed PlantArrangement
     *
     * Returns the final product after all construction steps are complete.
     * The builder no longer owns this object after this call.
     *
     * @return Pointer to PlantArrangement, or nullptr if not yet constructed
     * @post Builder's arrangement pointer may be reset (implementation dependent)
     * @note Caller assumes ownership of returned arrangement
     */
    PlantArrangement* getArrangement();
};

#endif // PLANTARRANGEMENTBUILDER_H