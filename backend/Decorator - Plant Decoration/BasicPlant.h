/**
 * @file BasicPlant.h
 * @brief Header file for the BasicPlant concrete component class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 */

#ifndef BASICPLANT_H
#define BASICPLANT_H

#include "PlantProduct.h"

/**
 * @class BasicPlant
 * @brief Concrete component representing an undecorated plant product
 * @ingroup Decorator
 *
 * BasicPlant serves as the ConcreteComponent in the Decorator design pattern.
 * It represents a plain plant product without any additional decorations or
 * features. This is the base object to which decorators can be applied to
 * add features like decorative pots, gift wrapping, or greeting cards.
 *
 * BasicPlant provides the simplest implementation of PlantProduct, returning
 * the plant's base price and basic description without any embellishments.
 * It acts as the core component that decorators wrap around.
 *
 * @par Design Pattern Role:
 * - ConcreteComponent: BasicPlant (this class)
 * - Component: PlantProduct
 * - Decorator: PlantDecorator
 * - ConcreteDecorators: DecorativePotDecorator, GiftWrappingDecorator, etc.
 *
 * @par Usage Example:
 * @code
 * Plant* rose = new Rose();
 * PlantProduct* basicProduct = new BasicPlant(rose);
 * cout << "Price: R" << basicProduct->getPrice() << endl;  // Shows base plant price
 *
 * // Can be wrapped with decorators:
 * PlantProduct* decoratedProduct = new DecorativePotDecorator(basicProduct);
 * cout << "Price: R" << decoratedProduct->getPrice() << endl;  // Shows base + pot price
 * @endcode
 *
 * @see PlantProduct
 * @see PlantDecorator
 * @see DecorativePotDecorator
 * @see GiftWrappingDecorator
 * @see Plant
 */
class BasicPlant : public PlantProduct {
public:
    /**
     * @brief Default constructor
     * @details Creates a BasicPlant with no associated plant
     * @post BasicPlant object is created with nullptr plant
     */
    BasicPlant();

    /**
     * @brief Constructor with plant parameter
     * @param p Pointer to the Plant object to wrap
     *
     * Creates a BasicPlant wrapping the specified plant. This is the
     * typical way to create a basic plant product for sale.
     *
     * @pre p should be a valid Plant pointer
     * @post BasicPlant is initialized with the given plant
     */
    explicit BasicPlant(Plant* p);

    /**
     * @brief Virtual destructor
     * @details Cleans up the BasicPlant object
     *
     * @note Does not delete the wrapped plant - ownership remains with caller
     */
    virtual ~BasicPlant();

    /**
     * @brief Gets the price of the basic plant
     * @return The base price of the plant without any decorations
     *
     * Returns the unmodified base price of the wrapped plant. This is
     * the starting point for price calculations when decorators are applied.
     *
     * @return Base price in currency units (R)
     * @post No modification to plant or product state
     *
     * @note If plant is nullptr, returns 0.0
     */
    double getPrice() const override;

    /**
     * @brief Gets the description of the basic plant
     * @return Simple description of the plant without decoration details
     *
     * Returns a basic description of the plant including its species
     * and type, without any decorator embellishments.
     *
     * @return String describing the basic plant
     * @post No modification to plant or product state
     *
     * @note If plant is nullptr, returns generic description
     */
    std::string getDescription() const override;

    /**
     * @brief Displays the basic plant information
     * @details Outputs plant details to standard output
     *
     * Displays the plant's basic information including species, type,
     * and price in a user-friendly format. This is the undecorated
     * display that shows only the plant's core information.
     *
     * @post Plant information is displayed to standard output
     * @note Output format is plain, without decorator additions
     */
    void display() const override;
};

#endif // BASICPLANT_H