/**
 * @file DecorativePotDecorator.h
 * @brief Header file for the DecorativePotDecorator concrete decorator class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 */

#ifndef DECORATIVEPOTDECORATOR_H
#define DECORATIVEPOTDECORATOR_H

#include "PlantDecorator.h"
#include <string>

/**
 * @class DecorativePotDecorator
 * @brief Concrete decorator that adds a decorative pot to plant products
 * @ingroup Decorator
 *
 * DecorativePotDecorator is a ConcreteDecorator in the Decorator pattern that
 * enhances plant products by adding a decorative pot. It allows customers to
 * upgrade from a basic plant to one presented in an attractive, high-quality pot.
 *
 * The decorator supports various pot types (ceramic, terracotta, modern, vintage)
 * and colors, each with its own pricing. It dynamically adds the pot's cost to
 * the base product price and includes pot details in the product description.
 *
 * This decorator can be combined with other decorators (like gift wrapping or
 * greeting cards) to create fully customized plant gift packages.
 *
 * @par Design Pattern Role:
 * - ConcreteDecorator: DecorativePotDecorator (this class)
 * - Decorator: PlantDecorator
 * - Component: PlantProduct
 * - ConcreteComponent: BasicPlant
 *
 * @par Available Pot Types:
 * - "ceramic" - Classic ceramic pot (default)
 * - "terracotta" - Traditional terracotta clay pot
 * - "modern" - Contemporary designer pot
 * - "vintage" - Rustic vintage-style pot
 *
 * @par Usage Example:
 * @code
 * PlantProduct* product = new BasicPlant(rose);
 * product = new DecorativePotDecorator(product, "modern", "black");
 * cout << product->getDescription() << endl;  // Includes pot details
 * cout << "Price: R" << product->getPrice() << endl;  // Base + pot price
 * @endcode
 *
 * @see PlantDecorator
 * @see PlantProduct
 * @see GiftWrappingDecorator
 * @see GreetingCardDecorator
 */
class DecorativePotDecorator : public PlantDecorator {
private:
    /**
     * @brief Type of decorative pot
     * @details Stores the pot style (ceramic, terracotta, modern, vintage)
     */
    std::string potType;

    /**
     * @brief Color of the decorative pot
     * @details Stores the pot color (white, black, red, blue, etc.)
     */
    std::string potColor;

    /**
     * @brief Price of the decorative pot
     * @details Cost added to base product price (R50 standard)
     */
    double potPrice;

public:
    /**
     * @brief Default constructor
     * @details Creates decorator with default pot settings
     * @post DecorativePotDecorator created with ceramic white pot at R50
     */
    DecorativePotDecorator();

    /**
     * @brief Constructor with customization parameters
     * @param product Pointer to the PlantProduct to decorate
     * @param type Type of pot (ceramic, terracotta, modern, vintage)
     * @param color Color of the pot (default: white)
     *
     * Creates a decorator that adds a decorative pot of specified type
     * and color to the product. The pot price is automatically set based
     * on the pot type.
     *
     * @pre product should be a valid PlantProduct pointer
     * @post Decorator wraps product with specified pot configuration
     * @note Standard pot price is R50, may vary by type
     */
    DecorativePotDecorator(PlantProduct* product,
                           const std::string& type = "ceramic",
                           const std::string& color = "white");

    /**
     * @brief Virtual destructor
     * @details Cleans up the decorator object
     * @note Does not delete wrapped product
     */
    virtual ~DecorativePotDecorator();

    /**
     * @brief Gets total price including pot
     * @return Base product price plus pot price
     *
     * Calculates the total price by adding the pot's cost to the
     * wrapped product's price.
     *
     * @return Total price in currency units (R)
     * @post No modification to decorator state
     * @note Returns wrappedProduct->getPrice() + potPrice
     */
    double getPrice() const override;

    /**
     * @brief Gets complete description including pot details
     * @return Product description with pot type and color appended
     *
     * Returns the wrapped product's description enhanced with pot
     * information (type and color).
     *
     * @return String describing product with pot details
     * @post No modification to decorator state
     * @note Format: wrapped description + " in [color] [type] pot"
     */
    std::string getDescription() const override;

    /**
     * @brief Displays product with pot information
     * @details Shows complete product details including pot
     *
     * Outputs the product information with pot specifications to
     * standard output in a user-friendly format.
     *
     * @post Product and pot information displayed to console
     */
    void display() const override;

    /**
     * @brief Gets the pot type
     * @return String representing the pot type
     *
     * @return Pot type (ceramic, terracotta, modern, vintage)
     * @post No modification to decorator state
     */
    std::string getPotType() const;

    /**
     * @brief Sets the pot type
     * @param type New pot type to set
     *
     * Changes the pot type. Price may be adjusted based on type.
     *
     * @pre type should be a valid pot type string
     * @post potType is updated to new value
     * @note May affect potPrice depending on implementation
     */
    void setPotType(const std::string& type);

    /**
     * @brief Gets the pot color
     * @return String representing the pot color
     *
     * @return Current pot color
     * @post No modification to decorator state
     */
    std::string getPotColor() const;

    /**
     * @brief Sets the pot color
     * @param color New pot color to set
     *
     * Changes the pot color. Does not typically affect price.
     *
     * @pre color should be a valid color string
     * @post potColor is updated to new value
     */
    void setPotColor(const std::string& color);

    /**
     * @brief Gets the pot's individual price
     * @return Price of just the pot (not including base product)
     *
     * Returns only the cost added by this decorator, useful for
     * showing itemized pricing.
     *
     * @return Pot price in currency units (R)
     * @post No modification to decorator state
     * @note This is the added cost, not total product price
     */
    double getPotPrice() const;
};

#endif // DECORATIVEPOTDECORATOR_H