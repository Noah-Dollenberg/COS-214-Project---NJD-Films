/**
 * @file GiftWrappingDecorator.h
 * @brief Header file for the GiftWrappingDecorator concrete decorator class
 * @author NJD Films
 * @date 2024
 * @version 1.0
 */

#ifndef GIFTWRAPPINGDECORATOR_H
#define GIFTWRAPPINGDECORATOR_H

#include "PlantDecorator.h"
#include <string>

/**
 * @class GiftWrappingDecorator
 * @brief Concrete decorator that adds gift wrapping to plant products
 * @ingroup Decorator
 *
 * GiftWrappingDecorator is a ConcreteDecorator in the Decorator pattern that
 * enhances plant products by adding professional gift wrapping. This makes the
 * plant suitable as a gift with customizable wrapping styles, ribbon colors,
 * and optional decorative bows.
 *
 * The decorator supports multiple wrapping styles (classic, modern, festive,
 * elegant) and various ribbon colors, adding both visual appeal and appropriate
 * cost to the base product. It's commonly combined with decorative pots and
 * greeting cards for complete gift packages.
 *
 * @par Design Pattern Role:
 * - ConcreteDecorator: GiftWrappingDecorator (this class)
 * - Decorator: PlantDecorator
 * - Component: PlantProduct
 *
 * @par Available Wrapping Styles:
 * - "classic" - Traditional gift wrap (default)
 * - "modern" - Contemporary minimalist style
 * - "festive" - Holiday-themed wrapping
 * - "elegant" - Premium luxury wrapping
 *
 * @par Usage Example:
 * @code
 * PlantProduct* product = new BasicPlant(rose);
 * product = new DecorativePotDecorator(product);
 * product = new GiftWrappingDecorator(product, "elegant", "gold", true);
 * cout << "Gift-ready: " << product->getDescription() << endl;
 * @endcode
 *
 * @see PlantDecorator
 * @see PlantProduct
 * @see DecorativePotDecorator
 * @see GreetingCardDecorator
 */
class GiftWrappingDecorator : public PlantDecorator {
private:
    /** @brief Style of gift wrapping (classic, modern, festive, elegant) */
    std::string wrappingStyle;

    /** @brief Color of the decorative ribbon */
    std::string ribbonColor;

    /** @brief Whether to include a decorative bow */
    bool includeBow;

    /** @brief Price of gift wrapping service (R25 standard) */
    double wrappingPrice;

public:
    /**
     * @brief Default constructor
     * @post Creates decorator with classic style, red ribbon, and bow at R25
     */
    GiftWrappingDecorator();

    /**
     * @brief Constructor with customization parameters
     * @param product Pointer to the PlantProduct to wrap
     * @param style Wrapping style (classic, modern, festive, elegant)
     * @param ribbon Ribbon color (default: red)
     * @param bow Whether to include bow (default: true)
     * @pre product should be a valid PlantProduct pointer
     * @post Decorator wraps product with specified wrapping configuration
     */
    GiftWrappingDecorator(PlantProduct* product,
                          const std::string& style = "classic",
                          const std::string& ribbon = "red",
                          bool bow = true);

    /**
     * @brief Virtual destructor
     * @note Does not delete wrapped product
     */
    virtual ~GiftWrappingDecorator();

    /**
     * @brief Gets total price including gift wrapping
     * @return Base product price plus wrapping price (R25)
     */
    double getPrice() const override;

    /**
     * @brief Gets description including wrapping details
     * @return Product description with wrapping style, ribbon, and bow details
     */
    std::string getDescription() const override;

    /**
     * @brief Displays product with gift wrapping information
     * @post Product and wrapping information displayed to console
     */
    void display() const override;

    /**
     * @brief Gets the wrapping style
     * @return Current wrapping style
     */
    std::string getWrappingStyle() const;

    /**
     * @brief Sets the wrapping style
     * @param style New wrapping style
     * @post wrappingStyle is updated
     */
    void setWrappingStyle(const std::string& style);

    /**
     * @brief Gets the ribbon color
     * @return Current ribbon color
     */
    std::string getRibbonColor() const;

    /**
     * @brief Sets the ribbon color
     * @param color New ribbon color
     * @post ribbonColor is updated
     */
    void setRibbonColor(const std::string& color);

    /**
     * @brief Checks if bow is included
     * @return true if bow is included, false otherwise
     */
    bool hasBow() const;

    /**
     * @brief Sets whether to include bow
     * @param bow true to include bow, false otherwise
     * @post includeBow is updated
     */
    void setIncludeBow(bool bow);

    /**
     * @brief Gets the wrapping service price
     * @return Gift wrapping price (R25)
     * @note This is the added cost, not total product price
     */
    double getWrappingPrice() const;
};

#endif // GIFTWRAPPINGDECORATOR_H